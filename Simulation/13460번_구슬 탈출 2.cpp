/*
R과 B의 경로가 겹칠 때 어느 구슬이 앞에 있는지에 따라 move함수 순서를 달리했다.
(다른 분 코드를 보니 이동횟수를 세서 작은 쪽 좌표에 rgo,cgo 한칸을 빼주었다.)
처음에 이동 후 R좌표가 그대로일때 continue를 했다가 WA를 받고 질문검색 창에 가보니
R은 그대로이고 B가 이동했을 때 다른 경우가 나왔다. 그래서 두 구슬이 모두 제자리일 때 continue를 해줬다. 
(질문검색 안 보는 습관을 들여야 하는데..)
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int,int>
using namespace std;

//북 동 남 서
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
			r = 0; c = 0; // 구녕 들어갔으니 좌표 바꿈
			tmp = true;
			return;
		}
	}
}

int main() {
	int n, m, cnt = 0, size = 0;
	queue<pair<P,P>> q; // 빨, 파 좌표
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
			// 같은 선상에 있으면서 가려는 방향 앞에 파란색 있으면 파란색 먼저
			if ((i==0 && Rnc==Bnc && Rnr>Bnr) || (i == 2 && Rnc == Bnc && Rnr<Bnr)
				|| (i == 1 && Rnr == Bnr && Rnc<Bnc) || (i == 3 && Rnr == Bnr && Rnc>Bnc)) {
				move(Bnr, Bnc, i, Bsuc, Rnr, Rnc);
				move(Rnr, Rnc, i, Rsuc, Bnr, Bnc);
			}
			else {
				move(Rnr, Rnc, i, Rsuc, Bnr, Bnc);
				move(Bnr, Bnc, i, Bsuc, Rnr, Rnc);
			}
			// 둘다 제자리거나 B가 구멍에 들어가면
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