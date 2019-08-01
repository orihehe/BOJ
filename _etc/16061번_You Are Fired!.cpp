/*
BOJ 16061 - You Are Fired!
https://www.acmicpc.net/problem/16061
*/
#include <cstdio>
#include <algorithm>
#include <functional>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[10001];
char name[10001][8];
int main() {
	int n, m, d, ans = 0;
	scanf("%d %d %d", &n, &d, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", name[i], &arr[i].first);
		arr[i].second = i;
	}
	sort(arr, arr + n, greater<pii>());
	for (int i = 0; i < m; i++) {
		ans += arr[i].first;
	}
	if (ans >= d) {
		printf("%d\n", m);
		for (int i = 0; i < m; i++)
			printf("%s, YOU ARE FIRED!\n", name[arr[i].second]);
	}
	else printf("impossible");

	return 0;
}