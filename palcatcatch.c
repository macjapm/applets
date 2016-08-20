#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#######################################################
//Command Line Applet Spin off of ProjectEuler Problem #4
//#######################################################
//Title : Palindrome Catcher
//Author : Mackenzie Park-McInnes
//Purpose : Find all Palindromes by multiplying all numbers within a given limit(incl.)
//			Outputs to textfile
//Compilation Instructions : gcc -o palcatch palcatch.c
//Usage : Argument 1 sets limit
//		: Argument 2 provides file to append, creates new if non-existent

int main(int argc, char *argv[]) {

	FILE *fd;
	int limit;

	if (argc != 3) {
		printf("Error: Expected 2 arguments, got %d", argc);
		return(-1);
	}

	limit = atoi(argv[1]);
	fd = fopen(argv[2], "a");

	char arr[7];
	char rev_arr[7];

	int i;
	int j;
	int id;
	int ir;

	int num;
	int len;
	int cmp;
	int lrg;

	fprintf(fd, "Palindromes Produced by Multiplying All Numbers up to %d(incl.)\n", limit);
	for(i=0;i<=limit;i++) {
		for(j=0; j<=limit;j++) {
			num = i*j;
			sprintf(arr, "%d", num);

			len = strlen(arr)-1;
			ir = len;
			for(id=0;id<=len;id++){
				rev_arr[ir] = arr[id];
				ir--;
			}

			cmp = strcmp(arr, rev_arr);
			if (cmp == 0 && num > lrg) {
				lrg = num;

			fprintf(fd, "%d\n", num);
			}
		}
	}
}
