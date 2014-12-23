"""
File: model.py
Author: John Vishnefske
Email: jvishnefske@gmail.com
Github: jvishnefske
Description: data model for kaggle elf optimization
"""
import datetime
import math
globalStart = datetime.datetime(2014, 1, 1)
secondsPerDay = 3600*24
normalStartTime = 9*60
normalEndTime = 19*60
# productivity update equation is:
# p=p' * (1.02)^n * (0.9)^m
# where m, n are hours in real numbers.
pIncrease = 1.02
pDecrease = .9


def strToMinutes(dateString):
    """calculate relative time in days
    since 1/1/2014, and minutes since midnight"""
    # date input format 'YYYY MM DD HH MM'
    # output (minutesSinceMidnight,day)
    year, month, day, hour, minute = dateString.split()
    relativeDate = datetime.datetime(year, month, day, hour, minute) -\
        globalStart
    day = relativeDate.days
    minutesSinceMidnight = (relativeDate.seconds % secondsPerDay) / 60
    return (minutesSinceMidnight, day)


def minutesToStr(minutesSinceMidnight, day):
    seconds = minutesSinceMidnight * 60
    delta = datetime.timedelta(day, seconds)
    dtime = delta + globalStart
    return dtime.strftime("%Y %m %d %H %m")


class Elf(object):
    """
    track current scheduled tasks for elf instance, and
    calculate costs.
    """
    # taskDays[day] each element represent a list of tasks of the form:
    # [[startMinute,endMinute,efficiencyAfter],..]
    taskDays = []
    currentDay = 0

    def __init__(self, elfid, productivity):
        self.elfid = elfid
        self._productivity = productivity

    def calcProductivity(self):

        # assume tasks are sorted chronologically
        try:
            eff = self.taskDays[-1][-1][2]
            eff = eff[-1]
        except IndexError:
            eff = self.productivity
        return eff

    def freeTime(self, day):
        if day >= len(self.taskDays):
            return normalEndTime - self.startTime(day)

    def startTime(self, day):
        if day-1 >= len(self.taskDays):
            return normalStartTime
        endTimes = list(zip(*self.taskDays[day-1])[1])
        endTimes.sort()
        endTime = max(endTimes[-1], normalEndTime)
        startTime = normalStartTime + endTime - normalEndTime
        return startTime

    def lastTaskEndTime(self, day):
        return self.taskDays[day][-1][1]

    # efficiency is calculated, and stored with each task.
    def trySchedule(self, toy, day):
        lastTaskEndTime = self.lastTaskEndTime(day)
        if lastTaskEndTime >= normalEndTime:
            return False  # current tasks already extend to end of day
        overtime = self.calcOvertime(toy)
        productivity = self.calcProductivity()
        realOvertime = overtime / productivity
        normalHours = toy.duration - realOvertime
        newProductivity = productivity * pIncrease ** normalHours *\
            pDecrease ** realOvertime
        startTime = lastTaskEndTime + 1
        endTime = startTime + toy.duration
        self.taskDays[day].append([startTime, endTime, newProductivity])

    def calcPenalty(self, toy, day):
        """calc cost of placing toy on end of queue
        result of zero means the toy can be build without overtime.
        nonzero is the local coeficient of lost proficiency
        """
        # cost = 2*pDecrease**realOverTime

    def calcOvertime(self, toy):
        lastTaskEndTime = self.lastTaskEndTime(-1)
        currentDuration = math.ceil(self.efficiency()*toy.duration)
        currentEndTime = lastTaskEndTime + currentDuration
        overtime = currentEndTime - normalEndTime
        return max(0, overtime)


class Toy(object):
    def __init__(self, toyId, arrivalTime, duration):
        self.toyId = toyId
        self.arrivalMinute, self.arrivalDay = strToMinutes(arrivalTime)
        self.duration = duration
