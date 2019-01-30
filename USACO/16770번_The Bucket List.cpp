// BOJ 16770 (https://www.acmicpc.net/problem/16770)
#include <cstdio>
#include <algorithm>
using namespace std;

int n, cur, maxB = 0, l, r, b;
int arr[1001];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &l, &r, &b);
		for (int j = l; j <= r; j++) arr[j] += b;
	}
	for (int i = 1; i <= 1000; i++) {
		maxB = max(maxB, arr[i]);
	}
	printf("%d", maxB);

	return 0;
}