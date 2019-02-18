/*
BOJ 16936 (https://www.acmicpc.net/problem/16936)

그래프로 생각해서 풀었다.
arr[i]*2==arr[j]거나 arr[i]/3==arr[j]라면 j->i로 간선을 그려준다.
들어오는 간선이 하나도 없는 원소가 마지막 원소가 된다.
그 원소에서 dfs를 돌려 모든 정점을 방문할 수 있을 때 원래의 수열이 된다.
*/
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
vector<ll> vec[100];
ll n, arr[100], srt;
bool suc, visited[100];
void dfs(ll cnt, ll cur) {
	if (cnt == n) {
		suc = true;
		printf("%lld ", arr[cur]);
		return;
	}
	for (ll v : vec[cur]) {
		if (!visited[v]) {
			visited[v] = true;
			dfs(cnt+1,v);
			visited[v] = false;
		}
		if (suc) {
			printf("%lld ", arr[cur]);
			return;
		}
	}
}
int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i] * 2 == arr[j]) {
				vec[j].push_back(i);
			}
			else if (arr[i] % 3 == 0 && arr[i] / 3 == arr[j]) {
				vec[j].push_back(i);
			}
			else cnt++;
		}
		if (cnt == n) srt = i;
	}
	dfs(1,srt);

	return 0;
}