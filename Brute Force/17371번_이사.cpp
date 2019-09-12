/*
BOJ 17371 - 이사
https://www.acmicpc.net/problem/17371

이사할 곳의 좌표는 항상 주어진 좌표들 중 하나가 된다.
*/
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int dist(pii a, pii b) {
	return (a.first - b.first)*(a.first - b.first) +
		(a.second - b.second)*(a.second - b.second);
}
int main() {
	int n, ans = 1e9, idx;
	pii arr[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	for (int i = 0; i < n; i++) {
		int mx = 0;
		for (int j = 0; j < n; j++) {
			mx = max(mx, dist(arr[i], arr[j]));
		}
		if (ans > mx) {
			ans = mx;
			idx = i;
		}
	}
	printf("%d %d", arr[idx].first, arr[idx].second);

	return 0;
}