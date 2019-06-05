/*
BOJ 16508 (https://www.acmicpc.net/problem/16508)

책의 개수가 16개 뿐이므로 완전탐색으로 해준다.
가장 작은 값 출력!
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

pair<int, string> arr[17];
int ap[27], minV=1000001;
int n, p;
void go(int cur, int sum) {
	if (cur == n) {
		bool suc = true;
		for (int i = 0; i < 26; i++) {
			if (ap[i] > 0) suc = false;;
		}
		if(suc)
			minV = min(minV, sum);
		return;
	}
	int len = arr[cur].second.size();
	for (int i = 0; i < len; i++) {
		ap[arr[cur].second[i] - 'A']--;
	}
	go(cur + 1, sum + arr[cur].first);
	for (int i = 0; i < len; i++) {
		ap[arr[cur].second[i] - 'A']++;
	}
	go(cur + 1, sum);
}
int main() {
	string word;
	cin >> word >> n;
	for (int i = 0; i < word.size(); i++) {
		ap[word[i] - 'A']++;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	go(0, 0);
	printf("%d", minV == 1000001 ? -1 : minV);

	return 0;
}