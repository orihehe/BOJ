/*
���� 15586 MooTube (Gold) (https://www.acmicpc.net/problem/15586) 
���� v�� ���� ���� �� ���絵�� k�̻��� ������� �� ������ ���ϴ� �����̴�.
���絵�� �ٸ� �������� ���� ����� ������ �� �ּڰ��̴�.
e�迭�� ���� ������ ���� �� �������� ����, Q�迭�� k,v,���� ���� ���� �� k�� ���� �������� ����
��������ġ�� k�̻��� ���� �����ϴµ� Q�迭�� k �������� ���� �����Ƿ� �տ��� �̹� ������ �� �����ϰ� k'�̻��� ������ �߰��� ���� �ȴ�.
��Ʈ�� ��� Ǯ���µ� ���Ϸ��� ������ �����صΰ� �����Ͽ� Ǫ�� ����� ó�� �غõ�. �������� ������� �θ��ٰ� �ϴµ� �Ź��Ѱ� ����.
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#define P pair<int,int>
using namespace std;

struct edge {
	int val, a, b;
};
bool operator < (edge& e1, edge& e2) {
	return e1.val < e2.val;
}
struct cmd {
	int val, avi, idx;
};
bool operator <(cmd& c1, cmd& c2) {
	return c1.val > c2.val;
}

int q, a, b, r, n;
edge e[100000];
cmd Q[100001];
int parent[100001];
int w[100001];
int ans[100001];

int find_root(int cur) {
	if (parent[cur] == cur) return cur;
	return parent[cur] = find_root(parent[cur]);
}

void merge(int v1, int v2) {
	v1 = find_root(v1);
	v2 = find_root(v2);

	parent[v1] = v2;
	w[v2] += w[v1];
}

void kruskal() {
	int lastUSA=n-2;
	int i;
	for (i = 1; i <= n; i++) {
		parent[i] = i;
		w[i] = 1;
	}
	for (int j = 0; j < q; j++) {
		for (i = lastUSA; e[i].val>=Q[j].val && i>=0; i--) {
			merge(e[i].a, e[i].b);
		}
		ans[Q[j].idx] = w[find_root(Q[j].avi)]-1;
		lastUSA = i;
	}
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &r);
		e[i] = { r,a,b };
	}
	sort(e, e + n - 1);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &a, &b);
		Q[i] = { a,b,i };
	}
	sort(Q, Q + q);
	kruskal();
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}