/*
BOJ 13333 - Q-인덱스
https://www.acmicpc.net/problem/13333
*/
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

/* 🐣🐥 */
int arr[1002];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	sort(arr + 1, arr + n + 1, greater<int>());
	for (int i = 0; i <= n; i++) {
		int up = 0;
		for (int j = 1; j <= n; j++)
			if (arr[j] >= i) up++;
		if (arr[i + 1] > i) continue;
		if (up >= i) return !printf("%d", i);
	}

	return 0;
}