/*
BOJ 15745 - Snow Boots
https://www.acmicpc.net/problem/15745

s보다 큰 깊이가 연속해서 d개보다 많을 때 N까지 가는 것이 불가능하다.
s가 큰 것부터 봐주면서 s보다 큰 깊이들을 merge해준다.
해주면서 가장 긴 길이가 d보다 작다면 가능, 아니라면 불가능
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
struct bot {
	int d, s, idx;
	bool operator <(const bot &a) const {
		return d > a.d;
	}
};
vector<pii> vec;
vector<bot> boots;
int sz[100001], p[100001], ms = 0;
bool use[100001], ans[100001];

int find(int a) {
	if (a == p[a])return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	p[b] = a;
	sz[a] += sz[b];
	ms = max(ms, sz[a]);
}
int main() {
	int n, b, f, s, vp = 0;
	scanf("%d %d", &n, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d", &f);
		vec.push_back({ f,i });
		p[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < b; i++) {
		scanf("%d %d", &f, &s);
		boots.push_back({ f,s,i });
	}
	sort(vec.begin(), vec.end(), greater<pii>());
	sort(boots.begin(), boots.end());
	for (int i = 0; i < b; i++) {
		while (vp<n && vec[vp].first>boots[i].d) {
			use[vec[vp].second] = true;
			ms = max(ms, 1);
			if (use[vec[vp].second - 1]) merge(vec[vp].second - 1, vec[vp].second);
			if (use[vec[vp].second + 1]) merge(vec[vp].second + 1, vec[vp].second);
			vp++;
		}
		if (ms < boots[i].s) ans[boots[i].idx] = true;
		else ans[boots[i].idx] = false;
	}

	for (int i = 0; i < b; i++) {
		if (ans[i]) printf("1\n");
		else printf("0\n");
	}

	return 0;
}