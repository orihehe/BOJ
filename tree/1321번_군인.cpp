/*
���� 1321 ���� (https://www.acmicpc.net/problem/1321)
���� ����� �����ڽ� ���� ���Ϸ��� ���� �̻��̶�� �� ������ ���� ������ ��ġ���� ���̴�.
�����ڽ� ���� �۴ٸ� �� ������ �������� �����ڽ� ����ŭ ���־� ���������� �Ѱ��ش�. 
�����ڽ� ����ŭ �� ������ �� ������ ���� �����̴�.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

int *tree;
int arr[500001];
int make_tree(int idx, int start, int end) {
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
void change(int val, int k, int idx, int start, int end) {
	if (start > k || end < k) return;
	else {
		tree[idx] += val;
		if (start == end) return;
		int mid = (start + end) / 2;
		change(val, k, idx * 2, start, mid);
		change(val, k, idx * 2 + 1, mid + 1, end);
	}
}
int find_loc(int k, int idx, int start, int end) {
	if (start == end) return start;

	int mid = (start + end) / 2;
	if (tree[idx * 2] >= k) 
		return find_loc(k, idx * 2, start, mid);
	else 
		return find_loc(k-tree[idx*2], idx * 2 + 1, mid + 1, end);
}

int main() {
	int n, h, m, cm, a, b;
	scanf("%d", &n);
	h = ceil(log2(n)) + 1;
	tree = new int[1 << h];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	make_tree(1, 1, n);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &cm);
		if (cm == 1) {
			scanf("%d %d", &a, &b);
			change(b, a, 1, 1, n);
		}
		else if (cm == 2) {
			scanf("%d", &a);
			printf("%d\n", find_loc(a, 1, 1, n));
		}
	}

	delete[] tree;

	return 0;
}