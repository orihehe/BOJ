/*
BOJ 17028 - Sleepy Cow Sorting
https://www.acmicpc.net/problem/17028

끝에서부터 최초의 정렬되지 않은 원소까지의 시간이 걸린다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[101];
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	arr[n] = 987;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] < arr[i + 1])
			ans = i;
		else break;
	}
	printf("%d", ans);

	return 0;
}