/*
BOJ 1108 - 검색 엔진
https://www.acmicpc.net/problem/1108

scc로 정점을 묶은 뒤 정점에 속하는 원소들끼리의 간선을 제외하고 위상정렬
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

/* 🐣🐥 */
stack<int> sta;
map<string, int> mp;
vector<int> vec[2501];
queue<int> q;
int mcnt, num[2501], cnt, fn[2501], scnt, ind[2501];
long long arr[2501];
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!fn[v]) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		scnt++;
		while (true) {
			int nx = sta.top();
			sta.pop();
			fn[nx] = scnt;
			if (nx == cur) break;
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, cur;
	string x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> m;
		if (mp.find(x) == mp.end()) {
			mp[x] = ++mcnt;
		}
		cur = mp[x];
		while (m--) {
			cin >> x;
			if (mp.find(x) == mp.end()) {
				mp[x] = ++mcnt;
			}
			vec[mp[x]].push_back(cur);
			ind[cur]++;
		}
	}
	for (int i = 1; i <= mcnt; i++) if (!num[i]) dfs(i);
	for (int i = 1; i <= mcnt; i++) {
		arr[i] = 1;
		for (int v : vec[i]) if (fn[v] == fn[i]) ind[v]--;
	}
	for (int i = 1; i <= mcnt; i++) {
		if (!ind[i]) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int v : vec[cur]) {
			if (fn[cur] == fn[v]) continue;
			ind[v]--;
			arr[v] += arr[cur];
			if (!ind[v]) q.push(v);
		}
	}
	cin >> x;
	cout << arr[mp[x]];

	return 0;
}