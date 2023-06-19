/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 5

defines a function to see if n is divisible by d 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns true or false
*/

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d)
{
    if (d != 0 && n % d == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (isDivisibleBy(n, i))
        {
            return false;
        }
    }
    return true;
}

int nextPrime(int n)
{
    if (n < 0)
    {
        return 2;
    }
    while (n < n*2)
    {
        n++;
        if (isPrime(n))
        {
            return n;
        }
    }
    return 0;
}

int countPrimes(int a, int b)
{
    int counter = 0;
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i) == true)
        {
            counter +=1;
        }
    }
    return counter;
}

bool isTwinPrime(int n)
{
    int forward, backward;
    forward = n + 2;
    backward = n - 2;

    if ((isPrime(forward) || isPrime(backward)) && isPrime(n))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int nextTwinPrime(int n)
{
    if (n < 0)
    {
        return 3;
    }

    while (n < n*2)
    {
        n++;
        if(isTwinPrime(n))
        {
            return n;
        }
    }
    return 0;
}

int largestTwinPrime(int a, int b)
{
    for (int i = b; i >= a; i--)
    {
        if (isTwinPrime(i))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
   int num, num2;
   cin >> num >> num2;

   return largestTwinPrime(num, num2);

   return 0;

}
