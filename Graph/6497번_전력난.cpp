/*
BOJ 6497 - 전력난
https://www.acmicpc.net/problem/6497
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
struct info {
	int x, y, v;
	bool operator < (const info &a) const {
		return v < a.v;
	}
};
vector<info> edge;
int p[200001];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
int main() {
	int m, n, a, b, c, sum, ans;
	while (scanf("%d %d", &m, &n)) {
		if (m == 0 && n == 0) break;
		edge.clear();
		sum = ans = 0;
		for (int i = 0; i < m; i++) p[i] = i;
		while (n--) {
			scanf("%d %d %d", &a, &b, &c);
			sum += c;
			edge.push_back({ a,b,c });
		}
		sort(edge.begin(), edge.end());
		for (info &a : edge) {
			if (find(a.x) != find(a.y)) {
				merge(a.x, a.y);
				ans += a.v;
			}
		}
		printf("%d\n", sum - ans);
	}

	return 0;
}