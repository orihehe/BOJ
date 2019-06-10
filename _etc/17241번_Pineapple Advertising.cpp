/*
BOJ 17241 - Pineapple Advertising
https://www.acmicpc.net/problem/17241
*/
#include <cstdio>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[200001];
int num[1000001];
int main() {
	int n, m, q, a, b, ans;
	scanf("%d %d %d", &n, &m, &q);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	while (q--) {
		ans = 0;
		scanf("%d", &a);
		if (!num[a]) ans++, num[a]++;
		for (int v : vec[a]) {
			if (!num[v]) ans++;
			num[v]++;
		}
		vec[a].clear();
		printf("%d\n", ans);
	}

	return 0;
}