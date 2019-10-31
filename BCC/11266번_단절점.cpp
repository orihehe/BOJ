/*
BOJ 11266 - 단절점
https://www.acmicpc.net/problem/11266
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<int> vec[10001], ans;
int num[10001], cnt, bnum, bcnt[10001];
vector<pii> sta, bcc[10001];
int dfs(int cur, int p) {
	int ret = num[cur] = ++cnt;
	for (int v : vec[cur]) {
		if (v == p) continue;
		if (num[cur] > num[v]) sta.push_back({ cur,v });
		if (num[v]) ret = min(ret, num[v]);
		else {
			int tmp = dfs(v, cur);
			ret = min(ret, tmp);
			if (tmp >= num[cur]) {
				while (!sta.empty() && sta.back() != pii(cur, v)) {
					bcc[bnum].push_back(sta.back());
					sta.pop_back();
				}
				bcc[bnum].push_back(sta.back());
				sta.pop_back();
				bnum++;
			}
		}
	}
	return ret;
}
int main() {
	int v, e, a, b;
	scanf("%d %d", &v, &e);
	while (e--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		if (!num[i]) dfs(i, i);
	}
	for (int i = 0; i < bnum; i++) {
		for (pii v : bcc[i]) {
			if (bcnt[v.first]) num[v.first] = -1;
			if (bcnt[v.second]) num[v.second] = -1;
		}
		for (pii v : bcc[i])
			bcnt[v.first] = bcnt[v.second] = i + 1;
	}
	for (int i = 1; i <= v; i++) if (num[i] == -1) ans.push_back(i);

	printf("%d\n", ans.size());
	for (int v : ans) printf("%d ", v);

	return 0;
}