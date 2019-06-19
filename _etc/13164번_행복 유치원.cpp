/*
BOJ 13164 - 행복 유치원
https://www.acmicpc.net/problem/13164

조가 갈리는 두 원소의 차이 외의 차이의 합이 답이다.
따라서 차이의 합에서 차이가 큰것 k개를 빼준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[300001], mid[300001];
int main() {
	int n, k, cnt = 0, sum = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n - 1; i++) {
		mid[i] = arr[i + 1] - arr[i];
		sum += mid[i];
	}
	sort(mid, mid + n - 1);
	for (int i = n - 1; i >= n - k; i--) sum -= mid[i];
	printf("%d", sum);

	return 0;
}