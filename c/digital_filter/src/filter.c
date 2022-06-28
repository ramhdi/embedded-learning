#include "filter.h"

void filter_init(Filter* filter, float* _num, unsigned char _num_len, float* _den, unsigned char _den_len) {
    filter->num_len = _num_len;
    filter->den_len = _den_len;

    for (int i=0; i<filter->num_len; i++) {
        filter->num[i] = _num[i];
        filter->num_buf[i] = 0;
    }

    for (int i=0; i<filter->den_len; i++) {
        filter->den[i] = _den[i];
        filter->den_buf[i] = 0;
    }
}

void filter_summary(Filter* filter) {
    printf("%d\n", filter->num_len);
    for (int i=0; i<filter->num_len; i++) {
        printf("%lf ", filter->num[i]);
    }
    printf("\n");

    printf("%d\n", filter->den_len);
    for (int i=0; i<filter->den_len; i++) {
        printf("%lf ", filter->den[i]);
    }
    printf("\n");
}

float filter_filt(Filter* filter, float input) {
    float output = 0;

    // push input to filter bufer
    for (int k=filter->num_len-1; k>=0; k--) {
        if (k==0) {
            filter->num_buf[k] = input;
        } else {
            filter->num_buf[k] = filter->num_buf[k-1]; // push buffer elements
        }
        
        // calculate output
        output += filter->num_buf[k]*filter->num[k];
    }

    for (int k=filter->den_len-1; k>=0; k--) {
        if (k==0) {
            output /= filter->den[k]; // divide by a_0
            filter->den_buf[k] = output;
        } else {
            filter->den_buf[k] = filter->den_buf[k-1]; // push buffer elements
            output -= filter->den_buf[k]*filter->den[k]; // calculate output
        }
    }

    return output;
}