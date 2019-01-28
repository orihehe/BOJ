/*
BOJ 15461 (https://www.acmicpc.net/problem/15461)

map을 처음 써본 문제
소의 아이디, 우유량을 저장하는 맵 하나, 우유량, 우유량 개수를 저장하는 맵 하나를 만든다.
display가 바뀌는 경우는
1. 새로 들어온 아이디가 최댓값일 때
2. 혼자 최댓값이던 소가 바뀌고 나서 최댓값이고 여러명이거나, 최댓값이 아닐 때
3. 여러명 최댓값인 소일때
4. 중간에 있던 소가 최댓값이 됐을 때
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct info {
	int day, id, chan;
	bool operator <(const info &a) const {
		return day < a.day;
	}
};
map<int, int> mp;
map<int, int> mv;
vector<info> vec;
int main() {
	int n, g, d, id, m, cnt = 0;
	char pm;
	scanf("%d %d", &n, &g);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %c%d", &d, &id, &pm, &m);
		vec.push_back({ d,id,pm == '+' ? m : -m });
	}
	sort(vec.begin(), vec.end());
	for (info &v : vec) {
		if (mp.find(v.id) == mp.end()) {  // 없으면
			mp[v.id] = g + v.chan;
			mv[mp[v.id]]++;
			if (mv.find(g + v.chan) == --(mv.end())) cnt++;
		}
		else if (mv.find(mp[v.id]) == --(mv.end()) // 최대에 혼자있으면
			&& mv[mp[v.id]] == 1) {
			mv.erase(mv.find(mp[v.id]));
			mp[v.id] += v.chan;
			mv[mp[v.id]]++;
			if (v.chan < 0) {
				if (mv.find(mp[v.id]) == --(mv.end()) && mv[mp[v.id]] != 1) cnt++;
				else if (mv.find(mp[v.id]) != --(mv.end())) cnt++;
			}
		}
		else if (mv.find(mp[v.id]) == --(mv.end())) { // 최대에 여러개
			cnt++;
			mv[mp[v.id]]--;
			mp[v.id] += v.chan;
			mv[mp[v.id]]++;
		}
		else {
			mv[mp[v.id]]--;
			if (mv[mp[v.id]] == 0) mv.erase(mv.find(mp[v.id]));
			mp[v.id] += v.chan;
			mv[mp[v.id]]++;
			if (mv.find(mp[v.id]) == --(mv.end()))  cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}