/*
BOJ 17515 - Maximizer
https://www.acmicpc.net/problem/17515

n/2보다 작은 수는 n/2보다 큰 수와 짝짓고, n/2보다 큰 수는 n/2보다 작은 수와 짝지어준다.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
int A[250001], B[250001];
vector<int> loc;
int main() {
	int n;
	scanf("%d", &n);
	int tmp = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		if (A[i] <= n / 2) loc.push_back(i);
		if (n % 2 && A[i] == n / 2 + 1) tmp = i;
	}
	int ap = 0;
	ll ans = 0, tans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
		if (B[i] > n / 2 + n % 2) {
			ans += abs(loc[ap++] - i);
		}
	}
	if (tmp != -1) loc.push_back(tmp);
	sort(loc.begin(), loc.end());
	ap = 0;
	for (int i = 0; i < n; i++) {
		if (B[i] > n / 2) {
			tans += abs(loc[ap++] - i);
		}
	}
	printf("%lld", min(tans, ans));

	return 0;
}