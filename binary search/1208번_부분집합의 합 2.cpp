/*
BOJ 1208 (https://www.acmicpc.net/problem/1208)
n 크기의 반씩 모든 경우를 구해준다. 구해주는 과정에서도 s와 같은 값이 나오면 세준다.
구한 두 집합에서 합이 s가 나오는 개수를 이분탐색 해준다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int n, s, arr[41];
ll cnt;
vector<int> tmp1, tmp2;
void dfs(int cur, int sum) {
	if (cur == n / 2) {
		tmp1.push_back(sum);
		if (s == sum) cnt++;
		return;
	}
	dfs(cur + 1, sum + arr[cur + 1]);
	dfs(cur + 1, sum);
}
void dfs2(int cur, int sum) {
	if (cur == n) {
		tmp2.push_back(sum);
		if (s == sum) cnt++;
		return;
	}
	dfs2(cur + 1, sum + arr[cur + 1]);
	dfs2(cur + 1, sum);
}
int main() {
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0, 0);
	dfs2(n / 2, 0);
	tmp1.pop_back(), tmp2.pop_back();
	sort(tmp1.begin(), tmp1.end());
	sort(tmp2.begin(), tmp2.end());
	for (int i = 0; i < tmp1.size(); i++) {
		cnt += upper_bound(tmp2.begin(), tmp2.end(), s - tmp1[i])
			- lower_bound(tmp2.begin(), tmp2.end(), s - tmp1[i]);
	}
	if (s == 0) cnt -= 2;
	printf("%lld", cnt);

	return 0;
}