/*
BOJ 2519 - 막대기
https://www.acmicpc.net/problem/2519

같은 종류의 막대마다 한 막대만이 F를 가질 수 있도록 한 뒤
교차하는 막대를 둘 중 최대 하나만 존재하도록 한다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int op, num[6001], cnt, scnt;
vector<int> vec[6001], ans;
stack<int> sta;
pii fn[6001];
bool flag = true, visited[6001];
int vt(int x1, int y1, int x2, int y2) {
	int ret = x1 * y2 - x2 * y1;
	return ret < 0 ? -1 : 1;
}
struct info {
	int x1, y1, x2, y2;
}arr[3001];
int getOP(int cur) {
	return cur + (cur > op ? -op : op);
}
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!fn[v].first) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		scnt++;
		while (true) {
			int nx = sta.top();
			sta.pop();
			fn[nx].first = scnt;
			fn[nx].second = nx;
			if (fn[nx].first == fn[getOP(nx)].first) flag = false;
			if (nx == cur) break;
		}
	}
	return ret;
}
bool cmp(pii a, pii b) {
	return a.first > b.first;
}
int main() {
	int n, a, b, c, d;
	scanf("%d", &n);
	op = n * 3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			arr[i * 3 + j] = { a,b,c,d };
		}
		int aa = i * 3;
		vec[getOP(aa)].push_back(aa + 1);
		vec[getOP(aa + 1)].push_back(aa);

		vec[getOP(aa + 2)].push_back(aa);
		vec[getOP(aa)].push_back(aa + 2);

		vec[getOP(aa + 2)].push_back(aa + 1);
		vec[getOP(aa + 1)].push_back(aa + 2);
	}

	for (int i = 0; i < op; i++) {
		for (int j = i + 1; j < op; j++) {
			a = vt(arr[i].x2 - arr[i].x1, arr[i].y2 - arr[i].y1,
				arr[j].x1 - arr[i].x2, arr[j].y1 - arr[i].y2);
			b = vt(arr[i].x2 - arr[i].x1, arr[i].y2 - arr[i].y1,
				arr[j].x2 - arr[i].x2, arr[j].y2 - arr[i].y2);
			if (a*b > 0) continue;
			a = vt(arr[j].x2 - arr[j].x1, arr[j].y2 - arr[j].y1,
				arr[i].x1 - arr[j].x2, arr[i].y1 - arr[j].y2);
			b = vt(arr[j].x2 - arr[j].x1, arr[j].y2 - arr[j].y1,
				arr[i].x2 - arr[j].x2, arr[i].y2 - arr[j].y2);
			if (a*b > 0) continue;
			vec[i].push_back(getOP(j));
			vec[j].push_back(getOP(i));
		}
	}
	for (int i = 0; i < op * 2; i++) if (!num[i]) dfs(i);
	if (!flag) return !printf("-1");
	sort(fn, fn + op * 2, cmp);
	for (int i = 0; i < op * 2; i++) {
		if (!visited[getOP(fn[i].second)]) {
			visited[fn[i].second] = true;
			if (fn[i].second < op) ans.push_back(fn[i].second + 1);
		}
	}
	printf("%d\n", ans.size());
	for (int v : ans) printf("%d ", v);

	return 0;
}