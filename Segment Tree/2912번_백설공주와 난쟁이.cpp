/*
BOJ 2912 - 백설공주와 난쟁이
https://www.acmicpc.net/problem/2912

머지소트트리로 색으로 정렬된 상태로 그 색이 몇 번 등장하는지 저장해둔다.
그러고나서 구하고 싶은 구간에 포함되는 세그의 인덱스를 뽑아와서
각 구간에서 가장 많이 등장하는 수를 답 후보로 두고 세준 값이 절반 초과인지 확인해준다.

만약 어떤 수가 모든 구간에서 반 이하로 등장한다면 그 수가 정답이 될 수가 없기 때문이다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int arr[300001], mx[10484576];
vector<pii> tree[1048576];
vector<int> ii;
void init(int idx, int s, int e) {
	if (s == e) {
		mx[idx] = arr[s];
		tree[idx].push_back({ arr[s],1 });
		return;
	}
	init(idx * 2, s, (s + e) / 2);
	init(idx * 2 + 1, (s + e) / 2 + 1, e);
	int rsz = tree[idx * 2 + 1].size(), rr = idx * 2 + 1;
	int rp = 0, fst = 0;
	for (pii v : tree[idx * 2]) {
		while (rp < rsz && tree[rr][rp].first < v.first) {
			tree[idx].push_back(tree[rr][rp]);
			if (tree[idx].back().second > fst) {
				fst = tree[idx].back().second;
				mx[idx] = tree[idx].back().first;
			}
			rp++;
		}
		if (rp < rsz && tree[rr][rp].first == v.first) {
			tree[idx].push_back({ v.first,v.second + tree[rr][rp].second });
			rp++;
		}
		else tree[idx].push_back(v);

		if (tree[idx].back().second > fst) {
			fst = tree[idx].back().second;
			mx[idx] = tree[idx].back().first;
		}
	}
	while (rp < rsz) {
		tree[idx].push_back(tree[rr][rp]);
		if (tree[idx].back().second > fst) {
			fst = tree[idx].back().second;
			mx[idx] = tree[idx].back().first;
		}
		rp++;
	}
}
void find(int idx, int s, int e, int l, int r) {
	if (e < l || r < s) return;
	if (l <= s && e <= r) {
		ii.push_back(idx);
		return;
	}
	find(idx * 2, s, (s + e) / 2, l, r);
	find(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n, c, m, a, b;
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	init(1, 1, n);
	scanf("%d", &m);
	while (m--) {
		ii.clear();
		scanf("%d %d", &a, &b);
		find(1, 1, n, a, b);
		sort(ii.begin(), ii.end());
		int hubo[40], hp = 0;
		for (int v : ii) {
			hubo[hp++] = mx[v];
		}
		bool suc = false;
		for (int i = 0; i < hp; i++) {
			int sum = 0;
			for (int v : ii) {
				int ix = lower_bound(tree[v].begin(), tree[v].end(), pii(hubo[i], 0)) - tree[v].begin();
				if (ix < tree[v].size() && tree[v][ix].first == hubo[i])
					sum += tree[v][ix].second;
			}
			if (sum >(b - a + 1) / 2) {
				printf("yes %d\n", hubo[i]);
				suc = true;
				break;
			}
		}
		if (!suc) printf("no\n");
	}

	return 0;
}