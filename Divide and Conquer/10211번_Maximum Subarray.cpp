/*
BOJ 10211 - Maximum Subarray
https://www.acmicpc.net/problem/10211

분할정복 과정에서 중간에서부터 왼쪽, 오른쪽으로 퍼져나가며 
최댓값을 구해 더한값 중 최댓값을 출력해준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[1001], mx;
void dq(int l, int r) {
	if (l == r) {
		mx = max(mx, arr[l]);
		return;
	}
	int mid = (l + r) / 2;
	dq(l, mid);
	dq(mid + 1, r);
	int al= arr[mid], ar= arr[mid+1], le = 0, ri = 0, lp = mid, rp = mid+1;
	while (lp>=l) {
		le += arr[lp--];
		al = max(al, le);
	}
	while (rp<=r) {
		ri += arr[rp++];
		ar = max(ar, ri);
	}
	mx = max(mx, al + ar);
}
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		mx = -1001;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		dq(1, n);
		printf("%d\n", mx);
	}

	return 0;
}