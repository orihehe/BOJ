/*
백준 1849 순열 (https://www.acmicpc.net/problem/1849)
트리의 각 노드에 그 구간의 최대값을 저장했다.
리프노드에는 처음에 각 범위 -1 (2~2이라면 1) 을 저장했다. 그 노드 앞에 그만큼의 큰 수가 있다는 뜻!
x를 입력받아 x가 어디에 위치한지 찾고 그 인덱스(idx)를 반환했다. (find_num)
그리고 idx+1~n까지 앞에 본인보다 작은 수가 들어갔으므로 -1을 해준다. 최댓값도 1씩 줄어들테니 모든 노드를 그냥 -1 해주면 된다.

다른 사람 풀이를 보니 리프노드에 1씩 저장하고 그 합을 부모노드에 저장한다.
그리고 만약 왼쪽자식이 본인보다 큰 수 개수 이하라면 왼쪽으로,
그 외엔 왼쪽노드만큼 빼주고 오른쪽으로 간다.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int *tree, *lazy;
int ans[100000];
int make_tree(int idx, int start, int end) {
	// 리프노드에 인덱스-1 -> 앞 큰수 개수
	if (start == end) {
		tree[idx] = start-1;
	}
	else {
		int mid = (start + end) / 2;
		// 최댓값 저장
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