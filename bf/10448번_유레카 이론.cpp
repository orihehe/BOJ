/*
BOJ 10448 (https://www.acmicpc.net/problem/10448)
n과m 문제들과 비슷한 문제이다.
처음에는 고려할 삼각수의 개수가 많아 TLE가 나지 않을까 싶었지만
3개의 수만 고르고, 1000이하라는 조건이 있어 괜찮았다.
*/
#include <cstdio>
using namespace std;

int t, k, arr[51], x = 0;
bool ep[1001];
void dfs(int cnt, int sum) {
	if (cnt == 3) {
		ep[sum] = true;
		return;
	}
	for (int i = 1; i <= 50; i++) {
		if (sum + arr[i] <= 1000) {
			dfs(cnt + 1, sum + arr[i]);
		}
	}
}
int main() {
	for (int i = 1; i <= 50; i++) {
		x += i;
		arr[i] = x;
	}
	dfs(0, 0);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);
		printf("%d\n", ep[k]);
	}

	return 0;
}