/*
BOJ 5211 - 가단조와 다장조
https://www.acmicpc.net/problem/5211
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
void pls(char x, int &a, int &b) {
	if (x == 'A' || x == 'D' || x == 'E') a++;
	else if (x == 'C' || x == 'F' || x == 'G') b++;
}
int main() {
	char st[101];
	int a = 0, b = 0;
	while (~scanf("%[^\n|]", st)) {
		pls(st[0], a, b);
		getchar();
	}
	if (a > b) printf("A-minor");
	else if (b > a) printf("C-major");
	else {
		pls(st[strlen(st) - 1], a, b);
		if (a > b) printf("A-minor");
		else if (b > a) printf("C-major");
	}

	return 0;
}