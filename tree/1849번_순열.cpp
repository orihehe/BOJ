/*
���� 1849 ���� (https://www.acmicpc.net/problem/1849)
Ʈ���� �� ��忡 �� ������ �ִ밪�� �����ߴ�.
������忡�� ó���� �� ���� -1 (2~2�̶�� 1) �� �����ߴ�. �� ��� �տ� �׸�ŭ�� ū ���� �ִٴ� ��!
x�� �Է¹޾� x�� ��� ��ġ���� ã�� �� �ε���(idx)�� ��ȯ�ߴ�. (find_num)
�׸��� idx+1~n���� �տ� ���κ��� ���� ���� �����Ƿ� -1�� ���ش�. �ִ񰪵� 1�� �پ���״� ��� ��带 �׳� -1 ���ָ� �ȴ�.

�ٸ� ��� Ǯ�̸� ���� ������忡 1�� �����ϰ� �� ���� �θ��忡 �����Ѵ�.
�׸��� ���� �����ڽ��� ���κ��� ū �� ���� ���϶�� ��������,
�� �ܿ� ���ʳ�常ŭ ���ְ� ���������� ����.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int *tree, *lazy;
int ans[100000];
int make_tree(int idx, int start, int end) {
	// ������忡 �ε���-1 -> �� ū�� ����
	if (start == end) {
		tree[idx] = start-1;
	}
	else {
		int mid = (start + end) / 2;
		// �ִ� ����
		tree[idx] = max(make_tree(idx * 2, start, mid),
			make_tree(idx * 2 + 1, mid + 1, end));
	}
	return tree[idx];
}
void change(int fs, int fe, int idx, int start, int end) {
	if (start > fe || end < fs) return;
	if (start != end && fs <= start && end <= fe) {
		lazy[idx] -= 1;
	}
	else {
		tree[idx] -= 1;
		if (start == end) return;
		int mid = (start + end) / 2;
		change(fs, fe, idx * 2, start, mid);
		change(fs, fe, idx * 2 + 1, mid + 1, end);
	}
}
int find_num(int k, int idx, int start, int end, int l) {
	if (start == end) {
		tree[idx] = -1;
		return start-1;
	}
	int tmp = l + lazy[idx];
	int mid = (start + end) / 2;
	if (k <= tree[idx * 2]+tmp) {
		return find_num(k, idx * 2, start, mid, tmp);
	}
	else {
		return find_num(k, idx * 2 + 1, mid + 1, end, tmp);
	}
}

int main() {
	int n, h, x, idx;
	scanf("%d", &n);
	h = ceil(log2(n)) + 1;
	tree = new int[1 << h];
	lazy = new int[1 << h];
	make_tree(1, 1, n);
	fill(lazy, lazy + (1 << h), 0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		idx = find_num(x, 1, 1, n, 0);
		ans[idx] = i;
		change(idx + 1, n, 1, 1, n);
	}
	for (int i = 0; i < n; i++) printf("%d\n", ans[i]);

	delete[] tree;
	delete[] lazy;

	return 0;
}