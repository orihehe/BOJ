/*
BOJ 1786 - 찾기
https://www.acmicpc.net/problem/1786

라빈카프로 찾아주면 된다.
공백이 들어올 수 있어 입력을 조심히 받자..
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_set>
#define ll long long
#define mod1 1000000009
#define mod2 1000000021
#define MAX 1000002
using namespace std;

/* 🐣🐥 */
unordered_set<ll> sss;
ll arr[MAX], vec[MAX], wprhq[2][MAX];
char st[MAX], tar[MAX];
vector<int> ans;
int main() {
	int len, m;
	ll x = 1, y = 1, ori1 = 0, ori2 = 0;
	for (int i = 0; i < MAX; i++) {
		wprhq[0][i] = y;
		wprhq[1][i] = x;
		y = y * 127 % mod1;
		x = x * 127 % mod2;
	}
	scanf("%[^\n]", st + 1);
	getchar();
	scanf("%[^\n]", tar + 1);
	len = strlen(st + 1);
	m = strlen(tar + 1);
	for (int i = 1; i <= m; i++) {
		ori1 = (ori1 + wprhq[0][MAX - i] * tar[i] % mod1) % mod1;
		ori2 = (ori2 + wprhq[1][MAX - i] * tar[i] % mod2) % mod2;
	}
	for (int i = 1; i <= len; i++) {
		arr[i] = (arr[i - 1] + wprhq[0][MAX - i] * st[i] % mod1) % mod1;
		vec[i] = (vec[i - 1] + wprhq[1][MAX - i] * st[i] % mod2) % mod2;
	}
	for (int i = m; i <= len; i++) {
		ll tmp1 = (arr[i] - arr[i - m] + mod1) % mod1*wprhq[0][i - m] % mod1;
		ll tmp2 = (vec[i] - vec[i - m] + mod2) % mod2*wprhq[1][i - m] % mod2;
		if (tmp1*mod2 + tmp2 == ori1 * mod2 + ori2) ans.push_back(i - m + 1);
	}
	printf("%d\n", ans.size());
	for (int i : ans) printf("%d ", i);

	return 0;
}