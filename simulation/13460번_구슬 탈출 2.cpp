/*
R�� B�� ��ΰ� ��ĥ �� ��� ������ �տ� �ִ����� ���� move�Լ� ������ �޸��ߴ�.
(�ٸ� �� �ڵ带 ���� �̵�Ƚ���� ���� ���� �� ��ǥ�� rgo,cgo ��ĭ�� ���־���.)
ó���� �̵� �� R��ǥ�� �״���϶� continue�� �ߴٰ� WA�� �ް� �����˻� â�� ������
R�� �״���̰� B�� �̵����� �� �ٸ� ��찡 ���Դ�. �׷��� �� ������ ��� ���ڸ��� �� continue�� �����. 
(�����˻� �� ���� ������ �鿩�� �ϴµ�..)
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int,int>
using namespace std;

//�� �� �� ��
int rgo[4] = { -1,0,1,0 };
int cgo[4] = { 0,1,0,-1 };
char board[11][11];
P R, B, hole;
void move(int& r, int& c, int dis, bool& tmp, int othR, int othC) {
	while (board[r + rgo[dis]][c + cgo[dis]] != '#' && 
		(r+rgo[dis]!=othR || c+cgo[dis]!=othC) ) {
		r += rgo[dis];
		c += cgo[dis];
		if (r == hole.first && c == hole.second) {
			r = 0; c = 0; // ���� ������ ��ǥ �ٲ�
			tmp = true;
			return;
		}
	}
}

int main() {
	int n, m, cnt = 0, size = 0;
	queue<pair<P,P>> q; // ��, �� ��ǥ
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", board[i]);
	}
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			if (board[i][j] == 'R') {
				R = { i,j };
			}
			else if (board[i][j] == 'B') B = { i,j };
			else if (board[i][j] == 'O') hole = { i,j };
		}
	}
	bool suc = false, Rsuc = false, Bsuc;
	q.push({ R,B });
	while (!q.empty()) {
		Bsuc = false;
		if (size == 0) {
			size = q.size();
			cnt++;
		}
		if (cnt > 10) break;
		R = q.front().first;
		B = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int Rnr = R.first, Rnc = R.second;
			int Bnr = B.first, Bnc = B.second;
			// ���� ���� �����鼭 ������ ���� �տ� �Ķ��� ������ �Ķ��� ����
			if ((i==0 && Rnc==Bnc && Rnr>Bnr) || (i == 2 && Rnc == Bnc && Rnr<Bnr)
				|| (i == 1 && Rnr == Bnr && Rnc<Bnc) || (i == 3 && Rnr == Bnr && Rnc>Bnc)) {
				move(Bnr, Bnc, i, Bsuc, Rnr, Rnc);
				move(Rnr, Rnc, i, Rsuc, Bnr, Bnc);
			}
			else {
				move(Rnr, Rnc, i, Rsuc, Bnr, Bnc);
				move(Bnr, Bnc, i, Bsuc, Rnr, Rnc);
			}
			// �Ѵ� ���ڸ��ų� B�� ���ۿ� ����
			if (Bsuc==true || (Rnr==R.first && Rnc==R.second && Bnr==B.first && Bnc==B.second)) {
				Bsuc = false;
				Rsuc = false;
				continue;
			}
			if (Rsuc) {
				suc = true;
				break;
			}
			q.push({ { Rnr,Rnc },{ Bnr,Bnc } });
		}
		if (suc) {
			break;
		}
		size--;
	}
	if (suc) {
		printf("%d", cnt);
	}
	else printf("-1");

	return 0;
}