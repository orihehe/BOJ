/*
BOJ 1015 (https://www.acmicpc.net/problem/1015)
*/
#include <cstdio>
#include <algorithm>
#define P pair<int,int>
using namespace std;

int main() {
	int n;
	P arr[50];
	int ans[50];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		ans[arr[i].second] = i;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}