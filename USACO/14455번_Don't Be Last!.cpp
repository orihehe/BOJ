/*
BOJ 14455 (https://www.acmicpc.net/problem/14455)
소 이름 첫글자가 모두 다르길래 loc 배열에 이름 앞 글자별로 info배열에 저장될 위치를 저장했다. 
*/
#include <iostream>
#include <algorithm>
#include <string>
#define P pair<int,int>
using namespace std;

P info[7];
int main() {
	int loc[26];
	int i, n, am, f;
	char st[20];
	string name[7] = { "Bessie","Elsie","Daisy","Gertie","Annabelle","Maggie","Henrietta" };
	for (int i = 0; i < 7; i++) {
		loc[name[i][0] - 'A'] = i;
		info[i].second = i;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", st, &am);
		info[loc[st[0] - 'A']].first += am;
	}
	sort(info, info + 7);
	f = info[0].first;
	for (i = 1; i < 7; i++) {
		if (f != info[i].first) {
			f = info[i].first;
			break;
		}
	}
	// 우유 양이 모두 같을 때
	if (i == 7) cout << "Tie\n";
	else {
		int cnt = 0, who;
		for (i = 0; i < 7; i++) {
			if (f == info[i].first) {
				cnt++; who = i;
			}
		}
		if (cnt == 1)
			cout << name[info[who].second] << "\n";
		else cout << "Tie\n"; // 두번째로 작은 값이 여러개일 때
	}

	return 0;
}