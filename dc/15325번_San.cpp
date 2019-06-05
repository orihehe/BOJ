/*
BOJ 15325 - San
https://www.acmicpc.net/problem/15325

n을 두 그룹으로 나누어준뒤, 앞 그룹은 i높이에서 끝나는 경우들을,
뒤의 그룹은 i높이에서 시작하는 경우들을 모두 구해 저장해둔다.
그리고나서 높이별로 lower_bound로 가능한 개수를 구해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define pil pair<int,ll>
using namespace std;

/* 🐣🐥 */
pil arr[41];
int n;
ll k, ans;
vector<ll> hh[41];
void go(int ii, int cur, int h, ll sum) {
	if (cur == 0) {
		hh[ii].push_back(sum);
		if (sum >= k) ans++;
		return;
	}
	if (h >= arr[cur - 1].first) {
		go(ii, cur - 1, arr[cur - 1].first, sum + arr[cur - 1].second);
	}
	go(ii, cur - 1, h, sum);
}
void go2(int ii, int cur, int h, ll sum) {
	if (cur == n-1) {
		hh[ii].push_back(sum);
		if (sum >= k) ans++;
		return;
	}
	if (h <= arr[cur + 1].first) {
		go2(ii, cur + 1, arr[cur + 1].first, sum + arr[cur + 1].second);
	}
	go2(ii, cur + 1, h, sum);
}
int main() {
	scanf("%d %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %lld", &arr[i].first, &arr[i].second);
	}
	for (int i = n / 2 - 1; i >= 0; i--) {
		go(i, i, arr[i].first, arr[i].second);
	}
	for (int i = 0; i < n / 2; i++) {
		sort(hh[i].begin(), hh[i].end());
	}
	for (int i = n / 2; i < n; i++) {
		go2(i, i, arr[i].first, arr[i].second);
	}
	for (int i = n / 2; i < n; i++) {
		for (ll v : hh[i]) {
			for (int j = 0; j < n / 2; j++) {
				if (arr[j].first <= arr[i].first) {
					ans += hh[j].end()
						- lower_bound(hh[j].begin(), hh[j].end(), k - v);
				}
			}
		}
	}

	printf("%lld", ans);

	return 0;
}