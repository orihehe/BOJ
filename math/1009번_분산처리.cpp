#include <cstdio>
using namespace std;

int main()
{
	int t,a,tmp,b, arr[4];
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		if (a % 10 == 0) {
			printf("10\n");
			continue;
		}
		tmp = a;
		for (int i = 1; i < 4; i++) {
			arr[i] = tmp % 10;
			tmp *= a;
		}
		arr[0] = tmp % 10;
		printf("%d\n", arr[b % 4]);
	}

	return 0;
}