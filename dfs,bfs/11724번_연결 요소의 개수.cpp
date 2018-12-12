// น้มุ 11724 (https://www.acmicpc.net/problem/11724)
#include <cstdio>
#include <vector>
using namespace std;

bool visited[1001];
vector<int> vec[1001];
void dfs(int cur) {
	visited[cur] = true;
	for (int &v : vec[cur]) {
		if (!visited[v]) dfs(v);
	}
}
int main() {
	int n, m, cnt = 0, a, b;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}