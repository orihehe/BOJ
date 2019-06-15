/*
BOJ 13415 - 정렬 게임
https://www.acmicpc.net/problem/13415

큰 구간 이전의 작은 구간들은 결과에 영향을 미치지 못하므로
구간이 큰 것부터 봐주는데, 그 뒤로 들어오는 구간들 중 큰 구간으로 건너뛰며 봐준다.
오름차순이냐, 내림차순이냐에 따라 원소를 적절히 배치
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int num[20001], ans[100001];
vector<pii> vec;
int main() {
	int n, m, a, b, last, x, fr, ba;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ans[i]);
		num[ans[i] + 10000]++;
	}
	last = n + 1, fr = 0, ba = 20000, x = -1;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vec.push_back({ a,i * 2 });
		vec.push_back({ b,i * 2 + 1 });
	}
	sort(vec.begin(), vec.end(), greater<pii>());
	vec.push_back({ 0,2 * m });
	last = vec[0].first, x = vec[0].second;
	for (int i = last + 1; i <= n; i++)
		num[ans[i] + 10000]--;
	for (pii v : vec) {
		if (last > v.first && v.second > x) {
			if (x % 2) {
				for (; last > v.first; last--) {
					while (!num[fr]) fr++;
					ans[last] = fr - 10000;
					num[fr]--;
				}
			}
			else {
				for (; last > v.first; last--) {
					while (!num[ba]) ba--;
					ans[last] = ba - 10000;
					num[ba]--;
				}
			}
			last = v.first, x = v.second;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);

	return 0;
}