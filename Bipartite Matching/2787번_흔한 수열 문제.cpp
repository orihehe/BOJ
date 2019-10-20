/*
BOJ 2787 - 흔한 수열 문제
https://www.acmicpc.net/problem/2787

x y v에서 v는 무조건 x~y구간에 존재해야한다.
따라서 각 v의 구간의 교집합을 구해두고, 각 위치의 최댓값, 최솟값을 구해서
v별로 조건을 만족한다면 그 인덱스로의 간선을 만들어준다.
그리고나서 이분매칭으로 확인.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
int mx[201], mn[201], B[201], l[201], r[201];
vector<int> vec[201];
bool visited[201];
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
	int n, m, cm, a, b, c;
	scanf("%d %d", &n, &m);
	fill(mx, mx + n, n);
	fill(mn, mn + n, 1);
	fill(l + 1, l + n + 1, 0);
	fill(r + 1, r + n + 1, n - 1);

	memset(B, -1, sizeof(B));
	while (m--) {
		scanf("%d %d %d %d", &cm, &a, &b, &c);
		a--, b--;
		if (cm == 1) {
			for (int i = a; i <= b; i++) {
				mx[i] = min(mx[i], c);
			}
		}
		else if (cm == 2) {
			for (int i = a; i <= b; i++) {
				mn[i] = max(mn[i], c);
			}
		}
		l[c] = max(l[c], a);
		r[c] = min(r[c], b);
	}
	for (int i = 0; i < n; i++)
		for (int j = mn[i]; j <= mx[i]; j++) {
			if (l[j] <= i && i <= r[j])
				vec[j].push_back(i);
		}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) cnt++;
	}
	if (cnt == n) {
		for (int i = 0; i < n; i++) printf("%d ", B[i]);
	}
	else printf("-1");

	return 0;
}