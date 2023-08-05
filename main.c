#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CYCLE_ARR for (int i = 0; i < a->arrSize; i++)

typedef struct Array {
	int *arr;
	int arrSize;
} arr_t;


void gint(int *num);   // get integer
int init_arr(arr_t *a); 
void print_arr(arr_t *a);
void swap(int *e1, int *e2); 
void permute(arr_t *a, int arrSize);
long long factorial(int *arrSize);  // calculate factorial
int scan_argv(char **argV, int *arrSize);  // check if an integer is the argument

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
		free(a.arr);
		return 1;
	}

	permute(&a, a.arrSize);
	printf("there are %llu permutations for a %d element array.", factorial(&a.arrSize), a.arrSize);
	free(a.arr);
}

void gint(int *num) {
	char *temp = (char *)malloc(128);
	fgets(temp, 128, stdin);
	if (strlen(temp) > 1) {
		if (!sscanf(temp, "%d", num) || temp[0] == ' ') {  // for some reason, ' ' makes it through sscanf when looking for %d
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
	a->arr = malloc(a->arrSize * sizeof(*a->arr));

	CYCLE_ARR {
        a->arr[i] = i + 1;  // init to 1, 2, 3, etc
    }

	CYCLE_ARR {
		if ((a->arr[i] == '\0') && (i < a->arrSize)) {
			return 0; // 0 = error for formatting purposes (see line 35)
		}
	}
	return 1;
}

void print_arr(arr_t *a) {
	CYCLE_ARR {
		printf("%d ", a->arr[i]);
	}
	puts(" "); // insert a newline after.
}

void swap (int *e1, int *e2) {
	int temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

void permute(arr_t *a, int arrSize) {
	if (arrSize == 1) {
		print_arr(a);	
		return;	
	}
	for (int i = 0; i < arrSize; i++) {
		permute(a, arrSize - 1);
		
		if (arrSize % 2 == 1) {
			swap(&a->arr[0], &a->arr[arrSize - 1]);
		}	
		else {
			swap(&a->arr[i], &a->arr[arrSize - 1]);
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
