#include <cstdio>
int main()
{
	int num;
	int e, s;
	int i, j;
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		e = i;
		for (j = 0; j < 2 * num - 1 - e; j++)
		{
			s = 2 * num - 1 - i;
			if (e <= j)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}