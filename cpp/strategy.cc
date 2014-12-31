/*
 * Strategy.cc
 * the plan is:
 * 1.choose an elf that has a gap, space after, or empty day. space after, 
 * and empty day should be topologically similar, except for 
 *
 * for gap:
 * determine cost function based on length of block which is allowed to fill given 
 * space.  Choose an iterator based on the gap, and potential pieces.
 * note: even though a gap may be targeted, the cost function may be based on 
 * assigning a given job to a given elf.  a cpp function could be utilized by 
 * inputing a queue, and assigning a heuristic to the queue.
 * 
 * The end goal of the huristic is what is the rate we are approaching the end goal. 
 * In other words given the current elf state what is the estimated end time 
 * assuming current progress. estimation based on efficiency at end of day minus 
 * average time gaps.
 *
 * There are certain some cases which produce the same finishing rate, however one may
 * be preferable due to using up larger pieces first. Consider where two cases both 
 * result in overtime, but one is able to schedule a longer job. While neither is 
 * inefficient, scheduling the longer task would be preferrable since the shorter is 
 * more likely to fit in another time slot.
 *
 * ideally each elf would reach 4.0
 *
 * not only is there a JobQueue
 *
 * also note that if there are no tasks to schedule, then gaps are unavoidable, and 
 * search time should not be wasted.
 *
 */
#include <list>
struct JobQueue{
    int elfId;
    std::list<int> toyId;
};

