/*
BOJ 6142 (https://www.acmicpc.net/problem/6142)

����� �ּҷ� �ؾ��ϹǷ� x���� �̻��� �� ���� �� �ִ� ������ map���� �����Ѵ�.
�׸��� x ������ �ҵ��� �ּ� ����� map���� lower_bound�� ã���� �ּҺ�� �̻��� �ּڰ��� ���´�.
����, �� ����� ���ٸ� -1���
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