/*
BOJ 17261 - 석유가 넘쳐흘러
https://www.acmicpc.net/problem/17261

현재 노드에 흘러올 수 있는 노드들을 구해준 뒤
시간을 이분탐색으로 구해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define pli pair<ll,int>
using namespace std;

/* 🐣🐥 */
int n;
pli w[262144];
ll arr[262144];
pli dfs(int cur) {
	if (cur * 2 > n) return w[cur] = { arr[cur],1 };
	pli le = dfs(cur * 2), ri = dfs(cur * 2 + 1);
	return w[cur] = { le.first + ri.first + arr[cur], le.second + ri.second };
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
	dfs(1);
	int l, r, mid, tt, ans;
	for (int i = 1; i <= n; i++) {
		l = 1, r = 200000000;
		vector<int> vec;
		ll tmp;
		tt = i;
		while (tt != 1) {
			if (tt % 2) vec.push_back(tt - 1);
			else vec.push_back(tt + 1);
			tt /= 2;
		}
		while (l <= r) {
			mid = (l + r) / 2;
			tmp = 1LL * mid * w[i].second - w[i].first;
			for (int v : vec) {
				tmp += max(1LL * 0, 1LL * mid*w[v].second - w[v].first);
				if (tmp >= 0) break;
			}
			if (tmp >= 0) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		printf("%d ", ans);
	}

	return 0;
}