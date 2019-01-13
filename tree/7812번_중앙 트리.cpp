/*
BOJ 7812 (https://www.acmicpc.net/problem/7812)
�켱 0�� ��Ʈ�� �ΰ� init���� 0������ ��� ������ ��� ��(sum)�� ���Ѵ�.
�� �� dfs �Լ����� �ڽ����� �������鼭 ���ص� sum�� �̿��� �� �ڽĿ����� ��� ������ ��� ���� �����ش�.
���� ��忡�� �ڽ����� �������鼭 � ���� ���ϴ� ���� �����غ���
cur-�ڽ��� �մ� ����ġ�� x�� �θ� �������鼭 �ڽĵ� �� * x��ŭ �����ϰ�, 
������(n-1)���� cur�� �ڽ��� �մ� ����1�� ����, (n-2-�ڽĵ� ��) * x��ŭ �����Ѵ�.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
#define P pair<ll,ll>
using namespace std;

vector<P> vec[10001];
P parent[10001];
ll ans, n;
// init���� cur�� �ڽ� ���� cur���� �ڽ����� ���� ����� ���� ����.
ll init(ll cur) {
	ll vcnt = 0;
	ll sum = 0;
	for (P &v : vec[cur]) {
		if (parent[cur].first == v.first) continue;
		parent[v.first].first = cur, vcnt++;
		// v�ڽ����� ���� ����� cur-v�� ����ġ * (v�ڽ� �� + 1)
		sum += v.second + init(v.first); // v������ �� + v-cur
		sum += v.second*parent[v.first].second; // v-cur * v�ڽļ�
		// ���� ��� �ڽ� ���� �� �ڽļ� + �� �ڽ��� �ڽļ��� ���Ѱ�
		vcnt += parent[v.first].second; 
	}
	parent[cur].second = vcnt; // �ڽ� ��� �� ����
	return sum;
}
void dfs(ll cur, ll sum) {
	ans = min(ans, sum);
	for (P &v : vec[cur]) {
		if (parent[cur].first == v.first) continue;
		dfs(v.first, sum - v.second*parent[v.first].second * 2
			+ v.second*(n - 2));
	}
}
int main() {
	ll a, b, c;
	while (scanf("%lld", &n)) {
		if (n == 0) break;
		ans = 987987987987987987;
		for (int i = 1; i < n; i++) {
			scanf("%lld %lld %lld", &a, &b, &c);
			vec[a].push_back({ b,c });
			vec[b].push_back({ a,c });
		}
		dfs(0, init(0));
		printf("%lld\n", ans);
		for (int i = 0; i < n; i++) {
			vec[i].clear();
			parent[i] = { 0,0 };
		}
	}

	return 0;
}