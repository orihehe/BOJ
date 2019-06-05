/*
위상정렬 문제
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int indegree[32001];
int main() {
	int n, m, a, b;
	vector<int> vec[32001];
	queue<int> q;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int &v : vec[tmp]) {
			indegree[v]--;
			if (indegree[v] == 0) q.push(v);
		}
		printf("%d ", tmp);
	}

	return 0;
}