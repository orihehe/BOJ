/*
BOJ 11599 - Racing Gems
https://www.acmicpc.net/problem/11599

y = rx + c, y = -rx + c 의 범위의 gem을 먹을 수 있다.
한 기준으로 정렬 후 LIS 문제처럼 풀어주기.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define pll pair<ll,ll>
using namespace std;

/* 🐣🐥 */
pll arr[100001];
int n, r, w, h, tree[262145], ans, nb[100001], np;
vector<ll> vec;
void update(int idx, int s, int e, int k, int num) {
	if (s > k || e < k) return;
	if (s == e) {
		tree[idx] = max(tree[idx], num);
		return;
	}
	update(idx * 2, s, (s + e) / 2, k, num);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, num);
	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}
int getmx(int idx, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) {
		return tree[idx];
	}
	return max(getmx(idx * 2, s, (s + e) / 2, l, r),
		getmx(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
bool cmp(pll a, pll b) { // 마이너스 기울기
	if (r*a.first + a.second == r * b.first + b.second)
		return a.second > b.second;
	return r * a.first + a.second < r*b.first + b.second;
}
int main() {
	scanf("%d %d %d %d", &n, &r, &w, &h);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &arr[i].first, &arr[i].second);
		vec.push_back(arr[i].second - r * arr[i].first);
	}
	sort(arr, arr + n, cmp);
	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++) {
		ll tmp = arr[i].second - r * arr[i].first;
		tmp = upper_bound(vec.begin(), vec.end(), tmp) - vec.begin() - 1;
		int tt = getmx(1, 0, n-1, 0, (int)tmp);
		ans = max(ans, tt + 1);
		update(1, 0, n-1, (int)tmp, tt + 1);
	}
	printf("%d", ans);

	return 0;
}