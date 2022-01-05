#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char const* const n1 = "world";

	char n2[5] = "world";
	strcpy(n2, "blah");

	printf("hello, %s, %s\n", n1, n2);
	return 0;
}
