/*
BOJ 1068 (https://www.acmicpc.net/problem/1068)
*/
#include <cstdio>
#include <vector>
using namespace std;

vector<int> tree[51];
int cnt, x;
void search(int cur) {
	if (cur == x) return;
	int c = 0;
	for (int v : tree[cur]) {
		// ������ ���δ� ���� ����
		if (v == x) continue;
		search(v); c++;
	}
	// ���� ��尡 ���ٸ� �������
	if (c == 0) cnt++;
}
int main() {
	int n, root;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == -1) root = i;
		else tree[x].push_back(i);
	}
	scanf("%d", &x);
	search(root);
	printf("%d", cnt);

	return 0;
}