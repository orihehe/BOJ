/*
���� 8741 (https://www.acmicpc.net/problem/8741)
1�� n�� 0�� n-1���� ��Ģ�� �߰������� �� �̷��� �Ǵ� ���� ���� �˻��غô�.
���� -> http://dev-min.tistory.com/6
*/
#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) printf("1");
	for (int i = 0; i < n - 1; i++) printf("0");

	return 0;
}