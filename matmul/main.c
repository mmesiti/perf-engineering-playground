#include "matmul_v1.c"
#include "init.c"


int main(){

    const int N = 1440;

    float * a = get_a(N);
    float * b = get_b(N);
    float * c = get_zero(N);
    float * d = get_zero(N);

    // We want to compute D = Bt A B
    // C = A B
    // D = Bt C
    matmat_mul(a,b,c,N);
    mat_t_mat_mul(b,c,d,N);

    free(d);free(c);free(b);free(a);
    return 0;

}


