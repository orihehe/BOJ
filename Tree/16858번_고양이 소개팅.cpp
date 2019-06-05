/*
BOJ 16858 - 고양이 소개팅
https://www.acmicpc.net/problem/16858

루트로부터 각 노드까지의 거리를 먼저 구해준다.
i와 j의 거리는 dist[j] - dist[i], i가 부모
dist[i]는 공통이니 dist[j]기준으로 정렬하여 관리하면 된다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[200001], v[200001], d[200001];
ll dist[200001];
vector<int> vec[200001];
map<ll, ll> mp[200001];
map<ll, ll> ::iterator iter, tmp;
ll ans;
void dfs(int cur, ll rdd) {
	dist[cur] = rdd;
	for (int v : vec[cur])
		dfs(v, rdd + d[v]);
}
int go(int cur) {
	int o = cur, sz = vec[cur].size();
	if (sz != 0)
		o = go(vec[cur][0]);
	for (int i = 1; i < sz; i++) {
		int nx = go(vec[cur][i]);
		if (mp[nx].size() > mp[o].size()) swap(o, nx);
		for (iter = mp[nx].begin(); iter != mp[nx].end(); iter++) {
			mp[o][iter->first] += iter->second;
		}
		mp[nx].clear();
	}
	if (v[cur] == -1) mp[o][dist[cur]] += arr[cur];
	else {
		iter = mp[o].upper_bound(dist[cur] + v[cur]);
		if (iter != mp[o].begin()) {
			for (--iter; ;) {
				if (iter->second > arr[cur]) {
					ans += arr[cur];
					iter->second -= arr[cur];
					arr[cur] = 0;
				}
				else {
					ans += iter->second;
					arr[cur] -= (int)iter->second;
					iter->second = 0;
				}
				if (iter == mp[o].begin() || !arr[cur]) {
					if (iter->second == 0) {
						tmp = iter--;
						mp[o].erase(tmp->first);
					}
					break;
				}
				if (iter->second == 0) {
					tmp = iter--;
					mp[o].erase(tmp->first);
				}
				else iter--;
			}
		}
	}
	return o;
}
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 2; i <= n; i++) {
		scanf("%d", &x);
		vec[x].push_back(i);
	}
	for (int i = 2; i <= n; i++) {
		scanf("%d", &d[i]);
	}
	dfs(1, 0);
	go(1);
	printf("%lld", ans);

	return 0;
}