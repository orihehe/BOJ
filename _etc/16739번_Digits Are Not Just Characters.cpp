/*
BOJ 16739 - Digits Are Not Just Characters
https://www.acmicpc.net/problem/16739
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
bool o[12];
int x[12];
int n, oz, tz, op = 0, tmp = 0;
char ori[12], tt[12];
bool flag;
int main() {
	scanf("%d %s", &n, ori);
	oz = strlen(ori);
	for (int i = 0; i < oz; i++) {
		if (ori[i] <= '9' && ori[i] >= '0') {
			tmp *= 10;
			tmp += ori[i] - '0';
		}
		else {
			if (tmp > 0) {
				x[op] = tmp;
				o[op++] = true;
			}
			tmp = 0;
			x[op++] = ori[i];
		}
	}
	if (tmp > 0) {
		x[op] = tmp;
		o[op++] = true;
	}

	while (n--) {
		scanf("%s", tt);
		tz = strlen(tt);
		flag = false; // 큰
		bool dif = true;
		int tp = 0;
		tmp = 0;
		for (int i = 0; i < tz; i++) {
			if (tp == op) break;
			if (tt[i] <= '9' && tt[i] >= '0') {
				tmp *= 10;
				tmp += tt[i] - '0';
				if (i + 1 != tz && (tt[i + 1] <= '9' && tt[i + 1] >= '0')) continue;
				else {
					if (o[tp]) {
						if (x[tp] == tmp) {
							tp++;
							tmp = 0;
							continue;
						}
						else if (x[tp] < tmp) {
							dif = false;
							break;
						}
						else {
							flag = true;
							dif = false; break;
						}
					}
					else {
						dif = false;
						flag = true; break;
					}
					tmp = 0;
				}
			}
			else {
				if (o[tp]) {
					dif = false;
					break;
				}
				if (x[tp] < tt[i]) {
					dif = false;
					break;
				}
				else if (x[tp] > tt[i]) {
					dif = false;
					flag = true;
					break;
				}
				tp++;
			}
		}
		if (dif && tp < op) flag = true;
		if (flag) printf("-\n");
		else printf("+\n");
	}

	return 0;
}