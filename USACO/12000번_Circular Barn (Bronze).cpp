/*
BOJ 12000 (https://www.acmicpc.net/problem/12000)

각 지점에서 시작했을 때의 거리를 모두 구하고 가장 작은값 출력
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[1001];
int n, sum, cnt, ans = 987654321;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		sum = cnt = 0;
		for (int j = i + 1; j < n; j++) {
			cnt++;
			sum += arr[j] * cnt;
		}
		for (int j = 0; j < i; j++) {
			cnt++;
			sum += arr[j] * cnt;
		}
		ans = min(ans, sum);
	}
	printf("%d", ans);

	return 0;
}