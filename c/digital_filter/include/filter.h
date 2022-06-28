#ifndef _filter_h_
#define _filter_h_

#include <stdio.h>
#define BUF_LEN 256

typedef struct {
    float num[BUF_LEN];
    float den[BUF_LEN];
    float num_buf[BUF_LEN];
    float den_buf[BUF_LEN];
    unsigned char num_len;
    unsigned char den_len;
} Filter;

void filter_init(Filter* filter, float* _num, unsigned char _num_len, float* _den, unsigned char _den_len);

void filter_summary(Filter* filter);

float filter_filt(Filter* filter, float input);

#endif