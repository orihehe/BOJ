/*
위상정렬
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int indegree[1001];
int main() {
	int n, m, t, x, last;
	vector<int> vec[1001], res;
	queue<int> q;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d", &t);
		scanf("%d", &last);
		--t;
		while (t--) {
			scanf("%d", &x);
			vec[last].push_back(x);
			last = x;
			indegree[x]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		res.push_back(tmp);
		for (int &v : vec[tmp]) {
			indegree[v]--;
			if (indegree[v] == 0) q.push(v);
		}
	}
	// 불가능한 경우 res 원소의 개수가 n보다 적을 것
	if (res.size() != n) printf("0");
	else {
		for (int i = 0; i < n; i++) printf("%d\n", res[i]);
	}

	return 0;
}