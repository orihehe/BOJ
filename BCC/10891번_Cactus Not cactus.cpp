/*
BOJ 10891 - Cactus? Not cactus?
https://www.acmicpc.net/problem/10891

BCC를 만드는 과정에서 나보다 num이 작은 개수가 1이하라면 선인장이다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[100001];
int num[100001], cnt;
bool ans = true;
int dfs(int cur, int p) {
	int ret = num[cur] = ++cnt;
	int cng = 0;
	for (int v : vec[cur]) {
		if (v == p) continue;
		if (num[v]) {
			ret = min(ret, num[v]);
			cng++;
		}
		else {
			int tmp = dfs(v, cur);
			ret = min(ret, tmp);
			if (num[cur] > tmp) cng++;
		}
	}
	if (cng >= 2) ans = false;
	return ret;
}
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 1);
	printf("%s", ans ? "Cactus" : "Not cactus");

	return 0;
}