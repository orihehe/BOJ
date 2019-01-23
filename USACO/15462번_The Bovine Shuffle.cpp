/*
BOJ 15462 (https://www.acmicpc.net/problem/15462)

��������Ʈ ������ �Ȱ��� Ǯ����.
i->ai ������ �׷����� �����غ��� �ᱹ ����Ŭ�� �̷�� ���鿡�� �ҵ��� �̵��ϰ� �ȴ�.
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