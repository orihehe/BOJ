/*
BOJ 15462 (https://www.acmicpc.net/problem/15462)

텀프로젝트 문제와 똑같이 풀었다.
i->ai 간선을 그려보고 생각해보면 결국 사이클을 이루는 노드들에만 소들이 이동하게 된다.
*/
#include <cstdio>
using namespace std;

int cnt, vec[100001];
bool cycle[100001], visited[100001];
void dfs(int cur) {
	int v = vec[cur];
	visited[cur] = true;
	if (!visited[v]) {
		dfs(v);
	}
	else if (!cycle[v]) {
		cnt++;
		for (int i = v; i != cur; i = vec[i])
			cnt++;
	}
	cycle[cur] = true;
}
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		vec[i] = x;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	printf("%d", cnt);

	return 0;
}