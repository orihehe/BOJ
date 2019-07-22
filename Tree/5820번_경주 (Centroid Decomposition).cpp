/*
BOJ 5820 - 경주
https://www.acmicpc.net/problem/5820
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long
#define pii pair<int,int>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
vector<pii> vec[200001];
vector<int> my[200001];
map<ll, int> mp[200001];
int k, n, ch[200001], num[20][200001], ans = INF;
ll dist[20][200001];
bool use[200001];
int getSize(int cur, int p) {
	ch[cur] = 1;
	for (pii v : vec[cur]) {
		if (v.second != p && !use[v.second])
			ch[cur] += getSize(v.second, cur);
	}
	return ch[cur];
}
int ctr(int cur, int p, int sz) {
	for (pii v : vec[cur]) {
		if (v.second != p && !use[v.second] && ch[v.second] > sz)
			return ctr(v.second, cur, sz);
	}
	return cur;
}
void dfs(int cur, ll dd, int cnt, int dep, int p, int pidx) {
	dist[dep][cur] = dd;
	num[dep][cur] = cnt;
	my[pidx].push_back(cur);
	for (pii v : vec[cur]) {
		if (v.second != p && !use[v.second])
			dfs(v.second, dd + v.first, cnt + 1, dep, cur, pidx);
	}
}
int dq(int cur, int dep) {
	int nx = ctr(cur, cur, getSize(cur, cur) / 2);
	dfs(nx, 0, 0, dep, nx, nx);
	use[nx] = true;
	mp[nx][0] = 0;
	for (pii v : vec[nx]) {
		if (!use[v.second]) {
			int cc = dq(v.second, dep + 1);
			for (int vv : my[cc]) {
				ll rm = k - dist[dep][vv];
				if (mp[nx].find(rm) != mp[nx].end()) {
					ans = min(ans, mp[nx][rm] + num[dep][vv]);
				}
			}
			for (int vv : my[cc]) {
				if (mp[nx].find(dist[dep][vv]) == mp[nx].end()) mp[nx][dist[dep][vv]] = num[dep][vv];
				else mp[nx][dist[dep][vv]] = min(mp[nx][dist[dep][vv]], num[dep][vv]);
			}
			my[cc].clear();
		}
	}
	mp[nx].clear();
	return nx;
}
int main() {
	int a, b, c;
	scanf("%d %d", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	dq(0, 0);
	printf("%d", ans == INF ? -1 : ans);

	return 0;
}
