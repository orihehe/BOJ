/*
5의 배수로 곱해질때마다 0이 추가된다
25는 5가 두번 있으므로 25때 0이 2번 추가된다
*/
#include <cstdio>
using namespace std;

int main()
{
	int n, cnt=0,tmp;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		tmp = i;
		while (tmp % 5 == 0) {
			tmp /= 5;
			cnt++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}