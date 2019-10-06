/*
BOJ 15604 - Factor-Free Tree
https://www.acmicpc.net/problem/15604

현재 구간에서 루트로 설정할 노드를 찾고 
그 노드 기준으로 구간을 나누어 같은 작업을 반복해준다.
그러한 노드를 구간 양 끝에서 번갈아서 찾아주면 NlogN이 보장된다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define MAX 10000001
using namespace std;

/* 🐣🐥 */
int prime[MAX], p[1000001];
unordered_map<int, int> mp;
vector<int> my[1000001], who[1000001];
bool suc(int idx, int l, int r) {
	for (int v : my[idx]) {
		int ii = lower_bound(who[v].begin(), who[v].end(), l) - who[v].begin();
		if (who[v][ii] != idx) return false;
		ii = lower_bound(who[v].begin(), who[v].end(), idx + 1) - who[v].begin();
		if (ii != who[v].size() && who[v][ii] <= r) return false;
	}
	return true;
}
bool dq(int l, int r, int pp) {
	if (l >= r) {
		if (l == r)
			p[l] = pp;
		return true;
	}
	int le = l, ri = r, idx = -1;
	while (le <= ri) {
		if (suc(le, l, r)) idx = le;
		else if (suc(ri, l, r)) idx = ri;
		if (idx != -1) break;
		le++, ri--;
	}
	if (idx == -1) return false;
	p[idx] = pp;
	return dq(l, idx - 1, idx) & dq(idx + 1, r, idx);
}
int main() {
	int num = 0;
	for (int i = 2; i < MAX; i++) {
		if (prime[i]) continue;
		prime[i] = i;
		mp[i] = num++;
		for (int j = i; 1LL * j*i < MAX; j++)
			if (!prime[i*j]) prime[i*j] = i;
	}
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		int last = -1;
		while (x > 1) {
			if (last != prime[x]) {
				last = prime[x];
				my[i].push_back(mp[last]);
				who[mp[last]].push_back(i);
			}
			x /= last;
		}
	}
	mp.clear();
	if (dq(0, n - 1, -1))
		for (int i = 0; i < n; i++) printf("%d ", p[i] + 1);
	else printf("impossible");

	return 0;
}