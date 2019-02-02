/*
BOJ 16767 (https://www.acmicpc.net/problem/16767)

�ҵ��� �켱 ���� ������ ������ �����Ѵ�.
���� �ð� ������ ������ �ҵ��� ť�� �־��ְ�,
ť�� ����ִٸ� �� �ռҿ� ���� �ð��� ������ �Ҹ� ��� �ִ´�.
���� �ð�(ti)�� �����ð��� ���̰� ���ð��� �Ǵ� �װ��� �ִ��� ���
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

struct cow {
	ll t, d, idx;
	bool operator <(const cow &a) const {
		return idx > a.idx;
	}
};
cow vec[100001];
int vp = 0;
ll n, maxT, ti;
bool cmp(cow &a, cow &b) {
	return a.t < b.t;
}
int main() {
	priority_queue<cow> pq;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &vec[i].t, &vec[i].d);
		vec[i].idx = i;
	}
	sort(vec, vec + n, cmp);

	while (!pq.empty() || vp<n) {
		if (pq.empty()) {
			ti = vec[vp].t;
			while (vp < n && vec[vp].t == ti) {
				pq.push(vec[vp++]);
			}
			continue;
		}
		cow nc = pq.top(); pq.pop();
		ti += nc.d;
		maxT = max(maxT, ti - nc.d - nc.t);
		while (vp<n && vec[vp].t <= ti) {
			pq.push(vec[vp++]);
		}
	}
	printf("%lld", maxT);

	return 0;
}