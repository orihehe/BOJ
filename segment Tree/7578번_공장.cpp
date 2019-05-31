/*
���� 7578 ���� (https://www.acmicpc.net/problem/7578)
�� ���̺� a,b�� �����Ϸ��� aA < bA && aB > bB �̰ų� aA > bA && aB < bB ���� �Ѵ�.
���� A�� B�� �������� ���̺��� ���ʷ� �����Ͽ� ���� ������ �ϳ��� ����ϸ� �ȴ�.
B���� i��° ���̺��� ������ �� i��°�� A������ j �̻� ����� ���̺� ���� ���� �ȴ�.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

int *tree, idx[1000001], arr[500001];
void change(int k, int idx, int start, int end) {
	if (start > k || end < k) return;
	tree[idx]++;
	if (start == end) return;
	int mid = (start + end) / 2;
	change(k, idx * 2, start, mid);
	change(k, idx * 2 + 1, mid + 1, end);
}
int find_sum(int fs, int fe, int idx, int start, int end) {
	if (start > fe || end < fs) return 0;
	if (fs <= start && end <= fe) {
		return tree[idx];
	}
	int mid = (start + end) / 2;
	return find_sum(fs, fe, idx * 2, start, mid) +
		find_sum(fs, fe, idx * 2 + 1, mid + 1, end);
}

int main() {
	int n, h, x;
	ll sum = 0;
	scanf("%d", &n);
	h = ceil(log2(n))+1;
	tree = new int [1 << h];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		idx[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x); 
		arr[i] = idx[x];
	}
	fill(tree, tree + (1 << h), 0);
	for (int i = 1; i <= n; i++) {
		// ������ arr[i]~n�� ����� ���̺� �� ����
		sum += (ll)find_sum(arr[i], n, 1, 1, n);
		// arr[i]��° ���̺� ����
		change(arr[i], 1, 1, n);
	}
	printf("%lld", sum);
	delete[] tree;

	return 0;
}