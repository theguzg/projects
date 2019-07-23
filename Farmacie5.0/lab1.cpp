#include <cstdio>
#include <cstdlib>

int prim(int x) {

	if (x < 2)
		return 0;

	if (x > 2 && x % 2 == 0)
		return 0;

	for (int d = 3; d*d <= x; d++)
		if (x%d == 0)
			return 0;
	return 1;

}

int main() {

	int n;

	scanf("Hai cu un numar : %d \n", n);
	prim(n);


	return 0;
}