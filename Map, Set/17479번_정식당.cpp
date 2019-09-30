/*
BOJ 17479 - 정식당
https://www.acmicpc.net/problem/17479
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#define ll long long
using namespace std;

/* 🐣🐥 */
map<string, int> nm, sp;
ll nmp, spp, sbp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, y;
	string x;
	cin >> a >> b >> c;
	while (a--) {
		cin >> x >> y;
		nm[x] = y;
	}
	while (b--) {
		cin >> x >> y;
		sp[x] = y;
	}
	while (c--)
		cin >> x;
	cin >> a;
	while (a--) {
		cin >> x;
		if (nm.find(x) != nm.end()) {
			nmp += nm[x];
		}
		else if (sp.find(x) != sp.end()) {
			spp += sp[x];
		}
		else {
			if (sbp != 0) return !printf("No");
			sbp += 1;
		}
	}
	if (spp != 0 && nmp < 20000LL) return !printf("No");
	if (sbp != 0 && nmp + spp < 50000LL) return !printf("No");
	printf("Okay");

	return 0;
}