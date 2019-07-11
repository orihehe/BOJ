/*
BOJ 5888 - Haybale Restacking
https://www.acmicpc.net/problem/5888
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[100001];
ll ans;
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &arr[i]);
		arr[i] -= x;
	}
	for (int i = 1; i < n; i++) arr[i] += arr[i - 1];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) ans += abs(arr[i] - arr[n / 2]);
	printf("%lld", ans);

	return 0;
}