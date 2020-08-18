#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<char> letters;

bool isVowel(char given) {
	if (given == 'a' || given == 'e' || given == 'i' || given == 'o' || given == 'u') {
		return true;
	}
	else {
		return false;
	}
}

bool isCorrect(string given) {
	bool vowelFlag = false;
	int consonantFlag = 0;
	for (int i = 0; i < given.size(); i++) {
		if (isVowel(given[i])) {
			vowelFlag = true;
		}
		else {
			consonantFlag++;
		}
	}

	if (vowelFlag && consonantFlag >= 2) {
		return true;
	}
	else {
		return false;
	}
}

void solve(int m, int n, vector<int>& tmp) {
	if (m == 0) {
		string test = "";
		for (int i = 0; i < tmp.size(); i++) {
			test.push_back(letters[tmp[i]]);
		}

		if (isCorrect(test)) cout << test << "\n";
		return;
	}

	int small = tmp.size() != 0 ? tmp.back() + 1 : 0;

	for (int i = small; i < n; i++) {
		tmp.push_back(i);
		solve(m - 1, n, tmp);
		tmp.pop_back();
	}
}

int main() {
	int l, c;
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char curr;
		cin >> curr;
		letters.push_back(curr);
	}
	sort(letters.begin(), letters.end());
	vector<int> tmp;
	solve(l, c, tmp);
}
