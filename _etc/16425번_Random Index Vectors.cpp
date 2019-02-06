/*
BOJ 16425 (https://www.acmicpc.net/problem/16425)

ADDED - ���� ��ġ �ٸ� ��ȣ�� ����, ������ ���
MULTIPLIED - ���� ��ġ ��ȣ�ٸ��� ����, ������ ��� ���
ROTATED - �������� k�� ����Ʈ
          n%k���� ū ���� ���ְ�, ���� ���� n-n%k���� ������
*/
#include <cstdio>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

vector<ll> ans;
int main() {
	ll n, m, A[1001], B[1001], an, bn, ap, bp, ak, bk, mm;
	scanf("%lld %lld", &n, &m);
	scanf("%lld", &an);
	for (int i = 0; i < an; i++) {
		scanf("%lld", &A[i]);
	}
	scanf("%lld", &bn);
	for (int i = 0; i < bn; i++) {
		scanf("%lld", &B[i]);
	}
	ap = 0, bp = 0;
	while (ap < an && bp < bn) {
		if (llabs(A[ap]) == llabs(B[bp])) {
			if (A[ap] == B[bp]) {
				ans.push_back(A[ap]);
			}
			ap++, bp++;
		}
		else if (llabs(A[ap]) < llabs(B[bp])) {
			ans.push_back(A[ap++]);
		}
		else {
			ans.push_back(B[bp++]);
		}
	}
	while (ap < an) {
		ans.push_back(A[ap++]);
	}
	while (bp < bn) {
		ans.push_back(B[bp++]);
	}
	printf("%d ", ans.size());
	for (ll v : ans) {
		printf("%lld ", v);
	}
	printf("\n");
	ans.clear();

	ap = 0, bp = 0;
	while (ap < an && bp < bn) {
		if (llabs(A[ap]) == llabs(B[bp])) {
			if (A[ap] == B[bp]) {
				ans.push_back(llabs(A[ap]));
			}
			else ans.push_back(-llabs(A[ap]));
			ap++, bp++;
		}
		else if (llabs(A[ap]) < llabs(B[bp])) {
			ap++;
		}
		else {
			bp++;
		}
	}
	printf("%d ", ans.size());
	for (ll v : ans) {
		printf("%lld ", v);
	}
	printf("\n");

	ans.clear();
	mm = m % n;
	ap = 0;
	while (ap < an && llabs(A[ap]) <= mm) {
		ap++;
	}
	ak = ap;
	while (ap < an) {
		ans.push_back(A[ap] > 0 ? A[ap] - mm : A[ap] + mm);
		ap++;
	}
	ap = 0;
	while (ap < ak) {
		ans.push_back(A[ap] > 0 ? A[ap] + (n - mm) : A[ap] - (n - mm));
		ap++;
	}
	printf("%d ", ans.size());
	for (ll v : ans) {
		printf("%lld ", v);
	}
	printf("\n");

	ans.clear();
	mm = m % n;
	bp = 0;
	while (bp<bn && llabs(B[bp]) <= mm) {
		bp++;
	}
	bk = bp;
	while (bp < bn) {
		ans.push_back(B[bp] > 0 ? B[bp] - mm : B[bp] + mm);
		bp++;
	}
	bp = 0;
	while (bp < bk) {
		ans.push_back(B[bp] > 0 ? B[bp] + (n - mm) : B[bp] - (n - mm));
		bp++;
	}
	printf("%d ", ans.size());
	for (ll v : ans) {
		printf("%lld ", v);
	}
	printf("\n");

	return 0;
}