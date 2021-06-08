#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>


int main() {


	FILE* fp;
	int c;
	int n = 0;
	int array[128];
	int x, i = 0;
	double p, I, H;
	double SI[128];

	for (i = 0; i < 128; i++) {
		array[i] = 0;
		SI[i] = 0;
	}

	fp = fopen("notes.txt", "r");
	if (fp == NULL) {

		printf("ERROR in obtaining file!");
		return -1;
	}
	do {
		c = fgetc(fp);

		if (feof(fp)) {
			break;

		}
		//printf("%d \t", c);
		x = c;
		array[x]++;
		n++;
	} while (1);


	
	fclose(fp);

	printf("Total no of characters are  %d\n", n);
	/*for(i=0; i < 128; i++) {

		printf("%c occurs %d times\n", i,array[i]);

	}*/

	H = 0;
	
	for (i = 32; i < 128; i++) {

		if (array[i] != 0) {

			

			p = (double)array[i] / n;

			I = (-log(p));
			I = I / (0.693);
			SI[i] = I;
			H += (p * I);


			printf("The self information of the %c is %lf \n",i , SI[i]);


		}
	}
	printf("The entropy of the information source is %lf \n\n", H);

	printf("*******************************************************QUESTION 3 *************************************************************************\n");
	
	main2();

	return 0;

	
	

}