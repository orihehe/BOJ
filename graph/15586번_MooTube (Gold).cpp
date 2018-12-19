/*
백준 15586 MooTube (Gold) (https://www.acmicpc.net/problem/15586) 
영상 v를 보고 있을 때 유사도가 k이상인 영상들이 몇 개인지 구하는 문제이다.
유사도는 다른 영상으로 가는 경로의 간선들 중 최솟값이다.
e배열에 간선 정보를 저장 후 오름차순 정렬, Q배열에 k,v,구할 순서 저장 후 k에 대해 내림차순 정렬
간선가중치가 k이상인 것을 선택하는데 Q배열을 k 내림차순 정렬 했으므로 앞에서 이미 선택한 것 제외하고 k'이상의 간선을 추가로 고르면 된다.
힌트를 듣고 풀었는데 구하려는 정보를 저장해두고 정렬하여 푸는 방법은 처음 해봤디. 오프라인 쿼리라고 부른다고 하는데 신박한거 같다.
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