/*
BOJ 14718 - 용감한 용사 진수
https://www.acmicpc.net/problem/14718

x에대해 정렬 후 y,z 완탐
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
struct info {
	int x, y, z;
	bool operator <(const info &a) const {
		return x < a.x;
	}
}arr[101];
int main() {
	int n, m, ans = 3000000, cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].z);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt = 0;
			for (int k = 0; k < n; k++) {
				if (arr[i].y >= arr[k].y && arr[j].z >= arr[k].z) cnt++;
				if (cnt >= m) {
					ans = min(ans, arr[i].y + arr[j].z + arr[k].x);
					break;
				}
			}
		}
	}
	printf("%d", ans);

	return 0;
}