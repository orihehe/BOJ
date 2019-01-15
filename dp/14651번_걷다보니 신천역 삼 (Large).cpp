/*
BOJ 14651 (https://www.acmicpc.net/problem/14651)
3의 배수는 자릿수 합이 3의 배수가 된다.
이전 자릿수에 구해져있는 0,1,2로만 표현한 수를 3으로 나눈 나머지 별로 생각하면
0,1,2 각각의 수에 0을 더하면 나머지가 0,1,2인 수, 1을 더하면 1,2,0, 2를 더하면 2,0,1 가 나온다.
n자릿수 까지 모두 구해준 뒤 나머지가 0인 n자리 수를 출력하면 된다.
*/
#include <cstdio>
#define ll long long
#define mod 1000000009
using namespace std;

ll dp[3][33334];
int main() {
	int n;
	scanf("%d", &n);
	dp[1][1] = dp[2][1] = 1;
	for (int i = 2; i <= n; i++) {
		ll tmp = dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1];
		for (int j = 0; j < 3; j++) {
			dp[j][i] = (dp[j][i] + tmp) % mod;
		}
	}
	printf("%lld", dp[0][n]);

	return 0;
}