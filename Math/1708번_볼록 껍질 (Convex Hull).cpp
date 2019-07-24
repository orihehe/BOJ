/*
BOJ 1708 - 볼록 껍질
https://www.acmicpc.net/problem/1708
*/
#include <cstdio>
#include <algorithm>
#include <stack>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[100001];
stack<int> sta;
ll ccw(pii a, pii b, pii c) {
	return 1LL * (a.first - c.first) * (b.second - c.second)
		- 1LL * (b.first - c.first) *(a.second - c.second);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + n);
	sort(arr + 1, arr + n, [](pii a, pii b) {
		if (1LL * (a.first - arr[0].first) * (b.second - arr[0].second) !=
			1LL * (b.first - arr[0].first)*(a.second - arr[0].second))
			return 1LL * (a.first - arr[0].first) * (b.second - arr[0].second)
			< 1LL * (b.first - arr[0].first)*(a.second - arr[0].second);
		if (a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	});
	sta.push(0), sta.push(1);
	for (int i = 2; i < n; i++) {
		while (sta.size() >= 2) {
			int ff = sta.top();
			sta.pop();
			int ss = sta.top();
			if (ccw(arr[ss], arr[i], arr[ff]) > 0) {
				sta.push(ff);
				break;
			}
		}
		sta.push(i);
	}
	printf("%d", sta.size());

	return 0;
}