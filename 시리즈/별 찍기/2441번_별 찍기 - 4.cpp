#include <cstdio>
int main()
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (j - i >= 0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}