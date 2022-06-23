// realtime_iir.c
// ramhdi, 23/06/2022
#include <stdio.h>
#include <math.h>
#define FILTER_LEN_B 2 // numerator
#define FILTER_LEN_A 3 // denominator
#define BUF_LEN 100

int main() {
    // implement digital oscillator with digital frequency = 0.25*pi
    // y(n) = cos(0.25*pi*n)
    double filter_b[FILTER_LEN_B] = {1, -cos(0.25*M_PI)};
    double filter_a[FILTER_LEN_A] = {1, -2*cos(0.25*M_PI), 1};
    double filter_b_buf[FILTER_LEN_B] = {0,0};
    double filter_a_buf[FILTER_LEN_A] = {0,0,0};
    double input_buf[BUF_LEN]; // x(n)
    double output_buf[BUF_LEN]; // y(n)

    for (int i=0; i<BUF_LEN; i++) {
        input_buf[i]=0;
        output_buf[i]=0;
    }

    int add = 0;
    
    for (int n=0; n<BUF_LEN; n++) {
        printf("x[%d] = ", n);
        scanf("%lf", &input_buf[n]);

        // push input to filter bufer
        for (int k=FILTER_LEN_B-1; k>=0; k--) {
            if (k==0) {
                filter_b_buf[k] = input_buf[n];
            } else {
                filter_b_buf[k] = filter_b_buf[k-1]; // push buffer elements
            }
            
            // calculate output
            output_buf[n] += filter_b_buf[k]*filter_b[k];
        }

        for (int k=FILTER_LEN_A-1; k>=0; k--) {
            if (k==0) {
                output_buf[n] /= filter_a[k]; // divide by a_0
                filter_a_buf[k] = output_buf[n];
            } else {
                filter_a_buf[k] = filter_a_buf[k-1]; // push buffer elements
                output_buf[n] -= filter_a_buf[k]*filter_a[k]; // calculate output
            }
        }
        
        printf("y[%d] = %lf\n", n, output_buf[n]);
    }
    return 0;
}