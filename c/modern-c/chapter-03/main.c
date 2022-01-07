#include <stdio.h>
#include <tgmath.h>

int main(void) {
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
