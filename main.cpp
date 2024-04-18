#include <deque>
#include <iostream>
#include <map>

#include "Calculate.cpp"

using namespace std;

deque<int> Fibbonachi(int n) {
  if (fib.count(n) == 0) fib[n] = Plus(Fibbonachi(n - 1), Fibbonachi(n - 2));
  // if the Fibonacci number of the desired number is not found in the
  // dictionary, it is
  //  calculated using the Plus function

  return fib[n];

}  // Fibonacci number calculation function implemented using dictionary for
// faster
// calculation of large numbers with fewer iterations

int main() {
  int n;
  cout << "Enter Fibbnachi's number" << endl;
  cin >> n;
  if (n < 0) {
    cout << "Wrong number";
    return 0;
  }
  cout << "Rezult is:";
  deque<int> rez = Fibbonachi(n);
  int i = 0;
  while (i < rez.size()) {
    cout << rez[i];
    i++;
  }  // output of the result obtained using the Fibonacci function
}
