#include <stdio.h>
int main()
{
    unsigned long long n; // Creating a variable
    unsigned long long min = 2147483647; // Creating a variable that contains minimum iteration
    unsigned long long max = 0; // Creating a variable that contains maximum iteration
    scanf("%lld", &n); // Taking input
    long long counter = 0; // Creating a counter
    if (n == 1)
        return (n);
    else if (n == 0)
        return (-1);
    else if (n < 0)
        return (-2147483648);
    while (n != 1) // Collatz conjecture
    {
        if (n < min) // If number is less than minimum
            min = n; // Update the minimum
        if (n > max) // If number is greater than maximum
            max = n; // Update the maximum
        counter++; // Incrementing the counter
        if (n % 2 == 0) // If number is even
            n = n / 2;  // divide it by 2
        else // If number is odd
            n = 3.00 * n + 1.00; // multiply it by 3 and add 1
        printf("%lld\n", n); // Print the number
    }
    printf("Max: %lld\n", max); // Print the maximum
    printf("Min: %lld\n", min); // Print the minimum
    printf("%lld steps\n", counter); // Print the number of steps
    return (n); // Return the number
}