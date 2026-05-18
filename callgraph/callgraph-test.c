#include <unistd.h>
#include <time.h>

#ifndef ACTIVITY
  #error "\
ACTIVITY should be defined either as 'sleep' or 'keep_cpu_busy'.\
Use the -DACTIVITY=sleep or -DACTIVITY=keep_cpu_busy \
in your compilation command." 
#endif

void keeping_cpu_busy(int seconds){

    int a = 0;
    struct timespec tstart,ttemp;

    clock_gettime(CLOCK_MONOTONIC,&tstart);
    while(1){
    for(int i =0; i < (1<<22); ++i) a++;
        clock_gettime(CLOCK_MONOTONIC,&ttemp);

        if((ttemp.tv_sec - tstart.tv_sec) > seconds) return;
    }
}


// Function names need to be at least   
void g_func(){
    ACTIVITY(2);
}

void f_func(){
    ACTIVITY(1);
    g_func();
}

void h_func(){
    ACTIVITY(3);
}

int main(){
    f_func();
    h_func();
}
