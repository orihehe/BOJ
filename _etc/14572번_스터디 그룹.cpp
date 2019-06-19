/*
BOJ 14572 - 스터디 그룹
https://www.acmicpc.net/problem/14572

모든 학생이 아는 알고리즘 수는 학생 몇을 빼도 같게 나온다.
따라서 d차이 이하의 학생 모두를 선택해서 계산해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<int> vec[100001];
pii arr[100001];
int my[31];
int main() {
	int n, k, d, m, w, ap = 0, acnt = 0, cnt = 0, ans = 0;
	scanf("%d %d %d", &n, &k, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &m, &w);
		arr[i] = { w,i };
		while (m--) {
			scanf("%d", &w);
			vec[i].push_back(w);
		}
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		while (ap < n && arr[ap].first - arr[i].first <= d) {
			for (int v : vec[arr[ap].second]) {
				if (!my[v]) cnt++;
				my[v]++;
			}
			ap++;
		}
		acnt = 0;
		for (int j = 1; j <= 30; j++) if (my[j] == ap - i) acnt++;
		ans = max(ans, (cnt - acnt)*(ap - i));

		for (int v : vec[arr[i].second]) {
			my[v]--;
			if (!my[v]) cnt--;
		}
	}
	printf("%d", ans);

	return 0;
}