#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	if (num == 1) {
		cout << '*';
		return 0;
	}
	for (int i = 0; i < num * 2; i++) {
		for (int j = 0; j < num; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					cout << "*";
				}
				else cout << " ";
			}
			else {
				if (j % 2 == 0) {
					cout << " ";
				}
				else cout << "*";
			}
		}
		cout << "\n";
	}
	return 0;
}