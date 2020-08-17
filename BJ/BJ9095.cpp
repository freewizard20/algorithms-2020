#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solve(int curr) {
	if (curr <= 0) return 0;
	if (curr == 1) return 1;
	if (curr == 2) return 2;
	if (curr == 3) return 4;

	int tot = 0;
	tot += solve(curr - 1);
	tot += solve(curr - 2);
	tot += solve(curr - 3);
	return tot;
}

int main() {
	int n;
	cin >> n;
	for (int z = 0; z < n; z++) {
		int curr;
		cin >> curr;
		cout << solve(curr) << endl;
	}
}
