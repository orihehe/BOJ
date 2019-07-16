/*
BOJ 10167 - 금광
https://www.acmicpc.net/problem/10167

현재 노드의 왼쪽 최대합, 오른쪽 최대합, 전체합, 이 구간에서의 최댓값 정보를 저장
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
struct node {
	ll le, ri, al, mx;
} tree[8192];
struct info {
	int x, y, val;
	bool operator < (const info &a)const {
		return y < a.y;
	}
} arr[3001];
vector<int> xx;
int szz = 1;
void update(int idx, int val) {
	idx += szz;
	tree[idx].al += val;
	if (tree[idx].al >0)
		tree[idx].mx = tree[idx].ri = tree[idx].le = tree[idx].al;
	else tree[idx].mx = tree[idx].ri = tree[idx].le = 0;
	idx /= 2;
	while (idx) {
		tree[idx].le = max(tree[idx * 2].al + tree[idx * 2 + 1].le, tree[idx * 2].le);
		tree[idx].ri = max(tree[idx * 2].ri + tree[idx * 2 + 1].al, tree[idx * 2 + 1].ri);
		tree[idx].al = tree[idx * 2].al + tree[idx * 2 + 1].al;
		tree[idx].mx = max(max(tree[idx * 2].mx, tree[idx * 2 + 1].mx), max(tree[idx].le, tree[idx].ri));
		tree[idx].mx = max(tree[idx].mx, tree[idx * 2].ri + tree[idx * 2 + 1].le);
		idx /= 2;
	}
}
int main() {
	int n;
	ll ans = 0;
	scanf("%d", &n);
	while (szz < n) szz *= 2;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].val);
		xx.push_back(arr[i].x);
	}
	sort(arr, arr + n);
	sort(xx.begin(), xx.end());
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(xx.begin(), xx.end(), arr[i].x) - xx.begin();
		arr[i].x = idx;
	}
	for (int i = 0; i < n; i++) {
		if (i > 0 && arr[i].y == arr[i - 1].y) continue;
		memset(tree, 0, sizeof(tree));
		for (int j = i; j < n; j++) {
			update(arr[j].x, arr[j].val);
			if (j <n - 1 && arr[j].y == arr[j + 1].y) continue;
			ans = max(ans, tree[1].mx);
		}
	}
	printf("%lld", ans);

	return 0;
}