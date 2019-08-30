/*
BOJ 17421 - 빗물이 넘쳐흘러
https://www.acmicpc.net/problem/17421
*/
#include <cstdio>
#include <stack>
#define ll long long
using namespace std;

/* 🐣🐥 */
struct info {
	int num, h;
	ll val;
};
int arr[100001];
stack<info> sta;
int main() {
	int n, k, x, cnt = 0;
	ll ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sta.push({ 0,0,0 });
	for (int i = 0; i <= n; i++) {
		x = arr[i];
		if (x == sta.top().h) {
			sta.top().num++;
			continue;
		}
		info tmp = { 1, x, 0 };
		if (x < sta.top().h && sta.top().val == 0 && cnt + 1 == k) {
			while (!sta.empty()) {
				ans += sta.top().val;
				sta.pop();
			}
			return !printf("%lld", ans);
		}
		if (x < sta.top().h)
			cnt++;
		while (x < sta.top().h) {
			info cur = sta.top();
			sta.pop();
			if (cur.val > 0) cnt--;
			tmp.val += cur.val + 1LL * cur.num *(cur.h - x);
			tmp.num += cur.num;
		}
		sta.push(tmp);
	}
	printf("-1");

	return 0;
}