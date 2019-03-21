/*
BOJ 15674 - 가로수
https://www.acmicpc.net/problem/15674

은행나무, 플라타너스별로 비용을 따로 관리
맨 처음 디자이너의 설정대로 merge후 최댓값(sum)을 저장하고
변동사항에따라 이전값과 바뀐값의 차이를 sum에 더해준다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pll pair<ll,ll>
using namespace std;

/* 🐣🐥 */
pll price[200001];
ll et[400001], pt[400001];
bool use[400001];
int p[400001];
int find(int a) {
	if (a == p[a])return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	et[a] += et[b];
	pt[a] += pt[b];
}
int main() {
	int n, m, cm, a, b;
	ll sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		scanf("%lld %lld", &price[i].first, &price[i].second);
		et[i] = price[i].first;
		pt[i] = price[i].second;
	}
	for (int i = n + 1; i <= n * 2; i++) p[i] = i;
	while (m--) {
		scanf("%d %d %d", &cm, &a, &b);
		if (cm == 0) {
			merge(a, b);
			merge(a + n, b + n);
		}
		else {
			merge(a, b + n);
			merge(a + n, b);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (use[find(i)]) continue;
		sum += min(et[find(i)]+pt[find(i+n)], et[find(i+n)]+pt[find(i)]);
		use[find(i)] = true;
		use[find(i + n)] = true;
	}
	printf("%lld\n", sum);
	ll before, after;
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d %d", &cm, &a, &b);
		before = min(et[find(a)] + pt[find(a + n)], et[find(a + n)] + pt[find(a)]);
		if (cm == 0) {
			if (find(a) != find(b))
				before += min(et[find(b)] + pt[find(b + n)], et[find(b + n)] + pt[find(b)]);
			merge(a, b);
			merge(a + n, b + n);
		}
		else if (cm == 1) {
			if (find(a+n) != find(b))
				before += min(et[find(b)] + pt[find(b + n)], et[find(b + n)] + pt[find(b)]);
			merge(a, b + n);
			merge(a + n, b);
		}
		else if (cm == 2) {
			et[find(a)] += b - price[a].first;
			price[a].first = b;
		}
		else {
			pt[find(a)] += b - price[a].second;
			price[a].second = b;
		}
		after = min(et[find(a)] + pt[find(a + n)], et[find(a + n)] + pt[find(a)]);
		sum += after - before;
		printf("%lld\n", sum);
	}

	return 0;
}