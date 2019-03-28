/*
BOJ 17027 - Shell Game
https://www.acmicpc.net/problem/17027
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int cnt[4] = { 0,0,0,0 };
int main() {
	int n, a, b, c;
	int arr[4] = { 0,1,2,3 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		swap(arr[a], arr[b]);
		cnt[arr[c]]++;
	}
	printf("%d", max({ cnt[1],cnt[2],cnt[3] }));

	return 0;
}