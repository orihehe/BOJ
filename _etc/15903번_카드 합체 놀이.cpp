/*
BOJ 15903 - 카드 합체 놀이
https://www.acmicpc.net/problem/15903

가장 작은 두 수를 계속 골라준다. 나온 결과도 후보에 포함,
*/
#include <cstdio>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

/* 🐣🐥 */
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main() {
	int n, x, k;
	ll a, b, ans = 0;
	scanf("%d %d", &n, &k);
	while (n--) {
		scanf("%d", &x);
		pq.push(x);
	}
	while (k--) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	printf("%lld", ans);

	return 0;
}