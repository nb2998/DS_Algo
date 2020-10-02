//problem: divisibility Count: Given N digit and Number A and Number B. Count number of N digit numbers divisible by both A and B;
#include <cmath>
#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

int divisibility_count(int digit, int A, int B)
{

    long long int first_num = pow(10, digit - 1);
    long long int lastnum = pow(10, digit) - 1;
    long long int modulo = 10000000007;
    // first number which is divisible by given A
    first_num = (first_num - first_num % A) + A;

    // last number which is divisible by given A
    lastnum = (lastnum - lastnum % A);

    // Apply the formula here
    int count_Of_divByA = (((lastnum - first_num) / A + 1)) % modulo;
    cout << count_Of_divByA << endl;
    // cout << countOfN_divByA << endl;

    int divisibilityCount = 0;
    for (long int k = 0, i = first_num; k < count_Of_divByA; k++, i = i + A)
    {
        if (i % B == 0)
        {
            divisibilityCount++;
            divisibilityCount = divisibilityCount % modulo;
        }
    }
    return divisibilityCount;
}

int main()
{
    int n, A, B;
    cin >> n >> A >> B;
    clock_t tStart = clock();
    cout << divisibility_count(n, A, B) << "\n";

    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

    return 0;
}
