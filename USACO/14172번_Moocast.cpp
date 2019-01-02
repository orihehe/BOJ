/*
BOJ 14172 (https://www.acmicpc.net/problem/14172)
각각 소들에 대해 p범위 안에 있는지 확인한다. 
범위 안에 있는 소와 간선을 만들어 준뒤 각 소에 대해 dfs로 마릿수를 세어 가장 큰 값을 출력한다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct loc {
	int x, y, p;
};
vector<int> vec[200];
bool visited[200];
int cnt;
void dfs(int cur) {
	visited[cur] = true;
	cnt++;
	for (int v : vec[cur]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main() {
	int n, maxC = 0;
	loc cow[200];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &cow[i].x, &cow[i].y, &cow[i].p);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int nx = cow[i].x - cow[j].x, ny = cow[i].y - cow[j].y;
			if (nx*nx + ny * ny <= cow[i].p * cow[i].p) {
				vec[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cnt = 0;
		memset(visited, false, sizeof(visited));
		dfs(i);
		maxC = max(maxC, cnt);
	}
	printf("%d", maxC);

	return 0;
}