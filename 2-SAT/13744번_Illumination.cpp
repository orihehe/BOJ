/*
BOJ 13744 - Illumination
https://www.acmicpc.net/problem/13744

같은 r이나 c에 위치한 램프를 봐주는데,
내가 비출 수 있는곳을 다른 램프가 비출 수 있다면 
둘 중 하나만 비추거나 둘 다 비추지 않도록 설정한다.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[1001];
int num[2001], fn[2001], cnt, scnt, k;
vector<int> vec[2001];
stack<int> sta;
bool ans = true;
int getOP(int cur) {
	return cur + (cur > k ? -k : k);
}
int dfs(int cur) {
	sta.push(cur);
	num[cur] = ++cnt;

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!fn[v]) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		scnt++;
		while (true) {
			int nx = sta.top();
			sta.pop();
			fn[nx] = scnt;
			if (fn[nx] == fn[getOP(nx)]) ans = false;
			if (nx == cur) break;
		}
	}
	return ret;
}
int main() {
	int n, r;
	scanf("%d %d %d", &n, &r, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (arr[i].first == arr[j].first) {
				if (abs(arr[i].second - arr[j].second) <= 2 * r) {
					vec[getOP(i)].push_back(j);
					vec[getOP(j)].push_back(i);
				}
			}
			else if (arr[i].second == arr[j].second) {
				if (abs(arr[i].first - arr[j].first) <= 2 * r) {
					vec[i].push_back(getOP(j));
					vec[j].push_back(getOP(i));
				}
			}
		}
	}
	for (int i = 0; i < k * 2; i++) if (!num[i]) dfs(i);
	printf("%d", ans ? 1 : 0);

	return 0;
}