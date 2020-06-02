#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <omp.h>

using namespace std;

int main(int argc, char* argv[]);
int prime_number(int n);

int main(int argc, char* argv[])
{
	int n = 200000;
	double wtime = omp_get_wtime();
	int primes = prime_number(n);
	wtime = omp_get_wtime() - wtime;

	cout << "  " << setw(8) << n
		<< "  " << setw(8) << primes
		<< "  " << setw(14) << wtime << "\n";

	return 0;
}

int prime_number(int n)
{
	int i;
	int j;
	int prime;
	int total = 0;

# pragma omp parallel \
  shared ( n ) \
  private ( i, j, prime )

# pragma omp for reduction ( + : total )
	for (i = 2; i <= n; i++)
	{
		prime = 1;

		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				prime = 0;
				break;
			}
		}
		total = total + prime;
	}

	return total;
}