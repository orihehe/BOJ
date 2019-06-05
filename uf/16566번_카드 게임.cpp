/*
BOJ 16566 - 카드 게임
https://www.acmicpc.net/problem/16566

lower_bound로 현재 수+1의 위치를 찾고,
유니온 파인드로 현재 수를 사용 하고 나서 더 큰수들중 가장 작은 값과 연결해준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[4000000], ans[10000], p[4000000];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
int main() {
	int n, m, k, x;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		p[i] = i;
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + m);
	for (int i = 0; i < k; i++) {
		scanf("%d", &x);
		int idx = lower_bound(arr, arr + m, x + 1) - arr;
		idx = find(idx);
		printf("%d\n", arr[find(idx)]);
		merge(idx, idx + 1);
	}

	return 0;
}