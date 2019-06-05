/*
BOJ 11597 - Excellence
https://www.acmicpc.net/problem/11597

정렬 후 양 끝에서부터 조합하여 최솟값을 찾아준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[100001], mn = 2000001;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);

	for (int i = 0; i < n / 2; i++) {
		mn = min(mn, arr[i] + arr[n - i - 1]);
	}
	printf("%d", mn);
	return 0;
}