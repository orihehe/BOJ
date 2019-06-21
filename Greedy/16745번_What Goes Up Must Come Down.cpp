/*
BOJ 16745 - What Goes Up Must Come Down
https://www.acmicpc.net/problem/16745

작은 원소부터 봐주는데, 같은 원소가 있다면 양 끝 두 원소를 먼저 봐준다.
최종 나오는 꼴은 양 옆에서부터 중간까지 오름차순이니
원소별로 양쪽 중 가까운 쪽으로 배치해준다.
*/
#include <cstdio>
#include <map>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[100001], tree[262144];
int n, mx, ii, lsum, rsum;
void update(int idx, int s, int e, int k, int val) {
	if (k<s || k>e) return;
	tree[idx] += val;
	if (s == e) return;
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
}
int hap(int idx, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r)
		+ hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
struct A {
	int val, idx;
	bool operator <(const A &a)const {
		if (val == a.val) return idx > a.idx;
		return val > a.val;
	}
};
priority_queue<A> le;
vector<A> vec;
int main() {
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		update(1, 0, n - 1, i, 1);
		scanf("%d", &arr[i]);
		le.push({ arr[i],i });
	}
	int lp, rp;
	while (!le.empty()) {
		bool flag = false;
		int ttt = le.top().val, locl, locr;
		vec.clear();
		while (!le.empty() && le.top().val == ttt) {
			vec.push_back(le.top());
			le.pop();
		}
		lp = 0, rp = vec.size() - 1;

		while (lp <= rp) {
			// 왼쪽에 이미 배치된 원소 수 + 왼쪽에 있는 나의 수 이상인 수의 개수가 현재 위치
			locl = lsum + hap(1, 0, n - 1, 0, vec[lp].idx) - 1;
			locr = lsum + hap(1, 0, n - 1, 0, vec[rp].idx) - 1;

			if (n - 1 - rsum - locr < locl - lsum) {
				ans += n - 1 - rsum - locr;
				update(1, 0, n - 1, vec[rp].idx, -1);
				rp--;
				rsum++;
			}
			else {
				ans += locl - lsum;
				update(1, 0, n - 1, vec[lp].idx, -1);
				lp++;
				lsum++;
			}
		}
	}
	printf("%lld", ans);

	return 0;
}