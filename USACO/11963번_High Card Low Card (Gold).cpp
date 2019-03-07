/*
BOJ 11963 - High Card Low Card (Gold)
https://www.acmicpc.net/problem/11963

BOJ 11968번 문제와 같은 방식이다.
내 카드의 작은 반개는 2R에서, 큰 반개는 1R에서 사용
*/
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

/* 🐣🐥 */
int arr[50001];
bool use[100001];
int be[50001], bp, cnt;
int main() {
	int n, bend;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		use[arr[i]] = true;
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (!use[i])be[bp++] = i;
	}
	sort(arr, arr + n / 2, greater<int>()); // 앞부터 큰거 1R
	sort(arr + n / 2, arr + n); // 앞부터 작은거 2R
	bp = n / 2, bend = n-1;
	for (int i = 0; i < n / 2; i++) {
		if (arr[i] > be[bend]) {
			bp++;
		}
		else {
			cnt++;
			bend--;
		}
	}
	bp = 0, bend = n / 2-1;
	for (int i = n / 2; i < n; i++) {
		if (arr[i] < be[bp]) {
			bend--;
		}
		else {
			cnt++;
			bp++;
		}
	}
	printf("%d", cnt);

	return 0;
}