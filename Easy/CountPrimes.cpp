#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n)
{
    if(n<=2)
        return 0;

    vector<bool> primes(n/2);
    fill(primes.begin(), primes.end(), true);

    int count = 1;
    for(unsigned long long i=3; i<n; i+=2)
    {
        if(primes[i/2])
        {
            count += 1;

            for(unsigned long long j=i; j*i<n; j+=2)
                primes[j*i/2] = false;
        }
    }

    return count;
}
int main()
{
    cout<<countPrimes(5000000);
    return 0;
}