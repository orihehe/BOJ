/*
BOJ 2887 - 행성 터널
https://www.acmicpc.net/problem/2887

x,y,z기준으로 정렬 뒤 연속한 정점의 간선만 봐준다.
비용이 min(|xA-xB|, |yA-yB|, |zA-zB|) 이기 때문에 정점당 가까운 x,y,z만 봐주면 됨
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
struct loc {
	int x, y, z, idx;
}arr[100001];
struct node {
	int v1, v2, val;
	bool operator<(const node &a)const {
		return val < a.val;
	}
};
vector<node> vec;
int p[100001], n;
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
long long kru() {
	int cnt = 0;
	long long ret = 0;
	sort(vec.begin(), vec.end());
	for (node v : vec) {
		if (find(v.v1) != find(v.v2)) {
			merge(v.v1, v.v2);
			cnt++;
			ret += v.val;
		}
		if (cnt == n - 1) break;
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].z);
		p[i] = arr[i].idx = i;
	}
	sort(arr, arr + n, [](loc a, loc b) {
		return a.x < b.x;
	});
	for (int i = 1; i < n; i++) {
		vec.push_back({ arr[i].idx,arr[i - 1].idx,abs(arr[i].x - arr[i - 1].x) });
	}
	sort(arr, arr + n, [](loc a, loc b) {
		return a.y < b.y;
	});
	for (int i = 1; i < n; i++) {
		vec.push_back({ arr[i].idx,arr[i - 1].idx,abs(arr[i].y - arr[i - 1].y) });
	}
	sort(arr, arr + n, [](loc a, loc b) {
		return a.z < b.z;
	});
	for (int i = 1; i < n; i++) {
		vec.push_back({ arr[i].idx,arr[i - 1].idx,abs(arr[i].z - arr[i - 1].z) });
	}
	printf("%lld", kru());

	return 0;
}