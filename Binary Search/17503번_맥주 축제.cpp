/*
BOJ 17503 - 맥주 축제
https://www.acmicpc.net/problem/17503
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[200001];
int main() {
	int n, m, k, a, b;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		arr[i] = { a,b };
	}
	sort(arr, arr + k, [](pii a, pii b) {
		return a.second < b.second;
	});
	int l = 0, r = k - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		int sum = 0;
		vector<int> vec;
		vec.reserve(mid + 1);
		for (int i = 0; i <= mid; i++) {
			vec.push_back(arr[i].first);
		}
		sort(vec.begin(), vec.end(), greater<int>());
		int lm = min(mid, n - 1);
		for (int i = 0; i <= lm; i++) sum += vec[i];

		if (sum >= m && mid >= n - 1) {
			r = mid - 1;
			ans = arr[mid].second;
		}
		else l = mid + 1;
	}
	printf("%d", ans);

	return 0;
}