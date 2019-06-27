/*
BOJ 16367 - TV Show Game
https://www.acmicpc.net/problem/16367
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii fn[10001];
int k, num[10001], cnt, scnt;
vector<int> vec[10001];
stack<int> sta;
bool suc = true, visited[10001], ans[5001];
int getOP(int cur) {
	return cur + (cur > k ? -k : k);
}
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!fn[v].first) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		scnt++;
		while (!sta.empty()) {
			int nx = sta.top();
			sta.pop();
			fn[nx] = { scnt,nx };
			if (fn[getOP(nx)].first == fn[nx].first) suc = false;
			if (nx == cur) break;
		}
	}
	return ret;
}
int main() {
	int n;
	int a[3];
	char x;
	scanf("%d %d", &k, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d %c", &a[j], &x);
			if (x == 'B') a[j] += k;
		}
		vec[getOP(a[0])].push_back(a[1]);
		vec[getOP(a[1])].push_back(a[0]);
		vec[getOP(a[0])].push_back(a[2]);
		vec[getOP(a[2])].push_back(a[0]);
		vec[getOP(a[1])].push_back(a[2]);
		vec[getOP(a[2])].push_back(a[1]);
	}
	for (int i = 1; i <= 2 * k; i++) {
		if (!num[i]) dfs(i);
	}
	if (!suc) return !printf("-1");
	sort(fn + 1, fn + 2 * k + 1, greater<pii>());
	for (int i = 1; i <= 2 * k; i++) {
		if (!visited[getOP(fn[i].second)]) {
			visited[fn[i].second] = true;
		}
		else {
			if (fn[i].second <= k) ans[fn[i].second] = true;
		}
	}
	for (int i = 1; i <= k; i++) {
		if (ans[i]) printf("R");
		else printf("B");
	}

	return 0;
}