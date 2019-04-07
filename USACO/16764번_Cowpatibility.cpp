/*
BOJ 16764 - Cowpatibility
https://www.acmicpc.net/problem/16764

각 소가 가진 flavors의 조합을 벡터에 저장해 map에 저장해둔다.
그리고나서 소별로 합집합을 구해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[5], lm;
map<vector<int>, int> mp;
vector<int> vec;
ll sum;
void dfs(int cur, int cnt) {
	if (cnt == lm) {
		sum += mp[vec];
		mp[vec]++;
		return;
	}
	if (cur == 5) return;
	dfs(cur + 1, cnt);
	vec[cnt] = arr[cur];
	dfs(cur + 1, cnt + 1);
}
int main() {
	ll n, ans = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &arr[j]);
		}
		sort(arr, arr + 5);
		vec.clear();
		vec.resize(5);
		for (int j = 1; j <= 5; j++) {
			lm = j;
			sum = 0;
			dfs(0, 0);
			if (j % 2) {
				ans += sum;
			}
			else {
				ans -= sum;
			}
		}
	}

	printf("%lld", n*(n - 1) / 2 - ans);

	return 0;
}