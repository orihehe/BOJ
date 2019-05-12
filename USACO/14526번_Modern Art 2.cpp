/*
BOJ 14526 - Modern Art 2
https://www.acmicpc.net/problem/14526

1 2 1 2 이런식으로 주어지면 불가능.
한 원소의 범위의 안쪽에있는 원소는 안쪽에만 존재해야한다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
int ans = 1, arr[100001];
bool suc = true;
vector<int> vec[100001];
void dfs(int dep, int l, int r) {
	ans = max(dep, ans);
	if (l > r) return;
	for (int i = l; i <= r; i++) {
		if (arr[i] == 0) continue;
		if (!suc) return;
		if (vec[arr[i]].size() == 1) {
			ans = max(dep+1, ans);
			continue;
		}
		int sz = vec[arr[i]].size();
		for (int j = 1; j < sz; j++) {
			if (vec[arr[i]][j] > r) suc = false;
			if (!suc) return;
			dfs(dep + 1, vec[arr[i]][j - 1] + 1, vec[arr[i]][j]-1);
		}
		i = vec[arr[i]][sz - 1];
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		vec[arr[i]].push_back(i);
	}
	dfs(0, 0, n-1);
	if (!suc) printf("-1");
	else printf("%d", ans);

	return 0;
}