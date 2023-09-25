#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


int main() {
	set<char> S1;
	set<char> S2;
	int n;
	int m;
	int q;
	cin >> n >> m >> q;
	int i = 0;
	char a;
	while (i < q+1) {
		cin >> a;
		if (S1.count(a) == 0) {
			S1.insert(a);
		}
		i++;
	}
	int j = 0;
	int k = 0;
	for (; j < n; k++) {
		if (k == m) {
			j++;
		}
		char elem = char(j) + char(k);
		S2.insert(elem);
	}
	vector<int> diff;
	set_difference(S1.begin(), S1.end(), S2.begin(), S2.end(),
		inserter(diff, diff.begin()));
	for (int e = 0; e != diff.size(); e++) {
		cout << diff[e];
	}

	return 0;

}