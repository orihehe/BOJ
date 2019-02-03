/*
BOJ 6142 (https://www.acmicpc.net/problem/6142)

비용을 최소로 해야하므로 x점수 이상일 때 얻을 수 있는 비용들을 map으로 관리한다.
그리고 x 점수인 소들의 최소 비용을 map에서 lower_bound로 찾으면 최소비용 이상중 최솟값이 나온다.
만약, 그 비용이 없다면 -1출력
*/
#include <cstdio>
#include <algorithm>
#include <map>
#define ll long long
#define pii pair<int,int>
using namespace std;

map <int, int> mp;
map <int, int> ::iterator iter;
pii cow[100001];
pii ggg[100001];
int gp;
bool cmp(pii &a, pii &b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}
int main() {
	int n, m;
	ll sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &cow[i].first, &cow[i].second);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &ggg[i].first, &ggg[i].second);
	}
	sort(cow, cow + n, cmp);
	sort(ggg, ggg + m, cmp);
	for (int i = 0; i < n; i++) {
		while (gp < m && ggg[gp].second >= cow[i].second) {
			mp[ggg[gp].first]++;
			gp++;
		}
		iter = mp.lower_bound(cow[i].first);
		if (iter == mp.end()) return !printf("-1");
		sum += iter->first;
		mp[iter->first]--;
		if (mp[iter->first] == 0) mp.erase(iter);
	}
	printf("%lld", sum);

	return 0;
}