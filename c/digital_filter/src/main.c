// digital_filter.c
// ramhdi, 27/06/2022
#include "filter.h"
#define ARRAY_LEN(x) sizeof(x)/sizeof(x[0])

int main() {
    // implement fibonacci sequence generator
    // y(n) = x(n) + y(n-1) + y(n-2)
    // where x(n) = unit impulse
    float b[] = {1};
    float a[] = {1, -1, -1};
    float input_buf[BUF_LEN]; // x(n)
    float output_buf[BUF_LEN]; // y(n)

    Filter ftr;
    filter_init(&ftr, b, ARRAY_LEN(b), a, ARRAY_LEN(a));
    filter_summary(&ftr);
    
    for (int n=0; n<BUF_LEN; n++) {
        printf("x[%d] = ", n);
        scanf("%f", &input_buf[n]);
        output_buf[n] = filter_filt(&ftr, input_buf[n]);
        printf("y[%d] = %f\n", n, output_buf[n]);
    }
    return 0;
}