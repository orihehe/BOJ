/*
BOJ 15761 (https://www.acmicpc.net/problem/15761)

값이 큰 소부터 줄을 세우면 최소로 레모네이드를 줄 수 있다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[100001];
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] >= cnt) cnt++;
	}
	printf("%d", cnt);

	return 0;
}