/*
BOJ 1620 (https://www.acmicpc.net/problem/1620)
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> sim;
map<int, string> ism;
int si(string st) {
	int len = st.size();
	int ret = 0;
	for (int i = 0; i<len; i++) {
		ret *= 10;
		ret += st[i] - '0';
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	string tmp;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		sim[tmp] = i;
		ism[i] = tmp;
	}
	for (int i = 0; i<m; i++) {
		cin >> tmp;
		if (tmp[0] <= '9' && tmp[0] >= '0') {
			cout << ism[si(tmp)] << "\n";
		}
		else {
			cout << sim[tmp] << "\n";
		}
	}

	return 0;
}