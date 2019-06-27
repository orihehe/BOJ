/*
BOJ 17257 - 불확정성이 넘쳐흘러
https://www.acmicpc.net/problem/17257

자세한 증명은 SCON 대회 풀이에 있다.
-> https://docs.google.com/document/d/1ridq9imuGpG-2prWMrm-1VQE5BkB9T_h4LpSoBCTppU/edit
*/
#include <cstdio>
#include <vector>
#define ll long long
#define mod 1000000009
using namespace std;

/* 🐣🐥 */
vector<ll> vec;
ll arr[100];
ll myPow(ll a, int b) {
	ll ret = 1;
	while (b > 0) {
		if (b % 2) {
			ret = ret * a%mod;
		}
		b /= 2;
		a = a * a%mod;
	}
	return ret;
}
bool isPrime(int a) {
	for (int i = 2; i*i <= a; i++)
		if (a%i == 0) return false;
	return true;
}
int main() {
	ll ans = 0, up, dw, y;
	int n, cnt = 0;
	scanf("%d %lld", &n, &y);
	for (int i = 2; i*i <= y; i++) {
		if (y%i == 0) {
			if (isPrime(i))
				vec.push_back(i);
			if (isPrime(y / i)) vec.push_back(y / i);
			cnt++;
		}
	}
	if (cnt == 0) vec.push_back(y);

	int sz = vec.size();
	for (int i = 0; i < sz; i++) arr[i] = 1;
	y = myPow(y, n);
	for (int i = 1; i <= n; i++) {
		up = dw = 1;
		for (int j = 0; j < sz; j++) {
			arr[j] = arr[j] * vec[j] % mod;
			up = up * (arr[j] - 1 + mod) % mod;
			dw = dw * arr[j] % mod;
		}
		up = up * (n - i + 1) % mod;
		ans = (ans + up * y %mod *myPow(dw, mod - 2) % mod) % mod;
	}
	printf("%lld", ans);

	return 0;
}