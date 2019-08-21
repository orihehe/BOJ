/*
BOJ 17395 - 이진수
https://www.acmicpc.net/problem/17395
*/
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
vector<int> vec;
int main() {
	ll x, tmp;
	int n, cnt = 0;
	scanf("%lld %d", &x, &n);
	tmp = x;
	while (x > 0) {
		vec.push_back(x % 2);
		if (x % 2) cnt++;
		x /= 2;
	}
	if (cnt < n) return !printf("-1");
	n--;
	int sz = vec.size();
	for (int i = sz - 1; i >= 0; i--) {
		if (!n) break;
		if (vec[i]) {
			n--;
			tmp ^= 1LL << i;
			printf("%lld ", tmp);
		}
	}
	printf("0");

	return 0;
}