/*
BOJ 16581 - Lie Detector
https://www.acmicpc.net/problem/16581
*/
#include <iostream>
#include <string>
using namespace std;

/* 🐣🐥 */
char s[2001];
string arr[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	bool tt, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	tt = true;
	for (int i = n - 1; i >= 0; i--) {
		x = arr[i] == "TRUTH";
		if (!tt) x = !x;
		tt = x;
	}
	cout << (x ? "TRUTH" : "LIE");

	return 0;
}