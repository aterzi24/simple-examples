#include<stdio.h>
FILE *f;

void func()
{
	int x = ftell(f);
	fseek(f, sizeof(int), SEEK_CUR);

	fseek(f, x, SEEK_SET);
}


main()
{

	int n, m, b[3][7], i, j;
	unsigned int q;
	float ff, a[10];
	double c[3], s;
	long x;
	f = fopen("sample.dat", "r");

	printf("%d\n", ftell(f));

	fseek(f, sizeof(int), SEEK_SET);

	func();

	printf("%d\n", ftell(f));

	fread(&ff, sizeof(float), 1, f);

	fseek(f, sizeof(int), SEEK_CUR);
	printf("%d\n", ftell(f));

	fclose(f);
}
