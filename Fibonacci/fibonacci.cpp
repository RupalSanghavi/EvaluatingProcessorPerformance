#include <iostream>
#include<stdio.h>

using namespace std;

int fib(int n)
{
   if (n <= 1) {
     return n;
   }
   return fib(n-1) + fib(n-2);
}

int main ()
{
  int total = 20;
  for (int i = 0; i < total; i++) {
      cout << fib(i) << endl;
  }

  return 0;
}
