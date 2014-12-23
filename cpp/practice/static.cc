#include <stdio.h>
int val(){
    printf("val called\n");
}
int sval(){
    static int _val=val();
    printf("s called\n");
    return _val;
}
int main(){
    printf("the value is %d\n",sval() );
    printf("the value is %d\n",sval() );
    printf("the value is %d\n",sval() );
}

