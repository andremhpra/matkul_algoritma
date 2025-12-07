#include <stdio.h>

#define MAX_FIB_VALUE 100

int main()
{
	// base cases.
	int cache[2] = {1, 1};
	printf("%d %d ", cache[0], cache[1]);

	// then start the fibonaci sequence.
	int fib = 2;
	while (fib <= MAX_FIB_VALUE)
	{
		printf("%d ", fib);

		cache[1] = cache[0];
		cache[0] = fib;

		fib = cache[0] + cache[1];
	}

	return 0;
}
