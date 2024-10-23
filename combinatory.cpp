#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

unsigned long long factorial(int n) {
  unsigned long long result = 1;

  for (int i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}

unsigned long long combinatory(int n, int k) {
  return factorial(n) / (factorial(k) * factorial(n - k));
}

unsigned long long combinatoryDP(int n, int k) {
  vector<vector<unsigned long long>> dp(n + 1,
                                        vector<unsigned long long>(n + 1, 0));

  for (int i = 0; i <= n; i++) {
    dp[i][0] = dp[i][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
  }

  return dp[n][k];
}

int numDigits(int num) { return num > 0 ? (int)log10(num) + 1 : 1; }

void pascal(int n) {
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int i = 0; i <= n; i++) {
    dp[i][0] = dp[i][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
  }

  int maxNum = dp[n][n / 2];
  int maxDigits = numDigits(maxNum);

  for (int i = 0; i <= n; i++) {

    cout << setw((n - i + 1) * (maxDigits + 1) / 2) << " ";

    for (int j = 0; j <= i; j++) {
      cout << setw(maxDigits) << dp[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int n, k;
  cin >> n >> k;

  cout << "DP: " << combinatoryDP(n, k) << endl;
  cout << "Factorial: " << combinatory(n, k) << endl;

  return 0;
}