/*
BOJ 13400 - Quality of Check Digits
https://www.acmicpc.net/problem/13400
*/
#include <cstdio>
#include <algorithm>
#include <functional>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int chk[10][10];
int id(int cur, int w) {
	int t, c = 0;
	if (w == 0) t = 1000;
	else t = 10000;
	while (t > 0) {
		c = chk[c][cur / t];
		cur %= t;
		t /= 10;
	}
	return c;
}
int toi(string s) {
	int ret = 0;
	for (int i = 0; i < 5; i++) {
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}
bool valid(int cur) {
	int t = 10000;
	if (id(cur, 1) != 0) return false;
	string st = "", tmp;
	while (t > 0) {
		st += ((int)cur / t) + '0';
		cur %= t;
		t /= 10;
	}
	for (int i = 0; i < 5; i++) {
		tmp = st;
		for (int j = '0'; j <= '9'; j++) {
			if (st[i] != j) {
				tmp[i] = j;
				int cc = toi(tmp);
				if (id(cc, 1) == 0) return false;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		tmp = st;
		swap(tmp[i], tmp[i + 1]);
		if (tmp != st) {
			int cc = toi(tmp);
			if (id(cc, 1) == 0) return false;
		}
	}
	return true;
}
int main() {
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &chk[i][j]);
		}
	}
	for (int i = 0; i <= 9999; i++) {
		int my = i * 10 + id(i, 0);
		if (!valid(my)) ans++;
	}
	printf("%d", ans);

	return 0;
}