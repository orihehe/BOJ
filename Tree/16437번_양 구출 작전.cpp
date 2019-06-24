/*
BOJ 16437 - 양 구출 작전
https://www.acmicpc.net/problem/16437
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
vector<int> vec[123457];
int arr[123457];
bool wolf[123457];
ll dfs(int cur) {
	ll ret = 0;
	for (int v : vec[cur]) {
		ret += dfs(v);
	}
	if (wolf[cur]) return max(0LL, ret - arr[cur]);
	else return ret + arr[cur];
}
int main() {
	int n, b;
	char w;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf(" %c %d %d", &w, &arr[i], &b);
		if (w == 'W') wolf[i] = true;
		vec[b].push_back(i);
	}
	printf("%lld", dfs(1));

	return 0;
}