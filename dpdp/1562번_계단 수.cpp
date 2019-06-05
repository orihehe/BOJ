/*
BOJ 1562 (https://www.acmicpc.net/problem/1562)

쉬운 계단 수 문제와 다른점은 0~9의 숫자가 최소 한번씩은 등장해야 한다는 것이다.
계단 수는 인접한 자릿수의 차이가 1이므로 0과 9가 모두 등장한다면 계단 수이다.
따라서 0이 등장할 때 2^0을 OR 연산으로 켜주고, 9가 등장할 때 2^1을 켜주었다.
모두 켜진 상태인 3에서의 값이 답이 된다.
*/
#include <cstdio>
#define mod 1000000000
using namespace std;

int dp[4][10][101]; // 0,9 둘 다 있는지, 끝 자리 숫자, 자릿수
int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i < 9; i++) {
		dp[0][i][1] = 1;
	}
	dp[2][9][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int k = 0; k < 4; k++) {
			for (int j = 1; j < 9; j++) {
				dp[k][j][i] = ((dp[k][j][i] +
					dp[k][j - 1][i - 1]) % mod +dp[k][j + 1][i - 1]) % mod;
			}
			// 맨 끝 수가 1인 것에 0 붙이기
			dp[k | 1][0][i] = (dp[k | 1][0][i] + dp[k][1][i - 1]) % mod;
			// 맨 끝 수가 8인 것에 9 붙이기
			dp[k | 2][9][i] = (dp[k | 2][9][i] + dp[k][8][i - 1]) % mod;
		}
	}
	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[3][i][n])%mod;
	}
	printf("%d", sum);

	return 0;
}