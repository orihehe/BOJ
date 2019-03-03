/*
BOJ 1517 - 버블 소트
https://www.acmicpc.net/problem/1517

swap횟수는 제자리보다 뒤에 있는 원소가 제자리로 가는 거리의 합이다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[500001],tmp[500001];
ll cnt;
void merge(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	merge(l, mid);	
	merge(mid + 1, r);
	int ap = l, bp = mid + 1, tp = l;
	while (ap <= mid && bp <= r) {
		if (arr[bp] < arr[ap]) {
			cnt += bp - tp;
			tmp[tp++] = arr[bp++];
		}
		else tmp[tp++] = arr[ap++];
	}
	while (ap <= mid) tmp[tp++] = arr[ap++];
	while (bp <= r) tmp[tp++] = arr[bp++];
	for (int i = l; i <= r; i++) arr[i] = tmp[i];
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	merge(1, n);
	printf("%lld", cnt);

	return 0;
}