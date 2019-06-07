/*
BOJ 15008 - Falling Apart
https://www.acmicpc.net/problem/15008
*/
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int n, a = 0, b = 0;
	int arr[16];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n, greater<int>());
	for (int i = 0; i < n; i++) {
		if (i % 2) b += arr[i];
		else a += arr[i];
	}
	printf("%d %d", a, b);

	return 0;
}