#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int e = 1;
	int s = 1;
	int m = 1;
	int year = 1;
	int etarget, starget, mtarget;

	cin >> etarget >> starget >> mtarget;

	while (!(e == etarget && s == starget && m == mtarget)) {
		year++;
		e++;
		s++;
		m++;
		if (e == 16) {
			e = 1;
		}
		if (s == 29) {
			s = 1;
		}
		if (m == 20) {
			m = 1;
		}
	}

	cout << year << endl;
}
