#include <stdio.h>
#include <tgmath.h>

void loops(void) {
	int i = 0;

	// this is functionally the same as while(true)
	// it gives us an infinite loop
	for (;;) {
		if (i > 10) {
			break;
		};
		printf("for:\t%d\n", i);
		i++;
	};

	// this is a more straight forward version of the logic above
	for (; i < 20; i++) {
		printf("for-v2:\t%d\n", i);
	};

	// this gives us a simple loop
	// the expression is evaluated before running the code
	while (i < 30) {
		printf("while:\t%d\n", i);
		i++;
	}

	// here we have the same logic as the while loop,
	// but we are guaranteed to run it at least once before
	// while evaluation
	do {
		printf("do:\t%d\n", i);
		i++;
	} while (i < 40);

	double const eps = 1E-9;
	double const a	 = 34.0;
	double x				 = 0.5;

	for (size_t j = 0; j < 10; ++j) {
		if (x > 1.0) { // Checks if we are on the correct side of 1
			x = 1.0 / x;
			continue;
		}
		double prod = a * x;
		if (fabs(1.0 - prod) < eps) { // Stops if close enough
			break;
		}
		x *= (2.0 - prod); // Heron approximation
		printf("%f\n", x);
	}
}

// void printArray(int a[], int s) {
void printArray(int a[], int s) {
	printf("[ ");
	for (int i = 0; i < s; i++) {
		printf("%d ", a[i]);
	};
	printf("]\n");
}

// Implimentation of mergeSort
// guided by: https://www.interviewbit.com/tutorial/merge-sort-algorithm/

void merge(int* a, int s, int m, int e) {
	int t[e - s + 1];
	int i = s;
	int j = m + 1;
	int k = 0;

	while (i <= m && j <= e) {
		if (a[i] <= a[j]) {
			t[k] = a[i];
			++i;
		} else {
			t[k] = a[j];
			++j;
		}
		++k;
	}

	while (i <= m) {
		t[k] = a[i];
		++k;
		++i;
	}

	while (j <= e) {
		t[k] = a[j];
		++k;
		++j;
	}

	for (i = s; i <= e; i += 1) {
		a[i] = t[i - s];
	}
}

void mergeSort(int* a, int s, int e) {
	if (s >= e) {
		return;
	}
	int m = (s + e) / 2;
	mergeSort(a, s, m);
	mergeSort(a, m + 1, e);
	merge(a, s, m, e);
}

int main(void) {
	// loops();
	int a[] = {5, 3, 4, 9, 1, 6, 8, 0, 7, 2};
	int s		= sizeof(a) / sizeof(a[0]);
	printArray(a, s);
	mergeSort(a, 0, s - 1);
	printArray(a, s);
}
