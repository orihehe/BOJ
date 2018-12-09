/*
ó���� �������迭�� Ǯ���ٰ� Ʋ���� ���� �˻� ���� �ô�.
�������迭�� �ϰԵǸ� �ڿ����� i-1�� ��(���� ��� �ٲ� ����)�� �տ����� ������� ���� �ٲ�� ��찡 ���� �� �ִ�.
���� �������迭�� �����ư��� i�� �����ߴ�. 
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int n, m, s, v, dp[2][1001],i,j, cnt=0;
	scanf("%d %d %d", &n, &s, &m);
	memset(dp, -1, sizeof(dp));
	dp[0][s] = 0;
	for (i = 1; i <= n; i++) {
		scanf("%d", &v);
		for (j = 0; j <= m; j++) {
			//���� ��� �� �������� �ٲ��� �� ���� �̾ �� ����
			if (dp[cnt%2][j] == i-1) {
				if (j + v <= m) dp[(cnt+1) % 2][j + v] = i;
				if (j - v >= 0) dp[(cnt+1) % 2][j - v] = i;
			}
		}
		cnt++;
	}
	for (i = m; i >= 0; i--) {
		if (dp[cnt%2][i] == n) {
			printf("%d", i);
			break;
		}
	}
	if (i == -1) printf("-1");

	return 0;
}