#include <cstdio>
using namespace std;

int main()
{
	char board[9][9];
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		scanf("%s", board[i]);
	for (int i = 0; i < 8; i++) {
		if (i == 0 || i % 2 == 0) {
			for (int j = 0; j < 8; j+=2) {
				if (board[i][j] == 'F') cnt++;
			}
		}
		else {
			for (int j = 1; j < 8; j+=2) {
				if (board[i][j] == 'F') cnt++;
			}
		}
	}
	printf("%d\n", cnt);

	return 0;
}