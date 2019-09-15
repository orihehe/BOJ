/*
BOJ 15410 - Cakey McCakeFace
https://www.acmicpc.net/problem/15410
*/
#include <cstdio>
#include <map>
using namespace std;

/* 🐣🐥 */
int arr[2001], aa[2001];
map<int, int> mp;
int main() {
	int n, m, mx = 0, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &aa[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (aa[j] >= arr[i]) mp[aa[j] - arr[i]]++;
		}
	}
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		if (iter->second > mx) {
			mx = iter->second;
			ans = iter->first;
		}
	}
	printf("%d", ans);

	return 0;
}