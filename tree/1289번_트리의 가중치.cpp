/*
BOJ 1289 (https://www.acmicpc.net/problem/1289)
나올 수 있는 경로 가중치의 합을 식으로 구한 후 묶어보면
현재 노드의 자식의 경로 가중치 * 현재에서 자식으로 가는 가중치 임을 볼 수 있다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
#define P pair<int,int>
#define mod 1000000007
using namespace std;

vector<P> vec[100001];
int parent[100001];
ll ans;
ll dfs(int cur) {
	int vcnt = 0;
	ll ret = 0; // cur에서 자식들로 가는 경로들의 합
	for (P &v : vec[cur]) { // 한 자식씩
		if (parent[cur] == v.first) continue;
		parent[v.first] = cur; vcnt++;
		ll re = dfs(v.first); // 한 자식에서 나올 경로 가중치 합
		// cur-자식으로 가는 가중치 + 자식의 경로 가중치 합 * cur-자식
		ll rr = (v.second*re + v.second) % mod; 
		ans = (ans + rr + rr * ret) % mod; // 이미 탐색한 자식들로 가는 경로를 더함
		ret = (ret + rr) % mod;  // 탐색한 자식들로 가는 경로의 가중치 합
	}
	if (vcnt == 0) return 0;
	return ret;
}
int main() {
	int n, a, b, c;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	dfs(1);
	printf("%lld", ans);

	return 0;
}