/*
백준 10999 구간 합 구하기 2 (https://www.acmicpc.net/problem/10999)
세그먼트 트리 + Lazy Propagation 문제 이다.
현재 트리 노드 구간이 바꿀 구간에 포함된다면 자식노드로 들어가서 하나하나 바꾸지 않고
lazy배열에 바꿀 값을 저장한 후 구간 합을 구하려 할 때 바꿔주는 방식이다.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

ll *tree, *lazy;
ll arr[1000001];
ll make_tree(int idx, int start, int end) {
	if (start == end) {
		tree[idx] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		tree[idx] = make_tree(idx * 2, start, mid) +
			make_tree(idx * 2 + 1, mid + 1, end);
	}
	return tree[idx];
}
void change(ll val, int fs, int fe, int idx, int start, int end) {
	if (start > fe || end < fs) return;
	// 현재 노드의 구간이 바꿀 구간에 완전 포함될 때
	if (start!=end && fs <= start && end <= fe) {
		lazy[idx] += val;
	}
	else {
		int ss = max(start, fs), ee = min(end, fe);
		tree[idx] += val * (ee - ss + 1);
		if (start == end) return;
		int mid = (start + end) / 2;
		change(val, fs, fe, idx * 2, start, mid);
		change(val, fs, fe, idx * 2 + 1, mid + 1, end);
	}
}
ll find_sum(int fs, int fe, int idx, int start, int end, ll l) {
	if (start > fe || end < fs) return 0;
	ll tmp = l;
	// 변경된 값이 있다면 tmp에 더해감
	if (lazy[idx] != 0) tmp += lazy[idx];
	if (fs <= start && end <= fe) {
		return tree[idx] + tmp * (end - start + 1);
	}
	int mid = (start + end) / 2;
	return find_sum(fs, fe, idx * 2, start, mid, tmp) +
		find_sum(fs, fe, idx * 2 + 1, mid + 1, end, tmp);
}

int main() {
	int n, m, k, h,a,b,c,d;
	scanf("%d %d %d", &n, &m, &k);
	h = ceil(log2(n))+1;
	tree = new ll[1 << h];
	lazy = new ll[1 << h];
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	make_tree(1, 1, n);
	fill(lazy, lazy + (1 << h), 0);
	for (int i = 0; i < m + k; i++) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d %d", &b, &c, &d);
			change(d, b, c, 1, 1, n);
		}
		else if (a == 2) {
			scanf("%d %d", &b, &c);
			printf("%lld\n", find_sum(b, c, 1, 1, n, 0));
		}
	}
	delete[] tree;
	delete[] lazy;

	return 0;
}