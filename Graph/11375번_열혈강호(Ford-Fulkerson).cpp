/*
백준 11375 열혈강호 (https://www.acmicpc.net/problem/11375)
처음 짜보는 최대 유량 구하는 알고리즘이다
이분 매칭으로도 푸는 문제라고 하는데 나중에 그걸로도 다시 풀어야겠다.
처음에 bfs로 풀었는데 계속 TLE를 받았다. bfs, dfs 별로 좋은 문제가 있다는데 무슨 차이인지 잘 모르겠다 ㅠ
많이 풀어봐야 겠다!
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 2003
using namespace std;

// f는 유량 c는 용량
vector<int> vec[MAX];
int f[MAX][MAX], c[MAX][MAX];
int visited[MAX], total = 0;
int n, m, x, w, E = 2002, S = 0;
bool dfs(int cur) {
	if (cur == E) return true;
	for (int &v : vec[cur]) {
		// 용량-유량이 0보다 커야 함 (더 보낼 수 있어야 함)
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
		// source->직원
		vec[S].push_back(i);
		vec[i].push_back(S);
		c[S][i] = 1;
		scanf("%d", &x);
		while (x--) {
			scanf("%d", &w);
			w += 1000;
			// 직원->일
			c[i][w] = 1;
			vec[i].push_back(w);
			vec[w].push_back(i);
		}
	}
	// 일-> sink
	for (int i = 1001; i <= 1000 + m; i++) {
		vec[i].push_back(E);
		vec[E].push_back(i);
		c[i][E] = 1;
	}
	fill(visited, visited + MAX, -1);
	while (dfs(S)) {
		for (int i = E; i != S; i = visited[i]) {
			//역방향은 감소, 
			f[i][visited[i]]--;
			f[visited[i]][i]++;
		}
		total++;
		fill(visited, visited + MAX, -1);
	}
	printf("%d", total);

	return 0;
}
