#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main2()
{
    int i;
    float p1[4] = { 0.2,0.4,0.5,0.9 }, p2[4] = { 0.1,0.3,0.5,0.7 }, q[4] = { 0.3,0.5,0.7,0.9 }, I_01, I_10, I_00, I_11, I, H;
    for (i = 0; i < 4; i++)
    {
        printf("p1=%f  p2=%f  q=%f \n", p1[i], p2[i], q[i]);

        I_00 = log2((1 - p1[i]) / ((1 - p1[i]) * q[i] + p2[i] * (1 - q[i])));
        I_01 = log2((p1[i]) / (p1[i] * q[i] + (1 - p2[i]) * (1 - q[i])));
        I_10 = log2(p2[i] / ((1 - p1[i]) * q[i] + p2[i] * (1 - q[i])));
        I_11 = log2((1 - p2[i]) / (p2[i] * q[i] + (1 - p2[i]) * (1 - q[i])));
        printf("\nMutual information is I_01 = % f, I_10 = % f, I_00 = % f, I_11 = % f", I_01, I_10, I_00, I_11);

        //Average Mutual information
        I = (double)(1 - p1[i]) * q[i] * I_00 + p1[i] * q[i] * I_01 + p2[i] * (1 - q[i]) * I_10 + (1 - p2[i]) * (1 - q[i]) * I_11;
        printf("\nAverage Mutual Information:%f\n", I);


        //conditional entropy
        H = -1 * ((1 - p1[i])*q[i] * log2(1 - p1[i]) + p1[i] * q[i] * log2(p1[i]) + p2[i]*(1 - q[i])*log2(p2[i]) + (1 - p2[i])*(1 - q[i]) * log2(1 - p2[i]));
        printf("Conditional entropy is % f\n", H);
        printf("\n\n");
    }
    return 0;
}

