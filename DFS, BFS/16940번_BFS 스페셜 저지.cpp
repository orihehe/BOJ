/*
BOJ 16940 - BFS 스페셜 저지
https://www.acmicpc.net/problem/16940

정점을 인덱스순으로 정렬하려 큐에 넣어 bfs를 돌리고, 방문 순서가 같은지 확인해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
queue<int> q;
vector<int> vec[100001];
int idx[100001], cnt;
bool visited[100001];
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		idx[a] = i;
	}
	visited[1] = true;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (idx[cur] != cnt) return !printf("0");
		cnt++;
		sort(vec[cur].begin(), vec[cur].end(), [](int x, int y) {
			return idx[x] < idx[y];
		});
		for (int v : vec[cur]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
	printf("1");

	return 0;
}