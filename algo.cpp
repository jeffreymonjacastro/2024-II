#include <iostream>
#include <random>
#include <set>

using namespace std;

int algo(int n) {
  int count = 0;
  set<int> S;

  // Generador de números aleatorios
  random_device rd;                     // Dispositivo aleatorio
  mt19937 gen(rd());                    // Mersenne Twister como generador
  uniform_int_distribution<> dis(1, n); // Distribución uniforme entre 0 y n-1

  while (S.size() < n) {
    int j = dis(gen); // Genera un número uniformemente distribuido
    S.insert(j);
    count++;
  }

  return count;
}

int main() {

  for (int i = 1; i <= 10; i++) {
    int sum = 0;
    for (int j = 0; j < 100; j++) {
      sum += algo(i);
    }

    cout << "El promedio de 100 iteraciones con " << i << " numeros es "
         << sum / 100 << endl;
  }

  return 0;
}
