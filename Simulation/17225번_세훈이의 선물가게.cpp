/*
BOJ 17225 - 세훈이의 선물가게
https://www.acmicpc.net/problem/17225

상민과 지수의 시간을 따로 관리하여 시간이 더 작은 사람의 남은 선물개수를 봐준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
struct gift {
	int t, cl, num;
};
gift arr[1000];
vector<int> aa, bb;
int rm[2];
int main() {
	int a, b, n, cnt = 0, at = 0, bt = 0, ap = 0;
	char c;
	scanf("%d %d %d", &a, &b, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c %d", &arr[i].t, &c, &arr[i].num);
		arr[i].cl = (c == 'R');
	}
	while (rm[0] || rm[1] || ap < n) {
		while (ap<n && (arr[ap].t <= at && arr[ap].t <= bt)) {
			if (rm[arr[ap].cl] == 0) {
				if (arr[ap].t > at && arr[ap].cl == 0) at = arr[ap].t;
				else if (arr[ap].t > bt && arr[ap].cl == 1) bt = arr[ap].t;
			}
			rm[arr[ap].cl] += arr[ap].num;
			ap++;
		}
		if (!rm[0] && !rm[1]) {
			at = bt = arr[ap].t;
			rm[arr[ap].cl] += arr[ap].num;
			ap++;
		}
		if (at == bt) {
			if (rm[0]) {
				aa.push_back(++cnt);
				rm[0]--;
				at += a;
			}
			else {
				bb.push_back(++cnt);
				rm[1]--;
				bt += b;
			}
		}
		else if (at < bt) {
			if (!rm[0]) {
				if (ap<n)
					at = min(arr[ap].t, bt);
				else at = bt;
			}
			else {
				aa.push_back(++cnt);
				rm[0]--;
				at += a;
			}
		}
		else {
			if (!rm[1]) {
				if (ap<n)
					bt = min(arr[ap].t, at);
				else bt = at;
			}
			else {
				bb.push_back(++cnt);
				rm[1]--;
				bt += b;
			}
		}
	}
	printf("%d\n", aa.size());
	for (int v : aa) printf("%d ", v);
	printf("\n%d\n", bb.size());
	for (int v : bb) printf("%d ", v);

	return 0;
}