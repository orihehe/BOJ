/*
BOJ 17022 - Sleepy Cow Sorting
https://www.acmicpc.net/problem/17022

꼭 옮겨야 하는 애들 뒤는 정렬되어있으니 정렬된 정보를 세그에 넣고
현재 옮길 애를 꼭 옮길 애들만큼 뒤로 + 정렬된곳의 내 위치 만큼 옮기면 된다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[100001], tree[262145];
bool us[100001];
void update(int idx, int s, int e, int k) {
	if (k < s || k > e) return;
	tree[idx]++;
	if (s == e) return;
	update(idx * 2, s, (s + e) / 2, k);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k);
}
int hap(int idx, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r)
		+ hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n, cur = 1, last = 0, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	arr[n] = 100002;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] < arr[i + 1])
			last = i;
		else break;
	}
	// last 뒤부터는 정렬되어있음
	for (int i = last; i < n; i++) {
		update(1, 1, n, arr[i]);
	}
	x = last - 1;
	printf("%d\n", last);
	for (int i = 0; i < last; i++) {
		printf("%d ", x + hap(1, 1, n, 1, arr[i]));
		update(1, 1, n, arr[i]);
		x--;
	}

	return 0;
}