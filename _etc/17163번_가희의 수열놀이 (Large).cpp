/*
BOJ 17163 - 가희의 수열놀이 (Large)
https://www.acmicpc.net/problem/17163

mod값이 2*10^9 까지 주어지지만, 쿼리 수가 10^6이므로 최대 10^6까지만 가능하다.
벡터에 나머지별로 마지막에 들어온 값을 관리해주고,
pq에 {인덱스, 나머지} 를 넣어 벡터의 마지막 원소와 일치하는지를 확인하여 출력해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
bool no;
int arr[1000001];
vector<int> vec[1000000];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main() {
	int q, m, cm, up = 0, x, cnt = 0;
	scanf("%d %d", &q, &m);
	if (m > 1000000) no = true;
	while (q--) {
		scanf("%d", &cm);
		if (no) {
			if (cm == 1) scanf("%d", &x);
			else if (cm == 3) printf("-1\n");
			continue;
		}
		if (cm == 1) {
			scanf("%d", &x);
			if (vec[x%m].size() == 0) cnt++;
			vec[x % m].push_back(up);
			pq.push({ up,x%m });
			arr[up++] = x;
		}
		else if (cm == 2) {
			if (up >= 1) {
				vec[arr[up - 1] % m].pop_back();
				if (vec[arr[up - 1] % m].size() == 0) cnt--;
				else pq.push({ vec[arr[up - 1] % m].back(), arr[up - 1] % m });
				up--;
			}
		}
		else {
			if (cnt!=m) {
				printf("-1\n");
				continue;
			}
			while (true) {
				pii cur = pq.top();
				if (vec[cur.second].back() != cur.first) pq.pop();
				else break;
			}
			printf("%d\n", up-pq.top().first);
		}
	}

	return 0;
}