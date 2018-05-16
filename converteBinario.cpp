#include <iostream>
#include <cmath>

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

int ConverteDecimal (int binario) {
    int aux[4];
    int decimal;

    aux[0] = binario / 1000;
    binario = binario % 1000;
    aux[1] = binario / 100;
    binario = binario % 100;
    aux[2] = binario / 10;
    aux[3] = binario % 10;

    decimal = (int)(aux[0] * pow(2, 3) + aux[1] * pow(2, 2) + aux[2] * pow(2, 1) + aux[3] * pow(2, 0));
    return decimal;
}

int main () {
    int binario, decimal;

    for (int i = 0; i < 16; ++i) {
        cout << "###" << endl;
        cout << "Decimal: " << i << endl;
        binario = ConverteBinario4Bits(i);
        decimal = ConverteDecimal(binario);
        cout << "Binário de 4 bits: " << binario << endl;
        cout << "Decimal: " << decimal << endl;
    }
    return 0;
}
