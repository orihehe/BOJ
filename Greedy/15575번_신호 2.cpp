/*
BOJ 15575 (https://www.acmicpc.net/problem/15575)

x좌표를 기준으로 가장 작은 y, 가장 큰 y 값만 사용한다.
모든 x좌표를 거치는 것이 최댓값이고
현재 x좌표에 대해 이전의 y들에 대해 이전-현재의 거리 + 이전까지의 거리 에서 최댓값을 저장한다.  
*/
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#define ll long long
using namespace std;

/* 🐣🐥 */
map<int, int> mxp;
map<int, int> mnp;
map<int, int> ::iterator iter;
double up, dw, ut, dt;
double dist(int a, int b) {
	ll x = a, y = b;
	return sqrt(x*x + y * y);
}
int main() {
	int n, a, b, na;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		iter = mxp.find(a); // 큰값
		if (iter == mxp.end()) {
			mxp[a] = b;
			mnp[a] = b;
		}
		else {
			if (iter->second < b) {
				mxp[a] = b;
			}
			if (mnp[a] > b) {
				mnp[a] = b;
			}
		}
	}
	iter = mxp.begin();
	a = iter->first; // 이전 큰거 x좌표
	for (++iter; iter != mxp.end(); iter++) {
		na = iter->first; // 현재 큰거 x좌표
		ut = max(up + dist(na - a, mxp[na] - mxp[a]), 
			dw + dist(na - a, mxp[na] - mnp[a]));
		dt = max(up + dist(na - a, mnp[na] - mxp[a]),
			dw + dist(na - a, mnp[na] - mnp[a]));
		up = ut, dw = dt;

		a = iter->first;
	}
	printf("%.7lf", max(up, dw));

	return 0;
}