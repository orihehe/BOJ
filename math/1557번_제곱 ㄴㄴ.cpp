/*
BOJ 1557 - 제곱 ㄴㄴ
https://www.acmicpc.net/problem/1557

소수의 제곱수로만 판별할 수 있다.
ex) 6^2 -> 2^2 * 3^3 등등 소수 구성으로 바꿀 수 있음

이분탐색으로 수를 정해두고 그 수 이하의 제곱수를 세서 k번째 제곱 ㄴㄴ수를 구한다.
*/
#include <cstdio>
#include <vector>
#define ll long long
#define MAX 2000000000
using namespace std;

/* 🐣🐥 */
int lm, mx;
ll k, l, r, mid, tmp, cc, ans;
vector<ll> vec;
bool use[100001];
ll dfs(int cur, ll sum) {
	ll ret = 0;
	if (cur != -1) {
		sum *= vec[cur];
		ret = mid / sum;
	}
	for (int i = cur + 1; i <= lm; i++) {
		if (sum*vec[i] > mid) break;
		ret -= dfs(i, sum);
	}
	return ret;
}
int main() {
	scanf("%lld", &k);
	for (int i = 2; i <= 44722; i++) {
		if (!use[i]) {
			vec.push_back((ll)i*i);
			for (int j = 2; j*i <= 44722; j++) {
				use[j*i] = true;
			}
		}
	}
	l = 1, r = MAX;

	while (l <= r) {
		mid = (l + r) / 2;
		for (int i = 0; i < vec.size(); i++) {
			if (mid / vec[i] == 0) break;
			lm = i;
		}
		tmp = dfs(-1, 1);
		if (k <= mid + tmp) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	printf("%lld", ans);

	return 0;
}