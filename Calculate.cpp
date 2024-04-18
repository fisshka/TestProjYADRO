#include <deque>
#include <iostream>
#include <map>

#define VERIFY(cond)                                                       \
  if (!(cond)) {                                                           \
    cout << "unit test failed at " << __FILE__ << "," << __LINE__ << endl; \
  } else                                                                   \
    cout << "suscess!!" << endl;
// macro for unit tests
using namespace std;

map<int, deque<int>> fib{
    {0, {0}}, {1, {1}}};  // deque for storing Fibbonachi function results

deque<int> Plus(deque<int> n1, deque<int> n2) /*copy of deque with
  infinite numbers are set as function parameters*/
{
  int i = n1.size() - 1;
  int j = n2.size() - 1;
  int tmp = 0;

  deque<int> rez(max(i + 1, j + 1));  // an array for storing results

  for (; i >= 0 || j >= 0; i--, j--) {
    if (i >= 0 && j >= 0) {
      rez[max(i, j)] = (n1[i] + n2[j] + tmp) % 10;
      tmp = (n1[i] + n2[j] + tmp) / 10;
    } else if (i >= 0) {
      rez[i] = (n1[i] + tmp) % 10;
      tmp = (n1[i] + tmp) / 10;
    } else if (j >= 0) {
      rez[j] = (n2[j] + tmp) % 10;
      tmp = (n2[j] + tmp) / 10;
    }

    /*repetitions of the addition algorithm "in a column" - the last digit
    it is written to a cell in the array, the first one goes to the next one*/
  }
  if (tmp > 0) rez.push_front(tmp);  // recording the next digit to result
  return rez;
}

void Comparing()  // unit tests implemented using a macro
{
  deque<int> n1{1, 2, 3};
  deque<int> n2{-1, 2, 3};
  deque<int> n3{1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
  deque<int> n5{9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
                9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
  deque<int> n6{1};

  deque<int> rez = Plus(n1, n1);
  VERIFY(rez[0] == 2 && rez[1] == 4 && rez[2] == 6)

  rez = Plus(n2, n2);
  VERIFY(rez[0] == -2 && rez[1] == 4 && rez[2] == 6)

  rez = Plus(n3, n3);
  int i = 35;
  bool tru = true;
  while (i > 0) {
    tru = tru && (rez[i] == n3[i] + n3[i]);
    i--;
  }
  VERIFY(tru == true)

  rez = Plus(n5, n6);
  tru = rez[0] == 1;
  i = 27;
  while (i > 0) {
    tru = tru && (rez[i] == 0);
    i--;
  }
  VERIFY(tru == true)

  rez = Plus(n6, n5);
  tru = rez[0] == 1;
  i = 27;
  while (i > 0) {
    tru = tru && (rez[i] == 0);
    i--;
  }
  VERIFY(tru == true)

  rez = Plus(n6, n3);
  i = 34;
  tru = rez[35] == n6[0] + n3[35];

  while (i > 0) {
    tru = tru && (rez[i] == n3[i]);
    i--;
  }
  VERIFY(tru == true)

  rez = Plus(n3, n6);
  i = 34;
  tru = rez[35] == n6[0] + n3[35];

  while (i > 0) {
    tru = tru && (rez[i] == n3[i]);
    i--;
  }
  VERIFY(tru == true)
}
