// BOJ 16506 (https://www.acmicpc.net/problem/16506)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
void to_2(int num, int s) {
	int cnt = 0;
	vec.clear();
	while (num > 0) {
		if (num % 2 == 0) {
			vec.push_back(0);
		}
		else vec.push_back(1);
		num /= 2;
		cnt++;
	}
	while (s > cnt) {
		printf("0"); cnt++;
	}
	for (int i = vec.size() - 1; i >= 0; i--) printf("%d", vec[i]);
}
int main() {
	int t,a,b,c,len;
	char op[7];
	bool shp;  // #C¿Œ¡ˆ
	scanf("%d", &t);
	while (t--) {
		shp = false;
		scanf("%s %d %d %d", op, &a, &b, &c);
		len = strlen(op);
		if (op[len - 1] == 'C') {
			shp = true;
			op[len - 1] = NULL;
		}
		if (strcmp(op, "ADD") == 0) {
			printf("0000");
		}
		else if (strcmp(op, "SUB") == 0) {
			printf("0001");
		}
		else if (strcmp(op, "MOV") == 0) {
			printf("0010");
		}
		else if (strcmp(op, "AND") == 0) {
			printf("0011");
		}
		else if (strcmp(op, "OR") == 0) {
			printf("0100");
		}
		else if (strcmp(op, "NOT") == 0) {
			printf("0101");
		}
		else if (strcmp(op, "MULT") == 0) {
			printf("0110");
		}
		else if (strcmp(op, "LSFTL") == 0) {
			printf("0111");
		}
		else if (strcmp(op, "LSFTR") == 0) {
			printf("1000");
		}
		else if (strcmp(op, "ASFTR") == 0) {
			printf("1001");
		}
		else if (strcmp(op, "RL") == 0) {
			printf("1010");
		}
		else if (strcmp(op, "RR") == 0) {
			printf("1011");
		}
		printf(shp ? "10" : "00");

		to_2(a, 3);
		to_2(b, 3);
		to_2(c, shp ? 4 : 3);
		if (!shp)printf("0\n");
		else printf("\n");
	}

	return 0;
}