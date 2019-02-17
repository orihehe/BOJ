/*
BOJ 16725 (https://www.acmicpc.net/problem/16725)

현재 항의 계수는 이전에 나온 항의 계수들을 앞에서부터 n길이의 구간을 더한 값이다.
구간을 한 칸씩 옮겨주며 구해준다.
*/
#include <cstdio>
#include <cstring>
#define ll long long
#define mod 1000000009
using namespace std;

/* 🐣🐥 */
int fr[250001], tmp[250001];
int main() {
	int n, m, k, l, r, idx;
	ll sum;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= n; i++) {
		fr[i] = 1;
	}
	for (int i = 0; i < m - 1; i++) {
		l = r = sum = idx = 0;
		while (true) {
			if (fr[r] == 0) {
				sum = (sum - fr[l++] + mod) % mod;
				tmp[idx++] = (int)sum;
				if (l == r)break;
			}
			else if (r - l < n + 1) {
				sum = (sum + fr[r++]) % mod;
				tmp[idx++] = (int)sum;
			}
			else {
				sum = (sum + fr[r++] - fr[l++] + mod) % mod;
				tmp[idx++] = (int)sum;
			}
		}
		memcpy(fr, tmp, sizeof(fr));
	}
	printf("%d", fr[k]);

	return 0;
}