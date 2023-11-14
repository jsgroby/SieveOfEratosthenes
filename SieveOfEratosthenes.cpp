#include <stdio.h>
#include <string.h>
#include <sys/time.h>

long GetTimeMs(void)
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec*1000 + t.tv_usec/1000;
}



// marks all mutiples of 'a' ( greater than 'a' but less than equal to 'n') as 1.
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}

// A function to print all prime numbers smaller than n
void SieveOfEratosthenes(int n)
{
    int counter = 0;  // To count the number of primes found
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        bool arr[n];
        memset(arr, 0, sizeof(arr));
        
        /* Following property is maintained in the below for loop
         arr[i] == 0 means i + 1 is prime
         arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                //(i+1) is prime, print it and mark its multiples
                printf("%d\n", i+1);
                counter = counter + 1;
                markMultiples(arr, i+1, n);
            }
        }
    }
    printf("\n%d primes found", counter);
}

// Driver Program to test above function
int main(void)
{
    int n;
    printf("Ceiling?\n");
    scanf("%d", &n);
    printf("Following are the prime numbers up to and including %d\n\n", n);
    long startTime = GetTimeMs();
    SieveOfEratosthenes(n);
    printf("\nElapsed Time: %ld ms\n", GetTimeMs() - startTime);
    return 0;
}

