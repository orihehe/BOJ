/*
BOJ 11968 - High Card Wins
https://www.acmicpc.net/problem/11968

상대와 내 카드 모두 큰 카드부터 본다.
만약 내 가장 큰 카드가 상대의 가장 큰 카드보다 작다면 내 카드중 가장 작은 값을 내고,
아니라면 가장 큰 카드를 낸다.
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
	sort(arr, arr + n, greater<int>());
	bp = 0, bend = n-1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > be[bend]) {
			bp++;
		}
		else {
			cnt++;
			bend--;
		}
	}
	printf("%d", cnt);

	return 0;
}