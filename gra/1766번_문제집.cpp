/*
위상정렬
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int indegree[32001];
int main() {
	int n, m, a, b;
	vector<int> vec[32001];
	priority_queue<int, vector<int>, greater<int>> pq;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) pq.push(i);
	}
	while (!pq.empty()) {
		int tmp = pq.top();
		pq.pop();
		for (int &v : vec[tmp]) {
			indegree[v]--;
			if (indegree[v] == 0) pq.push(v);
		}
		printf("%d ", tmp);
	}

	return 0;
}