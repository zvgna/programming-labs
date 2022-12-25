#include <iostream>
using namespace std;
int main()

{
    setlocale(0, "");
    cout << "~~~~~ 1 задание ~~~~~ \n";
    cout << "В памяти компьютера: \n";
    cout << "int занимает " << sizeof(int) << " байта \n";
    cout << "short int занимает " << sizeof(short int) << " байта \n";
    cout << "long int занимает " << sizeof(long int) << " байта \n";
    cout << "float занимает " << sizeof(float) << " байта \n";
    cout << "double занимает " << sizeof(double) << " байт \n";
    cout << "long double занимает " << sizeof(long double) << " байт \n";
    cout << "char занимает " << sizeof(char) << " байт \n";
    cout << "bool занимает " << sizeof(bool) << " байт \n";
    cout << "\n";


    cout << "~~~~~ 2 задание ~~~~~ \n";
    int imput;
    cout << "Введите любое целое число \n";
    cin >> imput;
    int idz = imput;
    cout << "Двоичное представление введенного числа: \n ";
    int a = sizeof(imput) * 8;
    int mask = 1 << (a - 1);
    for (int i = 0; i < a; i++) {
        if (i == 1 || i % 8 == 0) {
            putchar(' ');
        }
        putchar(imput & mask ? '1' : '0');
        imput <<= 1;
    }
    //начало идз
    cout << "\n";
    cout << "Введите на какое количество битов нужно сдвинуть полученное число: \n";
    int z;
    cin >> z;
    idz <<= z; handleForCase4

    for (int i = 0; i < a; i++) {
        if (i == 1 || i % 8 == 0) {
            putchar(' ');
        }
        putchar(idz & mask ? '1' : '0');
        idz <<= 1;
    //окончание идз
    }
    cout << "\n";
    union {
        float value;
        int b;
    };
    cout << "\n";
    cout << "~~~~~ 3 задание ~~~~~\n";
    cout << "Введите любое значение типа float \n";
    cin >> value;
    cout << "Двоичное представление введенного числа: \n";
    for (int i = 0; i < a; i++) {
        if (i == 1 || i % 8 == 0) {
            putchar(' ');

        }
        putchar(b & mask ? '1' : '0');
        b <<= 1;

    }
    cout << "\n |Экспонента|--------Мантисса-------|" << endl;
    cout << "\n";
    
    cout << "~~~~~ 4 задание ~~~~~\n";
    cout << "Введите значение типа double \n";


    union {
        double num;
        int num3[2];
    };

    cin >> num;

    int a2 = 32;
    int mask2 = 1 << (a2 - 1);

    for (int i = 0; i < a2; i++) {
        if (i == 1 || i % 8 == 0 || i == 12)
            cout << " ";
        cout << (num3[1] & mask2 ? '1' : '0');
        num3[1] <<= 1;
    }

    for (int i = 0; i < a2; i++) {
        if (i % 8 == 0)
            cout << " ";
        cout << (num3[0] & mask2 ? '1' : '0');
        num3[0] <<= 1;
    }

    cout << "\n   | Экспонента |-------------------------Мантисса-------------------------| \n";
}