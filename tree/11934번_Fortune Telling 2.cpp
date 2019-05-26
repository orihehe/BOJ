/*
BOJ 11934 - Fortune Telling 2
https://www.acmicpc.net/problem/11934

양면 중 작은 값 mn, 큰 값 mx
mn이상, mx미만의 t가 존재한다면 가장 마지막 등장 후의 mx이상의 t 등장 횟수(cnt)를 세어준다.
마지막 등장시점에 카드의 면은 무조건 mx값, cnt에 따라 더해주면 된다.

mn이상, mx미만의 t가 존재하지 않는다면 전체 구간의 mx이상의 t 등장 횟수를 세서
앞면 뒷면을 판별해준다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[200001], q[200001];
// mxi는 수 범위에서의 인덱스 max를 관리
// tree는 mx이상의 개수를 세줄건데, 그러기 위해 max가 큰 값부터 봐주며 넣어준다.
int mxi[524289], tree[524289], p; 
bool cmp(pii &a, pii &b) {
	return max(a.first, a.second) > max(b.first, b.second);
}
void init(int idx, int s, int e) {
	if (s == e) {
		mxi[idx] = q[s].second;
		return;
	}
	init(idx * 2, s, (s + e) / 2);
	init(idx * 2 + 1, (s + e) / 2 + 1, e);
	mxi[idx] = max(mxi[idx * 2], mxi[idx * 2 + 1]);
}
void update(int idx, int s, int e, int k) {
	if (k<s || k>e) return;
	tree[idx]++;
	if (s == e) return;
	update(idx * 2, s, (s + e) / 2, k);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k);
}
int geti(int idx, int s, int e, int l, int r) {
	if (e<l || s >r) return 0;
	if (l <= s && e <= r) return mxi[idx];
	return max(geti(idx * 2, s, (s + e) / 2, l, r),
		geti(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int hap(int idx, int s, int e, int l, int r) {
	if (e<l || s >r) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r) +
		hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n, k;
	ll ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &q[i].first);
		q[i].second = i;
	}

	sort(arr + 1, arr + n + 1, cmp);
	sort(q + 1, q + k + 1);
	init(1, 1, k);
	p = k;
	for (int i = 1; i <= n; i++) {
		int mn = min(arr[i].first, arr[i].second), mx = max(arr[i].first, arr[i].second);
		while (p > 0 && q[p].first >= mx) {
			update(1, 1, k, q[p--].second);
		}
		int s = lower_bound(q + 1, q + k + 1, pii(mn, -1)) - q;
		int e = upper_bound(q + 1, q + k + 1, pii(mx - 1, k)) - q - 1;
		int srt = 0, cnt = 0;
		if (s <= e) srt = geti(1, 1, k, s, e);
		if (srt + 1 <= k) cnt = hap(1, 1, k, srt + 1, k);

		if (srt == 0) {
			if (cnt % 2) ans += arr[i].second;
			else ans += arr[i].first;
		}
		else {
			if (cnt % 2) ans += mn;
			else ans += mx;
		}
	}
	printf("%lld", ans);

	return 0;
}