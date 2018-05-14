#include <iostream>

using namespace std;

int ConverteBinario4Bits (int n) {
    int aux[4];
    int resto, binario;

    aux[3] = n % 2;
    resto = n / 2;
    aux[2] = resto % 2;
    resto = resto / 2;
    aux[1] = resto % 2;
    resto = resto / 2;
    aux[0] = resto % 2;

    binario = aux[0]*1000 + aux[1]*100 + aux[2]*10 + aux[3]*1;

    return binario;
}

int main () {
    int n;

    cin >> n;

    cout << "Decimal(de 0 até 15): " << n << endl;
    cout << "Binário de 4 bits: " << ConverteBinario4Bits(n) << endl;

    return 0;
}
