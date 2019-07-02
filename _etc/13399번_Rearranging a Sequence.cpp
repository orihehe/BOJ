/*
BOJ 13399 - Rearranging a Sequence
https://www.acmicpc.net/source/13710895
*/
#include <cstdio>
#include <algorithm>
#include <functional>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[200001];
bool cmp(pii a, pii b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}
int main() {
	int n, m, a;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) arr[i].second = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a);
		arr[a].first = max(arr[a].first, i);
	}
	sort(arr + 1, arr + n + 1, cmp);
	for (int i = 1; i <= n; i++) printf("%d\n", arr[i].second);

	return 0;
}