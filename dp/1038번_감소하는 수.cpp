/*
백준 1038번 감소하는 수 (https://www.acmicpc.net/problem/1038)
dp[자릿수][맨앞수] 배열을 만들어 풀었다. 각 자릿수마다 경우의 수 저장
dp[자릿수][10]자리에는 현재까지 모든 경우의 수 저장
먼저 현재 자릿수i를 구하고 이전 자릿수까지의 모든 경우 + 현재 자릿수 맨 앞자리 경우의 개수로 현재 자릿수의 수 j를 구한다.
그리고나서 이전 자릿수의 9까지의 경우의 수와 현재 자릿수의 수 이전 수까지의 경우의 수를 빼주어 다음 자릿수로 넘어간다.

다른 분 풀이를 보다가 굉장히 감탄한 풀이를 봤다.
-> http://blog.encrypted.gg/142
*/
#include <cstdio>
using namespace std;

int dp[11][11];
int main() {
	int n, i, j;
	for (int i = 0; i < 10; i++) dp[1][i] = dp[1][i - 1] + 1;
	dp[1][10] = 10;
	for (i = 2; i <= 10; i++) {
		for (j = i-1; j < 10; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
		}
		dp[i][10] = dp[i - 1][10] + dp[i][9];
	}
	scanf("%d", &n); n++;
	for (i = 1; i <= 10; i++) {
		if (dp[i][10] >= n) break;
	}
	if (i == 11) printf("-1");
	else {
		for (i; i >= 0; i--) {
			for (j = 0; j < 10; j++) {
				if (dp[i][j] == 0) continue;
				if (dp[i][j] + dp[i - 1][10] >= n) {
					n -= dp[i][j - 1] + dp[i - 1][9];
					printf("%d", j);
					break;
				}
			}
		}
	}

	return 0;
}