/*
BOJ 11278 - 2-SAT - 2
https://www.acmicpc.net/problem/11278
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<int> vec[41];
stack<int> sta, ast;
int n, num[41], cnt, scnt;
bool ans, use[41];
pii arr[41];
int getOP(int a) {
	return a + (a > n ? -n : n);
}
bool cmp(pii a, pii b) {
	return a.first > b.first;
}
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!arr[v].first) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		scnt++;
		while (true) {
			int nx = sta.top();
			sta.pop();
			arr[nx].first = scnt;
			if (arr[nx].first == arr[getOP(nx)].first) ans = true;
			if (nx == cur) break;
		}
	}
	return ret;
}
int main() {
	int m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a < 0) a = -a + n;
		if (b < 0) b = -b + n;
		vec[getOP(a)].push_back(b);
		vec[getOP(b)].push_back(a);
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (!num[i]) dfs(i);
		arr[i].second = i;
	}
	sort(arr + 1, arr + 1 + 2 * n, cmp);
	for (int i = 1; i <= 2 * n; i++) {
		if (!use[getOP(arr[i].second)]) use[arr[i].second] = true;
	}

	if (ans) return !printf("0");
	printf("1\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", !use[i]);
	}

	return 0;
}