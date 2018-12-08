#include <cstdio>
int main()
{
	int m;
	scanf("%d", &m);
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}