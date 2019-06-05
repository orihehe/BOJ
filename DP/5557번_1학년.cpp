/*
백준 5557 1학년(https://www.acmicpc.net/problem/5557)
식의 뒤에서부터 생각했다. dp[i][0~20]에 dp[i+1][j]의 값에 현재 수(arr[i])를 빼거나 더한 경우의 수를 저장한다.
*/
#include <cstdio>
#define ll long long
using namespace std;

ll dp[100][21], arr[100];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	dp[n - 1][arr[n-1]]++;
	for (int i = n - 2; i >= 1; i--) {
		for (int j = 0; j < 21; j++) {
			if (j + arr[i] <= 20) {
				dp[i][j + arr[i]] += dp[i + 1][j];
			}
			if (j - arr[i] >=0) {
				dp[i][j - arr[i]] += dp[i + 1][j];
			}
		}
	}
	printf("%lld", dp[1][arr[0]]);

	return 0;
}