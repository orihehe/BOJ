/*
BOJ 17481 - 최애 정하기
https://www.acmicpc.net/problem/17481
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;

/* 🐣🐥 */
int B[1001];
vector<int> vec[1001];
map<string, int> mp;
bool visited[1001];
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	string x;
	int n, m, y, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		mp[x] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> y;
		while (y--) {
			cin >> x;
			vec[i].push_back(mp[x]);
		}
	}
	memset(B, -1, sizeof(B));
	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) ans++;
	}
	if (ans == n) printf("YES");
	else printf("NO\n%d", ans);

	return 0;
}