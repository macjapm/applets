#include <stdio.h>
#include <stdlib.h>

//#######################################################
//Command Line Applet Spin off of ProjectEuler Problem #1
//#######################################################
//Title : Multiple Finder
//Author : Mackenzie Park-McInnes
//Purpose : Finds all multiples of a number up to a specified range(Inclusive),
//			Optionally prints sum of these values
//Date : 2016/08/04
//Compilation Instructions: gcc -o multfind multfind.c

//Usage : Argument 1 sets multiple value
//		  Argument 2 sets range value
//		  Argument 3 sets SUM option, SUM=1 outputs sum of all multiples, else
//									  SUM=0 NOSUM
//		  Argument 4 defines file name to write to 


int find(int i, int mult, int range, int sum, int SUM, int FILEOUT, FILE *fd);

int main(int argc, char *argv[]) {
	
	int SUM;
	int FILEOUT;

	int sum = 0;
	int i = 0;
	int mult;
	int range;

	FILE *fd;


	if (argc > 5) {
		printf("Error: Expected 3-4 Arguments, Got %d", argc-1);
		return(-1);
	}

	if (argc == 5) {
		FILEOUT = 1;
	}

	if (FILEOUT == 1) {
		fd = fopen(argv[4], "a");
	}
	

	if (*argv[3] == '1') {
		SUM = 1;
	} else if (*argv[3] == '0') {
		SUM = 0;
	}

	mult = atoi(argv[1]);
	range = atoi(argv[2]);

	find(i, mult, range, sum, SUM, FILEOUT, fd);

	return(0);
}

int find(int i, int mult, int range, int sum, int SUM, int FILEOUT, FILE *fd) {
	for(i=1; i <= range; i++) {
		if (i % mult == 0) {
			if (FILEOUT == 1) {
			fprintf(fd, "%d is a multiple of %d\n", i, mult);
			} else {
				printf("%d is a multiple of %d\n", i, mult);
			}
			sum += i;
		}
	}
	if (FILEOUT == 1 & SUM == 1) {
	fprintf(fd, "Summing all mutliples of %d in range 1 to %d inclusive, yields %d\n", mult, range, sum);
	} else {
		if (SUM == 1) {
			printf("Summing all mutliples of %d in range 1 to %d inclusive, yields %d\n", mult, range, sum);
		}
	}
	return(0);
}
