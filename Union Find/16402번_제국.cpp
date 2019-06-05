/*
BOJ 16402 - 제국
https://www.acmicpc.net/problem/16402
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

/* 🐣🐥 */
map<string, int> mp;
int p[501];
string nat[501];
int getr(int a) {
	if (p[a] == a) return a;
	return p[a] = getr(p[a]);
}
void merge(int a, int b) {
	if (getr(a) == b) { // 속국이 종주국을 이겼을 경우
		p[a] = a;
		p[b] = a;
		return;
	}
	p[getr(b)] = getr(a);
}
int main() {
	int n, m, len, w, np = 0;
	char name[31], name2[31];
	string nm, a, b;
	string nation[501];
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		nm = "";
		scanf(" %[^\n]", name);
		len = strlen(name);
		for (int j = 11; j < len; j++) {
			nm += name[j];
		}
		mp[nm] = i;
		nat[i] = nm;
	}
	while (m--) {
		a = b = "";
		scanf(" %[^,],%[^,],%d", name, name2, &w);
		len = strlen(name);
		for (int j = 11; j < len; j++) {
			a += name[j];
		}
		len = strlen(name2);
		for (int j = 11; j < len; j++) {
			b += name2[j];
		}
		if (w == 1) {
			merge(mp[a], mp[b]);
		}
		else if (w == 2) {
			merge(mp[b], mp[a]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (getr(i) == i) {
			nation[np++] = nat[i];
		}
	}
	sort(nation, nation + np);
	printf("%d\n", np);
	for (int i = 0; i < np; i++) printf("Kingdom of %s\n", nation[i].c_str());

	return 0;
}