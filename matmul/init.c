#include <stdlib.h>
#include <math.h>

float* matalloc(int N){
    return (float*) malloc(N*N*sizeof(float));
}

void setzero(float* m, int N){
    for(int i=0;i<N*N;++i) 
        m[i] = 0;
}

float* get_a(int N){
    float *a = matalloc(N); 
    for(int i=0;i<N*N;++i)
        a[i] = sinf((float) i);
    return a;
}

float* get_b(int N){
    float *b = matalloc(N); 
    for(int i=0;i<N*N;++i)
        b[i] = cosf((float) i);
    return b;
}

float* get_zero(int N){
    float *c = matalloc(N);
    setzero(c,N);
    return c;


}


