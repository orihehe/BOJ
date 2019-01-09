/*
BOJ 14455 (https://www.acmicpc.net/problem/14455)
�� �̸� ù���ڰ� ��� �ٸ��淡 loc �迭�� �̸� �� ���ں��� info�迭�� ����� ��ġ�� �����ߴ�. 
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
	// ���� ���� ��� ���� ��
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
		else cout << "Tie\n"; // �ι�°�� ���� ���� �������� ��
	}

	return 0;
}