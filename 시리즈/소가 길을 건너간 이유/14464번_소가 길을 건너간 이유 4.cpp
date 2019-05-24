/*
BOJ 14464 - 소가 길을 건너간 이유 4
https://www.acmicpc.net/problem/14464
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int arr[20001], cp, ap;
pii cow[20001];
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	int n, m, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < m; i++) scanf("%d %d", &cow[i].first, &cow[i].second);

	sort(arr, arr + n);
	sort(cow, cow + m);

	for (int i = 0; i < n; i++) {
		while (cp < m && cow[cp].first <= arr[i]) {
			pq.push(cow[cp++].second);
		}
		while (!pq.empty() && pq.top() < arr[i]) pq.pop();
		if (!pq.empty()) {
			pq.pop();
			ans++;
		}
	}
	printf("%d", ans);

	return 0;
}