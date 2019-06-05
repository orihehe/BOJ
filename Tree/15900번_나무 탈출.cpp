/*
BOJ 15900 - 나무 탈출
https://www.acmicpc.net/problem/15900

루트에서 각 리프노드로 가는 거리를 계산하여 구한다.
*/
#include <cstdio>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[500001];
long long ans;
void dfs(int cur, int cnt, int p) {
	for (int v : vec[cur]) {
		if (v != p) dfs(v, cnt + 1, cur);
	}
	if (vec[cur].size() == 1)
		ans += cnt;
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 0, 1);
	printf("%s", ans % 2 ? "Yes" : "No");

	return 0;
}