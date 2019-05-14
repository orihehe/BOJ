/*
BOJ 17074 - 정렬
https://www.acmicpc.net/problem/17074

배열이 이미 정렬되어있다면 원소 개수 출력,
그렇지 않다면 정렬되지 않은 한 위치의 주변 5개를 빼봤을 때 정렬되어있는지 체크했다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[100001], ans, pp;
bool suc = true;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			suc = false;
			pp = i;
			break;
		}
	}
	if (suc) return !printf("%d", n);
	for (int i = max(0, pp - 2); i < min(pp + 2, n); i++) {
		suc = true;
		for (int j = 0; j < n - 1; j++) {
			if (j == i) continue;
			if (j + 1 == i) {
				if (j + 2 < n && arr[j] > arr[j + 2]) {
					suc = false;
					break;
				}
			}
			else if (arr[j] > arr[j + 1]) {
				suc = false;
				break;
			}
		}
		if (suc) ans++;
	}
	printf("%d", ans);

	return 0;
}