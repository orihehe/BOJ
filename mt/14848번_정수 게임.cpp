/*
BOJ 14848 - 정수 게임
https://www.acmicpc.net/problem/14848

합집합을 잘 구해본다. 포함배제!
1,2,3,...개의 원소의 교집합을 빼고 더하는 것을 번갈아 하는 꼴로 나타남.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[16];
ll n, k, sum = 0, x = -1, tmp, cc;
ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	while (a > 0) {
		ll tmp = b;
		b = a;
		a = tmp % a;
	}
	return b;
}
void dfs(ll cur, ll cnt, ll cs) {
	if (cnt == cc) {
		tmp += n / cs;
		return;
	}
	if (cur == k) return;
	dfs(cur + 1, cnt + 1, cs*arr[cur] / gcd(cs, arr[cur]));
	dfs(cur + 1, cnt, cs);
}
int main() {
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%lld", &arr[i]);
		sum += n / arr[i];
	}
	for (int i = 2; i <= k; i++) {
		tmp = 0; cc = i;
		dfs(0, 0, 1);
		sum += x * tmp;
		x = -x;
	}
	printf("%lld", n - sum);

	return 0;
}