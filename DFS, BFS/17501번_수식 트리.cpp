/*
BOJ 17501 - 수식 트리
https://www.acmicpc.net/problem/17501

숫자 부분의 부호를 dfs로 구해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

/* 🐣🐥 */
int arr[100001];
bool buho[200001];
vector<int> vec[200001];
int n, x, y;
void dfs(int cur, bool t) {
	if (cur <= n) {
		buho[cur] = t;
		return;
	}
	dfs(vec[cur][0], t);
	dfs(vec[cur][1], buho[cur] ? !t : t);
}
int main() {
	char cm;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = n + 1; i <= 2 * n - 1; i++) {
		scanf(" %c %d %d", &cm, &x, &y);
		if (cm == '-') buho[i] = true;
		vec[i].push_back(x);
		vec[i].push_back(y);
	}
	dfs(2 * n - 1, false);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += !buho[i];
	}
	int ans = 0;
	sort(arr + 1, arr + n + 1, greater<int>());
	for (int i = 1; i <= cnt; i++) ans += arr[i];
	for (int i = cnt + 1; i <= n; i++) ans -= arr[i];
	printf("%d", ans);

	return 0;
}