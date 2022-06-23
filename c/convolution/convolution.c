// convolution.c
// ramhdi, 22/06/2022
#include <stdio.h>
#define FILTER_LEN 4
#define INPUT_LEN 10
#define OUTPUT_LEN INPUT_LEN + FILTER_LEN - 1

int main() {
    int filter[FILTER_LEN] = {1,1,1,1};
    int input[INPUT_LEN] = {1,1,1,1,1,1,1,1,1,1};
    int output[OUTPUT_LEN];
    int add = 0;
    
    for (int i=0; i<OUTPUT_LEN; i++) {
        output[i] = 0;
        for (int j=0; j<FILTER_LEN; j++) {
            if (i>=j && i<j+INPUT_LEN) {
                add = filter[j]*input[i-j];
                output[i] += add;
                printf("(i=%d,j=%d) add = %d\n",i,j,add);
            }
        }
        
    }

    ///*
    for (int i=0; i<OUTPUT_LEN; i++) {
        printf("%d\n", output[i]);
    }
    //*/
    return 0;
}