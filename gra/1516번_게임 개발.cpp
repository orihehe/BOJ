/*
ACM Craft(https://www.acmicpc.net/problem/1005)와 유사한 문제
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int time[501];
bool visited[501];
vector<int> vec[501];
int dfs(int cur) {
	visited[cur] = true;
	int tmp = 0;
	for (int &v : vec[cur]) {
		tmp = max(tmp, !visited[v] ? dfs(v) : time[v]);
	}
	return time[cur] += tmp;
}

int main() {
	int n, t;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		time[i] = t;
		while (true) {
			scanf("%d", &t);
			if (t == -1) break;
			vec[i].push_back(t);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) dfs(i);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", time[i]);
	}

	return 0;
}