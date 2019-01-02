/*
BOJ 14172 (https://www.acmicpc.net/problem/14172)
���� �ҵ鿡 ���� p���� �ȿ� �ִ��� Ȯ���Ѵ�. 
���� �ȿ� �ִ� �ҿ� ������ ����� �ص� �� �ҿ� ���� dfs�� �������� ���� ���� ū ���� ����Ѵ�.
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