/*
���� 11375 ������ȣ (https://www.acmicpc.net/problem/11375)
ó�� ¥���� �ִ� ���� ���ϴ� �˰����̴�
�̺�Ž�����ε� Ǫ�� ������� �ϴµ� ���߿� �װɷε� �ٽ� Ǯ��߰ڴ�.
ó���� bfs�� Ǯ���µ� ��� TLE�� �޾Ҵ�. bfs, dfs ���� ���� ������ �ִٴµ� ���� �������� �� �𸣰ڴ� ��
���� Ǯ����� �ڴ�!
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 2003
using namespace std;

// f�� ���� c�� �뷮
vector<int> vec[MAX];
int f[MAX][MAX], c[MAX][MAX];
int visited[MAX], total = 0;
int n, m, x, w, E = 2002, S = 0;
bool dfs(int cur) {
	if (cur == E) return true;
	for (int &v : vec[cur]) {
		// �뷮-������ 0���� Ŀ�� �� (�� ���� �� �־�� ��)
		if (c[cur][v] - f[cur][v] <= 0 || visited[v] != -1) continue;
		visited[v] = cur;
		if (dfs(v)) return true;
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		// source(S)=0, sink(E)=2002
		// source->����
		vec[S].push_back(i);
		vec[i].push_back(S);
		c[S][i] = 1;
		scanf("%d", &x);
		while (x--) {
			scanf("%d", &w);
			w += 1000;
			// ����->��
			c[i][w] = 1;
			vec[i].push_back(w);
			vec[w].push_back(i);
		}
	}
	// ��-> sink
	for (int i = 1001; i <= 1000 + m; i++) {
		vec[i].push_back(E);
		vec[E].push_back(i);
		c[i][E] = 1;
	}
	fill(visited, visited + MAX, -1);
	while (dfs(S)) {
		for (int i = E; i != S; i = visited[i]) {
			//�������� ����, 
			f[i][visited[i]]--;
			f[visited[i]][i]++;
		}
		total++;
		fill(visited, visited + MAX, -1);
	}
	printf("%d", total);

	return 0;
}