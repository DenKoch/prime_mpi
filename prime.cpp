#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char* argv[]);
int prime(int n);

int main(int argc, char* argv[])
{
	int n = 200000, p, primes;
	clock_t t = clock();
	primes = prime(n);
	t = clock() - t;

	cout << "  " <<	setw(8)	 << n
		 << "  " << setw(8)  << primes
		 << "  " << setw(14) << ((float)t) / CLOCKS_PER_SEC << "\n";

	return 0;
}

int prime(int n)
{
	int i, j, prime, total = 0;

	for (i = 2; i <= n; i++)
	{
		prime = 1;
		for (j = 2; j < i; j++)
		{
			if ((i % j) == 0)
			{
				prime = 0;
				break;
			}
		}
		total = total + prime;
	}
	return total;
}