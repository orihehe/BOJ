/*
BOJ 16362 - Parentheses
https://www.acmicpc.net/problem/16362
*/
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

/* 🐣🐥 */
char st[1002];
stack<char> sta;
bool flag = false;
int main() {
	scanf("%[^\n]", st);
	int len = strlen(st);
	for (int i = 0; i < len; i++) {
		if (st[i] == ' ') continue;
		if (st[i] == '(') sta.push('(');
		else if (st[i] == ')') {
			if (!sta.empty() && sta.top() == 'a') {
				flag = true;
			}
			else if (sta.empty() || sta.top() != '.')return !printf("error");

			while (!sta.empty()) {
				if (sta.top() != '(') sta.pop();
				else break;
			}
			if (sta.empty()) return !printf("error");
			sta.pop();
			if (!sta.empty() && sta.top() == '+') sta.push('.');
			else  sta.push('a');
		}
		else if (st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/' || st[i] == '%') {
			if (!sta.empty() && sta.top() == '.') flag = true;
			else if (sta.empty() || sta.top() > 'z' || sta.top() < 'a') return !printf("error");
			sta.push('+');
		}
		else {
			if (!sta.empty() && (sta.top() == '.' || sta.top() == 'a'))return !printf("error");
			if (!sta.empty() && sta.top() == '+') {
				sta.push('.');
			}
			else {
				sta.push('a');
			}
		}
	}
	if (sta.size() == 1) {
		if (sta.top() == 'a') printf("improper");
		else printf("error");
	}
	else {
		int cnt = 0;
		while (!sta.empty()) {
			if (sta.top() == '(') return !printf("error");
			if (sta.top() == '.') cnt++;
			sta.pop();
		}
		if (cnt == 0) return !printf("error");
		if (flag || cnt >1) printf("improper");
		else printf("proper");
	}

	return 0;
}