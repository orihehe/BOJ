/*
BOJ 15715 - 배열과 gcd
https://www.acmicpc.net/problem/15715

현재 arr[i]의 원소로 가능한 가짓수는 num/c[i]에서 c[i-1]/c[i]의 소인수의 배수를 제외한 값과 같다.
*/
#include <cstdio>
#include <vector>
#define ll long long
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
bool sosu[35000];
vector<int> vec, tt;
int n, num, last, x, tmp, sz, lm;
void prime(int a) {
	for (int v : vec) {
		if (v*v > a) break;
		if (a %v == 0) {
			tt.push_back(v);
			while (a%v == 0) a /= v;
		}
	}
	if (a != 1) tt.push_back(a);
	sz = tt.size();
}
int dfs(int cur, int sum) {
	int ret = 0;
	if (cur != -1)
		ret = lm / sum;
	for (int i = cur + 1; i < sz; i++) {
		if (1LL * tt[i] * sum > lm) break;
		ret -= dfs(i, sum * tt[i]);
	}
	return ret;
}
int main() {
	for (int i = 2; i <= 31623; i++) {
		if (!sosu[i]) {
			vec.push_back(i);
			for (int j = 2; j*i <= 31623; j++) {
				sosu[i*j] = true;
			}
		}
	}
	ll ans = 1;
	scanf("%d %d %d", &n, &num, &last);
	for (int i = 1; i < n; i++) {
		scanf("%d", &x);
		if (x > last || last % x != 0) return !printf("0");
		tt.clear();
		tmp = last / x;
		prime(tmp);
		lm = num / x;
		lm += dfs(-1, 1);
		ans = (ans * lm) % mod;
		last = x;
	}
	printf("%lld", ans);

	return 0;
}