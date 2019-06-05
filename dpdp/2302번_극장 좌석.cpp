/*
N(x)=N(x-1)+N(x-2)
x���� x-1�������� �¼� ��ü ��� �ڿ� �׳� ���ϰ�� (N(x-1))
x���� x-1�� �ڸ��� �ٲ� ��� (N(x-2)) �̴�.
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int dp[41];
int main() 
{
	int n, m, x, lastV=0, sum=1;
	scanf("%d %d", &n, &m);
	dp[0] = 1; dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
	while (m--) {
		scanf("%d", &x);
		sum *= dp[x-1 - lastV];
		lastV = x;
	}
	sum *= dp[n - lastV];
	printf("%d", sum);

	return 0;
}