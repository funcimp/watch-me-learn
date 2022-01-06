#include <stdio.h>

int main(void) {
	int i = 0;

	// this is the same as while (true)
	for (;;) {
		if (i > 55) {
			break;
		};
		printf("iterator: %d\n", i);
		i++;
	};
}
