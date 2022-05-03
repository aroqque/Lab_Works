#include "foo.h"

#define N 10

int main()
{
	srand(time(NULL));

	char fname1[] = "text1.txt";
	char fname2[] = "text2.txt";

	int mas1[N];
	int mas2[N];
	int x = 0;

	fill_array(mas1, N);
	foo1(fname1, mas1, N);
	foo2(fname1, fname2, mas1, mas2, N);
	foo3(fname2, x, N);
	cout << "\n";
	print_array(mas2, N);
}