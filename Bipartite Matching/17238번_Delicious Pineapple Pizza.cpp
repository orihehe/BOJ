/*
BOJ 17238 - Delicious Pineapple Pizza
https://www.acmicpc.net/problem/17238

xor한 값을 구해둔 뒤, 이분탐색으로 값을 정해두고
이분매칭에서 mid값 이상인 간선만을 사용하여 모두 매칭 가능한지를 봐준다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int n, vec[101][101], B[101], arr[101], mid;
bool visited[101];
bool dfs(int cur) {
	visited[cur] = true;
	for (int i = 0; i < n; i++) {
		if (vec[cur][i] < mid) continue;
		if (B[i] == -1 || !visited[B[i]] && dfs(B[i])) {
			B[i] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	int x, ans = 0, l, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		for (int j = 0; j < n; j++) {
			vec[i][j] = x ^ arr[j];
		}
	}
	l = 0, r = 1500000000;
	while (l <= r) {
		mid = (1LL * l + r) / 2;
		int cnt = 0;
		memset(B, -1, sizeof(B));
		for (int i = 0; i < n; i++) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) cnt++;
		}
		if (cnt == n) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%d", ans);

	return 0;
}