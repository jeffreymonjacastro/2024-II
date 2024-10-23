#include <iostream>
#include <vector>

using namespace std;

int algo(int n) {
  vector<int> A(n);

  A[0] = 1;
  A[1] = 3;
  A[2] = 6;

  for (int i = 3; i < n; i++) {
    A[i] = A[i - 1] + 2 * A[i - 2] + A[i - 3];
  }

  return A[n - 1];
}

int main() {

  for (int i = 1; i <= 20; i++) {
    cout << "El valor de A[" << i << "] es " << algo(i) << endl;
  }

  return 0;
}