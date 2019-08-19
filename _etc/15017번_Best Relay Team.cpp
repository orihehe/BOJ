/*
BOJ 15017 - Best Relay Team
https://www.acmicpc.net/problem/15017
*/
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
char st[501][22];
int f[501];
pii arr[501];
int main() {
	int n;
	double x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %lf %lf", st[i], &x, &y);
		f[i] = (x + 1e-7) * 100;
		arr[i].first = (y + 1e-7) * 100;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	int ans = 987654321, idx = 0;
	for (int i = 0; i < n; i++) {
		int p = 0, tmp = f[arr[i].second];
		for (int j = 0; j < n; j++) {
			if (p == 3) break;
			if (arr[j].second == arr[i].second) continue;
			tmp += arr[j].first;
			p++;
		}
		if (ans > tmp) {
			ans = tmp;
			idx = arr[i].second;
		}
	}
	printf("%d.%d%d\n%s\n", ans / 100, ans / 10 % 10, ans % 10, st[idx]);
	int p = 0;
	for (int j = 0; j < n; j++) {
		if (p == 3) break;
		if (arr[j].second == idx) continue;
		printf("%s\n", st[arr[j].second]);
		p++;
	}

	return 0;
}