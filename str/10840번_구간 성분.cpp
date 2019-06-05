/*
BOJ 10840 - 구간성분
https://www.acmicpc.net/problem/10840

구간별로 각 알파벳 개수를 세준다.
세준 정보를 set에 넣고 b에서 센 값이 set에 있으면 가능
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

/* 🐣🐥 */
set<vector<int>> sss;
vector<int> vec;
int main() {
	int al, bl, ap, aa;
	char a[1501], b[1501];
	scanf("%s %s", a, b);
	al = strlen(a), bl = strlen(b);
	aa = min(al, bl);
	for (int i = aa; i >= 1; i--) {
		vec.clear();
		vec.resize(26);
		sss.clear();
		for (int j = 0; j < i; j++) {
			vec[a[j] - 'a']++;
		}
		sss.insert(vec);
		for (int j = i; j < al; j++) {
			vec[a[j] - 'a']++;
			vec[a[j - i] - 'a']--;
			sss.insert(vec);
		}

		vec.clear();
		vec.resize(26);
		for (int j = 0; j < i; j++) {
			vec[b[j] - 'a']++;
		}
		if (sss.find(vec) != sss.end()) return !printf("%d", i);
		for (int j = i; j < bl; j++) {
			vec[b[j] - 'a']++;
			vec[b[j - i] - 'a']--;
			if (sss.find(vec) != sss.end()) return !printf("%d", i);
		}
	}
	printf("0");

	return 0;
}