#include "matmul_v1.c"
#include "init.c"
#include <likwid-marker.h>

int main(){

    const int N = 1440;

    float * a = get_a(N);
    float * b = get_b(N);
    float * c = get_zero(N);
    float * d = get_zero(N);

    // We want to compute D = Bt A B
    // C = A B
    // D = Bt C

    LIKWID_MARKER_INIT;
    LIKWID_MARKER_REGISTER("MM");
    LIKWID_MARKER_REGISTER("MTM");

    LIKWID_MARKER_START("MM");
    matmat_mul(a,b,c,N);
    LIKWID_MARKER_STOP("MM");
    LIKWID_MARKER_START("MTM");
    mat_t_mat_mul(b,c,d,N);
    LIKWID_MARKER_STOP("MTM");

    free(d);free(c);free(b);free(a);
    LIKWID_MARKER_CLOSE;
    return 0;

}


