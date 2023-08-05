#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CYCLE_ARR for (int i = 0; i < a->arrSize; i++)

typedef struct Array {
	int *nArr;
	int arrSize;
} arr_t;


void gint(int *num);
int init_arr(arr_t *a);
void parr(arr_t *a);
void swap(int *e1, int *e2);
void permute(arr_t *a, int arrs);
long long factorial(int *arrSize);
int scan_argv(char **argV, int *arrSize);

int main(int argC, char *argV[]) {
	arr_t a;

	if (argV[1] != NULL) {
		if (scan_argv(argV, &a.arrSize) == 1) {
			;
		}
	}

	else {
		puts("how many elements?");
		gint(&a.arrSize);
	}

	if (!init_arr(&a)) {
		fprintf(stderr, "array init error\n");
		free(a.nArr);
		return 1;
	}

	permute(&a, a.arrSize);
	printf("there are %llu permutations for a %d element array.", factorial(&a.arrSize), a.arrSize);
	free(a.nArr);
}

void gint(int *num) {
	char *temp = (char *)malloc(128);
	fgets(temp, 128, stdin);
	if (strlen(temp) > 1) {
		if (!sscanf(temp, "%d", num) || temp[0] == ' ') {
			puts("try again:");
			free(temp);
			gint(num);
		}
		else {
			free(temp);
		}

	}
	else {
		puts("try again:");
		free(temp);
		gint(num); 
	}
}

int init_arr(arr_t *a) {
	a->nArr = malloc(a->arrSize * sizeof(*a->nArr));

	CYCLE_ARR {
        a->nArr[i] = i + 1;
    }

	CYCLE_ARR {
		if ((a->nArr[i] == '\0') && i <a->arrSize) {
			return 0;
		}
	}
	return 1;
}

void parr(arr_t *a) {
	CYCLE_ARR {
		printf("%d ", a->nArr[i]);
	}
	puts(" ");
}

void swap (int *e1, int *e2) {
	int temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

void permute(arr_t *a, int arrs) {
	if (arrs == 1) {
		parr(a);	
		return;	
	}
	for (int i = 0; i < arrs; i++) {
		permute(a, arrs - 1);
		
		if (arrs % 2 == 1) {
			swap(&a->nArr[0], &a->nArr[arrs - 1]);
		}	
		else {
			swap(&a->nArr[i], &a->nArr[arrs - 1]);
		}
	}
}

long long factorial(int *arrSize) {
	long long res = 1;
	for (int i = *arrSize; i > 1; i--) {
		res *= i;
	}
	return res;
}

int scan_argv(char **argV, int *arrSize) {
	int res = sscanf(argV[1], "%d", arrSize);
	return res;
}
