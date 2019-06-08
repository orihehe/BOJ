/*
BOJ 15014 - Lemonade Trade
https://www.acmicpc.net/problem/15014

2^100000 로 오버플로, 로그로 값을 저장하고 복구해준다.
이전에 나왔던 내가 원하는 음료의 최댓값만을 찾아주면된다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;

/* 🐣🐥 */
map<string, double> mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string a, b;
	double f;
	cin >> n;
	mp["pink"] = 0;
	while (n--) {
		cin >> b >> a >> f;
		if (mp.find(a) != mp.end()) {
			if (mp.find(b) != mp.end()) {
				mp[b] = max(mp[b], mp[a] + log2(f));
			}
			else mp[b] = mp[a] + log2(f);
		}
		if (mp.find("blue") != mp.end() && mp["blue"] >= log2(10)) 
			return !printf("10.000000");
	}

	if (mp.find("blue") == mp.end()) printf("0.000000");
	else printf("%.7lf", pow(2, mp["blue"]));

	return 0;
}