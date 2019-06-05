/*
BOJ 13328 - Message Passing
https://www.acmicpc.net/problem/13328

dp[n] = dp[n-1] + dp[n-2] + ... + dp[n-d]
행렬곱을 이용, 빠른제곱으로 빠르게 연산해주자
*/
#include <cstdio>
#include <cstring>
#define mod 31991
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[51][51], d, t;
int calc(int b) {
	int ret[51][51], tmp[51][51];
	memset(ret, 0, sizeof(ret));
	ret[0][0] = 1;
	for (int i = 0; i < d; i++) ret[0][i] = 1, arr[0][i] = 1;
	for (int i = 1; i < d; i++) ret[i][i - 1] = 1, arr[i][i - 1] = 1;
	while (b > 0) {
		if (b % 2) {
			for (int i = 0; i < d; i++) {
				for (int j = 0; j < d; j++) {
					ll tt = 0;
					for (int k = 0; k < d; k++) {
						tt += ret[i][k] * arr[k][j];
					}
					tmp[i][j] = tt % mod;
				}
			}
			memcpy(ret, tmp, sizeof(ret));
		}
		b /= 2;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < d; j++) {
				ll tt = 0;
				for (int k = 0; k < d; k++) {
					tt += arr[i][k] * arr[k][j];
				}
				tmp[i][j] = tt % mod;
			}
		}
		memcpy(arr, tmp, sizeof(arr));
	}
	return ret[0][0];
}
int main() {
	scanf("%d %d", &d, &t);
	for (int i = 0; i < d; i++) arr[0][i] = 1;
	for (int i = 1; i < d; i++) arr[i][i - 1] = 1;
	printf("%d", calc(t - 1));

	return 0;
}