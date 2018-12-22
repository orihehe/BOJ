/*
백준 1321 군인 (https://www.acmicpc.net/problem/1321)
현재 노드의 왼쪽자식 값이 구하려는 군번 이상이라면 이 군인은 왼쪽 구간에 배치받을 것이다.
왼쪽자식 값이 작다면 이 군인의 군번에서 왼쪽자식 값만큼 빼주어 오른쪽으로 넘겨준다. 
왼쪽자식 값만큼 앞 군번이 그 구간에 들어가기 때문이다.
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