/*
BOJ 13549 (https://www.acmicpc.net/problem/13549)
�����̵��� �ϴ� ��� 0���� �ð��� �ɸ���.
loc�迭�� �� �� �̵��Ͽ� ���� ��ġ�� �Դ����� �����Ͽ� 
ť�� �� ��ġ�� ���� �� �̵�Ƚ���� �� ���ٸ� ���� �ʴ� ������� �ߴ�.
���� �̵� Ƚ������ �ּڰ� ���.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define P pair<int,int>
using namespace std;

int loc[100003];
int main() {
	int n, k, s = 1, cnt = 100000;
	queue<P> q;
	scanf("%d %d", &n, &k);
	q.push({ n,0 });
	fill(loc, loc + 100003, 100000);
	while (!q.empty()) {
		if (s == 0) {
			s = q.size();
		}
		int cur = q.front().first;
		int cc = q.front().second;
		q.pop();
		if (cur == k) {
			cnt = min(cnt, cc);
		}
		if (cur > 0 && loc[cur - 1] > cc + 1) {
			q.push({ cur - 1 , cc + 1 });
			loc[cur - 1] = cc + 1;
		}
		if (cur < 100000 && loc[cur + 1] > cc + 1) {
			q.push({ cur + 1 , cc + 1 });
			loc[cur + 1] = cc + 1;
		}
		if (cur * 2 <= 100001 && loc[cur * 2] > cc) {
			q.push({ cur * 2 , cc });
			loc[cur * 2] = cc;
		}
		s--;
	}
	printf("%d", cnt);

	return 0;
}