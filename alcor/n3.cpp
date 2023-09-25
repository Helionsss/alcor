#include <iostream>
#include <string>
using namespace std;


int main() {
	string a;
	int s;
	cin >> s >> a;
	int n = a.size();
	int err = 0;
	int i = 0;
	int j = n - 1;
	for (; i < j; i++, j--) {
		if (a[i] != a[j]) {
			err += 1;
			if (a[i + 1] == a[j]) {
				i++;
			}
			else if (a[i] == a[j - 1]) {
				j--;
			}
		}
	}
	if (err <= 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}