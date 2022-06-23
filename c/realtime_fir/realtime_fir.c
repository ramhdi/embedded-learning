// convolution.c
// ramhdi, 22/06/2022
#include <stdio.h>
#define FILTER_LEN 2
#define BUF_LEN 100

int main() {
    double filter[FILTER_LEN] = {0.5, 0.5}; // simple moving average
    double filter_buf[FILTER_LEN] = {0,0};
    double input_buf[BUF_LEN];
    double output_buf[BUF_LEN];

    for (int i=0; i<BUF_LEN; i++) {
        input_buf[i]=0;
        output_buf[i]=0;
    }

    int add = 0;
    
    for (int n=0; n<BUF_LEN; n++) {
        printf("x[%d] = ", n);
        scanf("%lf", &input_buf[n]);

        // push input to filter bufer
        for (int k=FILTER_LEN-1; k>=0; k--) {
            if (k==0) filter_buf[k] = input_buf[n];
            else filter_buf[k] = filter_buf[k-1];
            
            // calculate output
            output_buf[n] += filter_buf[k]*filter[k];
        }
        
        printf("y[%d] = %lf\n", n, output_buf[n]);
    }
    return 0;
}