/*
BOJ 15013 - King of the Waves
https://www.acmicpc.net/problem/15013

각 정점에 내가 이기는 상대로의 간선을 이어준다.
그리고나서 0에서부터 dfs를 돌려 모든 정점을 방문할 수 있다면 dfs를 들어간 역순으로 출력해준다.
내가 이기는 애들로만 가기 때문에 가능하다.
*/
#include <cstdio>
#include <vector>
using namespace std;

char b[1001][1002];
vector<int> vec[1001], ans;
bool visited[1001];
int n, cnt = 0;
bool dfs(int cur) {
	visited[cur] = true;
	cnt++;

	for (int v : vec[cur]) {
		if (!visited[v])
			dfs(v);
	}
	ans.push_back(cur);

	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", b[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (b[i][j] == '1') vec[i].push_back(j);
	}
	dfs(0);
	if (cnt != n) return !printf("impossible");
	for (int v : ans)
		printf("%d ", v);

	return 0;
}