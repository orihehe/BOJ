/*
BOJ 15599 - Ascending Photo
https://www.acmicpc.net/problem/15599

연속한 키는 한 사람으로 생각하고, 모두 자른다고 했을 시 n-1번 잘라야한다.
구해야 할 것은 자르지 않는 횟수를 최대화하는 것이다.
그 문제는 (1,2), (2,3), (3,4),...쌍을 최대로 선택하는 것과 동치이다.

1 2 3 1 2 3 4 1 2 3 으로 주어질 때 +1로 연속한 수를 그룹으로 묶으면
1-2-3, 1-2-3, 1-2-3-4 이 되고
쌍을 선택 가능한 경우는 현재 고르려는 a,b의 a가 하나만 존재하거나
이전에 선택한 쌍과 다른 그룹일 때이다.
이유는 위의 예시로 보면 1-2를 선택했을 시 그 그룹의 2-3을 자른 뒤
사이에 다른 그룹들의 2,3을 사이에 넣어야 하기 때문.

따라서 ('어느 그룹', '값') 쌍 두 개를 가지고 dp로 값을 구해줬다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int arr[1000001], ssz;
vector<int> vec, vv, loc[1000001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		vec.push_back(arr[i]);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 0; i < n; i++) {
		if (i > 0 && arr[i] == arr[i - 1]) continue;
		int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
		vv.push_back(idx);
	}
	int sz = vv.size(), s = 0;
	ssz = vec.size();
	vv.push_back(-1);
	int cnt = 0;
	for (int i = 1; i <= sz; i++) {
		if (i == sz || vv[i - 1] + 1 != vv[i]) {
			for (int j = s; j < i; j++) {
				loc[vv[j]].push_back(cnt);
			}
			cnt++;
			s = i;
		}
	}
	pair<pii, pii> last = { {-1,0},{-1,0} };
	for (int i = 1; i < ssz; i++) {
		pair<pii, pii> cur = last;
		cur.first.first = cur.second.first = -1;
		for (int v : loc[i]) {
			int idx = lower_bound(loc[i - 1].begin(), loc[i - 1].end(), v)
				- loc[i - 1].begin();
			if (idx == loc[i - 1].size() || loc[i - 1][idx] != v) continue;
			int ret;
			if (last.first.first != v || loc[i - 1].size() == 1)
				ret = last.first.second;
			else ret = last.second.second;
			ret++;
			if (cur.first.second < ret) {
				cur.second = cur.first;
				cur.first = { v,ret };
			}
			else if (cur.second.second < ret) cur.second = { v,ret };
		}
		last = cur;
	}
	printf("%d", sz - 1 - last.first.second);

	return 0;
}
