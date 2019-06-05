/*
백준 16677 악마 게임 (https://www.acmicpc.net/problem/16677)
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

double val[100];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string ori, word[100];
	int n, len, idx, orilen;
	double cnt, maxV;
	cin >> ori >> n;
	orilen = ori.size();
	for (int i = 0; i < n; i++) {
		cin >> word[i] >> val[i];
		len = word[i].size();
		idx = 0; cnt = 0;
		for (int j = 0; j < len; j++) {
			// idx가 원래 단어 길이를 넘으면 x
			if (idx<orilen && ori[idx] == word[i][j]) {
				idx++; continue;
			}
			cnt++;
		}
		// 비교 끝났는데 idx가 원래 단어 끝까지 가지 않았으면 단어 못만듦
		if (idx < orilen) val[i] = 0;
		else val[i] /= cnt;
	}
	idx = 0; maxV = val[0];
	for (int i = 1; i < n; i++) {
		if (maxV < val[i]) {
			maxV = val[i]; idx = i;
		}
	}
	if (maxV != 0) cout << word[idx];
	else cout << "No Jam";

	return 0;
}