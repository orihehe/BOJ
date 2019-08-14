/*
BOJ 17307 - 색깔 통일하기
https://www.acmicpc.net/problem/17307
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[250001];
ll l[250001], r[250001];
vector<int> vec;
int main() {
	int n, c, idx;
	scanf("%d %d", &n, &c);
	arr[0] = 1000000001;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i - 1] != arr[i]) vec.push_back(i);
	}
	if (vec.size() == 1) {
		return !printf("1\n0");
	}
	int sz = vec.size();
	for (int i = 1; i < sz; i++) {
		l[vec[i]] = (arr[vec[i - 1]] + c - arr[vec[i]]) % c;
		l[vec[i]] += l[vec[i - 1]];
	}
	for (int i = sz - 2; i >= 0; i--) {
		r[vec[i]] = (arr[vec[i + 1]] + c - arr[vec[i]]) % c;
		r[vec[i]] += r[vec[i + 1]];
	}
	ll ans;
	if (l[vec[sz - 1]] < r[vec[0]]) {
		ans = l[vec[sz - 1]];
		idx = vec[sz - 1];
	}
	else {
		idx = vec[0];
		ans = r[vec[0]];
	}
	for (int i = 1; i < sz - 1; i++) {
		if (max(l[vec[i]], r[vec[i]]) < ans) {
			ans = max(l[vec[i]], r[vec[i]]);
			idx = vec[i];
		}
		else if (max(l[vec[i]], r[vec[i]]) == ans) {
			idx = min(idx, vec[i]);
		}
	}
	printf("%d\n%lld", idx, ans);

	return 0;
}