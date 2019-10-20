/*
BOJ 11377 - 열혈강호 3
https://www.acmicpc.net/problem/11377

먼저 직원별로 하나의 일을 담당시켜 매칭시켜준다.
그리고나서 하나씩 더 시켰을 때 더 할수 있는 양과, 일을 2개 할 수 있는 명수중 작은 값을 더해 출력
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
int B[1001];
vector<int> vec[2001];
bool visited[2001];
bool dfs(int cur) {
	visited[cur] = true;
	for (int v : vec[cur]) {
		if (B[v] == -1 || !visited[B[v]] && dfs(B[v])) {
			B[v] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	int n, m, k, ans = 0, x, xx, sa = 0;
	scanf("%d %d %d", &n, &m, &k);
	memset(B, -1, sizeof(B));
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		for (int j = 0; j < x; j++) {
			scanf("%d", &xx);
			vec[i].push_back(xx);
			vec[i + n].push_back(xx);
		}
	}
	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) {
			ans++;
		}
	}
	for (int i = n; i < 2*n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) {
			sa++;
		}
	}
	printf("%d", ans + min(sa,k));

	return 0;
}