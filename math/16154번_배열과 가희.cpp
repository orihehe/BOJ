/*
BOJ 16154 - 배열과 가희
https://www.acmicpc.net/problem/16154

먼저 첫 원소들의 쌍을 구해둔다.
그리고나서 바뀌는 원소의 원래 있던 쌍 개수를 빼주고, 새 원소로 생기는 쌍 개수를 더한다.
쌍은 현재 원소가 가지는 소인수를 약수로 가지는 원소를 세준다.
*/
#include <cstdio>
#include <vector>
#define ll long long
#define MAX 1000000
using namespace std;

/* 🐣🐥 */
vector<int> tt;
int use[1000001], mp[1000001];
int arr[200001], sz;
ll ans;
bool mn;
void prime(int a) {
	tt.clear();
	while (use[a] > 0) {
		int aa = use[a];
		tt.push_back(use[a]);
		while (a%aa == 0) a /= aa;
	}
	if(a!=1)
	tt.push_back(a);
	sz = tt.size();
}
int dfs(int cur, int sum) {
	int ret = 0;
	for (int i = cur; i < sz; i++) {
		if (1LL * sum * tt[i] > MAX) continue;
		int ttt = sum * tt[i];
		if (!mn || mp[ttt] != 0) {
			ret -= dfs(i + 1, ttt);
		}
		if (mn) {
			ret += --mp[ttt];
		}
		else {
			ret += mp[ttt]++;
		}
	}
	return ret;
}
int main() {
	for (int i = 2; i <= MAX; i++) {
		if (!use[i]) {
			for (int j = 2; j*i <= MAX; j++) {
				use[i*j] = i;
			}
		}
	}
	int n, q, x, p;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		prime(arr[i]);
		ans += dfs(0, 1);
	}
	while (q--) {
		scanf("%d %d", &p, &x);
		prime(arr[p]);
		mn = true;
		ans -= dfs(0, 1);
		prime(x);
		mn = false;
		ans += dfs(0, 1);
		printf("%lld\n", ans);
		arr[p] = x;
	}

	return 0;
}