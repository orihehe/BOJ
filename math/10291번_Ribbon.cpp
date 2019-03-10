/*
BOJ 10291 - Ribbon
https://www.acmicpc.net/problem/10291

모든 입력에 대해 2씩 빼준 값을 저장하고 최대공약수를 구하면 된다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int gcd(int a, int b) {
	if (b > a) swap(a, b);
	int tmp;
	while (b > 0) {
		tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}
int main() {
	int n, sum, ans;
	int arr[11];
	while (~scanf("%d", &n)) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			arr[i] -= 2;
			sum += arr[i];
		}
		ans = arr[0];
		for (int i = 1; i < n; i++) {
			ans = gcd(ans, arr[i]);
		}
		printf("%d %d\n", ans, sum/ans);
	}

	return 0;
}