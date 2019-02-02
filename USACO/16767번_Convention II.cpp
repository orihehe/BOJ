/*
BOJ 16767 (https://www.acmicpc.net/problem/16767)

소들을 우선 빨리 도착한 순으로 정렬한다.
현재 시간 이전에 도착한 소들을 큐에 넣어주고,
큐가 비어있다면 맨 앞소와 같은 시간에 도착한 소를 모두 넣는다.
현재 시간(ti)와 도착시간의 차이가 대기시간이 되니 그것의 최댓값을 출력
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