/*
BOJ 2957 (https://www.acmicpc.net/problem/2957)

현재 노드가 삽입될 위치는
1. 먼저 삽입된 노드들 중 나보다 큰 값들 중 가장 작은 값의 왼쪽
2. 먼저 삽입된 노드들 중 나보다 작은 값들 중 가장 큰 값의 오른쪽
둘 중 하나인데, 깊이 값이 더 큰 노드 밑에 삽입되어야 한다.

1노드와 2노드는 이어져있고 현재 값은 그 사이,
1노드 깊이가 더 작다면 1노드의 자식으로 넣으려 해도 그 위치에 2노드가 있음.
반대의 경우도 마찬가지
*/
#include <cstdio>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;

map<int, int> mp;
map<int, int> ::iterator iter;
int main() {
	int n, x;
	ll cur = 0;
	scanf("%d", &n);
	scanf("%d", &x);
	n--;
	mp[x] = 0;
	printf("0\n");
	while (n--) {
		scanf("%d", &x);
		iter = mp.lower_bound(x);
		if (iter == mp.end()) { // 내가 젤 큼
			mp[x] = (--iter)->second + 1;
		}
		else if (iter == mp.begin()) { // 내가 젤 작음
			mp[x] = iter->second + 1;
		}
		else {
			mp[x] = (iter--)->second;
			mp[x] = max(mp[x], iter->second) + 1;
		}
		cur += mp[x];
		printf("%lld\n", cur);
	}

	return 0;
}