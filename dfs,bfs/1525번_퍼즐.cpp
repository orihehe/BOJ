/*
BOJ 퍼즐 - (https://www.acmicpc.net/problem/1525)

vec에 모든 경우 (9!가지) 를 넣어준다.
lower_bound로 vec에서 현재 상태와 같은 문자열의 위치를 찾아 use배열에 등장 여부를 표시한다.
등장 하지 않았다면 queue에 넣어주고, q가 비었는데 못찾았다면 -1, 찾았다면 cnt출력 
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<string> vec;
bool use[400000];
int rgo[4] = { 0,1,0,-1 };
int cgo[4] = { 1,0,-1,0 };
int main() {
	char c;
	int s = 1, cnt = 0, loc, loc_0;
	bool suc = false;
	string init = "012345678", tar, cur, tmp;
	queue<string> q;
	do {
		vec.push_back(init);
	} while (next_permutation(init.begin(), init.end()));

	for (int i = 0; i < 9; i++) {
		scanf(" %c", &c);
		tar += c;
	}
	init = "123456780";
	q.push(init);
	loc = lower_bound(vec.begin(), vec.end(), init) - vec.begin();
	use[loc] = true;

	while (!q.empty()) {
		if (s == 0) {
			s = q.size();
			cnt++;
		}
		cur = q.front(); q.pop();
		if (cur == tar) {
			suc = true;
			break;
		}
		loc_0 = cur.find('0');

		for (int i = 0; i < 4; i++) {
			int nr = loc_0 / 3 + rgo[i], nc = loc_0 % 3 + cgo[i];
			if (nr < 0 || nc < 0 || nr >= 3 || nc >= 3) continue;
			tmp = cur;
			swap(tmp[loc_0], tmp[(nr * 3) + nc]);
			loc = lower_bound(vec.begin(), vec.end(), tmp) - vec.begin();
			if (!use[loc]) {
				q.push(tmp);
				use[loc] = true;
			}
		}
		s--;
	}
	printf("%d", suc ? cnt : -1);

	return 0;
}