#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{
	int n, sum = 0,x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		sum += x;
	}
	printf("%d", sum - n + 1);

	return 0;
}
