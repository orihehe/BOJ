/*
BOJ 16153 - 비트와 가희
https://www.acmicpc.net/problem/16153

meet in the middle
켜야 할 비트를 모두 켠 값을 orion에 저장해둔다. on에는 나머지 비트로 만들어야 할 나머지를 저장
나머지 비트들을 (int범위) 반 나누어 모든 경우를 nn[0], nn[1]에 저장하고,
모든 no[0]에 대해 v1로 뒀을 때 v1의 나머지 + nn[1]의 나머지가 on이 되는 개수를 
upper, lower _bound로 찾아주었다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
bool use[31], suc;
vector<pii> nn[2];
vector<pii> ::iterator fr, ba;
int n, a, b, x, ans = 0, last, on, orion;
void go(int cur, int cnt, int sum, int e, int w) {
	if (cnt == e) {
		if (sum == 0) return;
		if (sum%a == on && sum+orion <= b) ans++;
		last = cur;
		nn[w].push_back({ sum%a, sum });
		return;
	}
	if (use[cur]) go(cur + 1, cnt, sum, e, w);
	else {
		go(cur + 1, cnt + 1, sum + (1 << cur), e, w);
		go(cur + 1, cnt + 1, sum, e, w);
	}
}
int main() {
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		use[x] = true;
		on += (1 << x);
	}
	if (on%a == 0 && on!=0 && on <= b) ans++;
	orion = on;
	on = (a - on % a)%a; // 목표 나머지
	x = 31 - n; // 남은 비트 개수
	go(0, 0, 0, x / 2,0);
	go(last, x / 2, 0, x,1);
	sort(nn[1].begin(), nn[1].end());
	for (pii v1 : nn[0]) {
		//b - v1.second-orion 로 b의 값 이하만 찾음
		ans+= upper_bound(nn[1].begin(), nn[1].end(), pii((on - v1.first + a) % a, b - v1.second-orion))-
			lower_bound(nn[1].begin(), nn[1].end(), pii((on - v1.first + a) % a, -1));
	}
	printf("%d", ans);

	return 0;
}