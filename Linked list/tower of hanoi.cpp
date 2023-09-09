
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char final, char intermidiate)
{
	if (n == 0) {
		return;
	}
	towerOfHanoi(n - 1, source, intermidiate, final);
	cout << "Move disk " << n << " from rod " << source << " to rod " << final << endl;
	towerOfHanoi(n - 1, intermidiate, final, source);
}

// Driver code
int main()
{
	int N = 3;

	// A, B and C are names of rods
	towerOfHanoi(N, 'A', 'C', 'B');
	return 0;
}

// This is code is contributed by rathbhupendra
