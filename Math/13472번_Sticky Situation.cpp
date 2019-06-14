/*
BOJ 13472 - Sticky Situation
https://www.acmicpc.net/problem/13472

삼각형을 만드려면 작은 두 막대의 합이 가장 큰 막대 보다 커야한다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
long long arr[20001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n - 2; i++) {
		if (arr[i] + arr[i + 1] > arr[i + 2]) return !printf("possible");
	}
	printf("impossible");

	return 0;
}