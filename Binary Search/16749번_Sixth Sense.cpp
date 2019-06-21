/*
BOJ 16749 - Sixth Sense
https://www.acmicpc.net/problem/16749

먼저 이 카드로 이길 수 있는 최대 승리 수를 구해둔다. (k)
그리고나서 이분탐색으로 현재 위치에 올 수 있는 가장 큰 수를 구해준다.
이 수를 쓸 수 있는지는 지금까지 승리 + 뒷부분 최대 승리가 k라면 가능
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int op[10001], my[10001], os;
int orr[5001], arr[5001], p[5001], sa[5001];
int find(int cur) {
	if (cur == p[cur])return cur;
	return p[cur] = find(p[cur]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
int main() {
	int n, k = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &orr[i]);
		op[orr[i]]++;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		p[i] = i;
		sa[i] = arr[i];
		my[arr[i]]++;
	}
	p[n] = n;
	sort(sa, sa + n);

	for (int i = 1; i <= 10000; i++) {
		int tt = min(os, my[i]);
		k += tt;
		os -= tt;
		os += op[i];
	}

	for (int i = 0; i < n; i++) {
		int tmp = lower_bound(sa, sa + n, orr[i] + 1) - sa;
		tmp = find(tmp);
		int l = tmp == n ? 0 : tmp, r = n - 1, mid, ans, aidx, sum;
		op[orr[i]]--;
		while (l <= r) {
			mid = (l + r) / 2;
			sum = 0;
			int idx = find(mid);
			if (idx == n) {
				r = mid - 1;
				continue;
			}
			my[sa[idx]]--;
			os = 0;
			for (int j = 1; j <= 10000; j++) {
				int tt = min(os, my[j]);
				sum += tt;
				os -= tt;
				os += op[j];
			}
			if (sum + (orr[i] < sa[idx]) == k) {
				aidx = idx, ans = sa[idx];
				l = mid + 1;
			}
			else r = mid - 1;
			my[sa[idx]]++;
		}
		k -= orr[i] < ans;
		my[ans]--;
		merge(aidx, aidx + 1);
		printf("%d ", ans);
	}

	return 0;
}