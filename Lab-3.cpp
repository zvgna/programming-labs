#include <iostream>
#include <ctime>
#include <iomanip>
#include <Windows.h>
using namespace std;

const int N = 6;

void Show(int(*A)[N]) {
    int* end = A[0] + N * N - 1;

    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            destCoord.X = i * 4;
            destCoord.Y = j;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << A[i][j];
        }
}

void ShakeA(int(*A)[N]) {
    for (int i = 0; i < (N / 2); i++) {
        for (int j = 0; j < N; j++) {
            swap(A[i][j], A[i + (N / 2)][j]);
        }
    }
    for (int i = 0; i < (N / 2); i++) {
        for (int j = 0; j < (N / 2); j++) {
            swap(A[i][j], A[i + (N / 2)][j + (N / 2)]);
        }
    }
}

void ShakeB(int(*A)[N]) {
    for (int i = 0; i < (N / 2); i++) {
        for (int j = 0; j < N; j++) {
            if (j < (N / 2)) {
                swap(A[i][j], A[i + (N / 2)][j + (N / 2)]);
            }
            else {
                swap(A[i][j], A[i + (N / 2)][j - (N / 2)]);
            }
        }
    }
}

void ShakeC(int(*A)[N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (N / 2); j++) {
            swap(A[i][j], A[i][j + (N / 2)]);
        }
    }
}

void ShakeD(int(*A)[N]) {
    for (int i = 0; i < (N / 2); i++) {
        for (int j = 0; j < N; j++) {
            swap(A[i][j], A[i + (N / 2)][j]);
        }
    }
}

void Sort(int(*A)[N]) {
    int* pt = A[0];
    int nm = N * N - 1;
    for (int n = 0; n < N*N; ++n) {
        for (int i = n; i < N*N - 1 - n; ++i) {
            if (*(pt+i) > *(pt + i + 1))
                swap(*(pt + i), *(pt + i + 1));
            if (*(pt + nm - i) < *(pt + nm - i - 1))
                swap(*(pt + nm - i), *(pt + nm - i - 1));
        }
    }
}

int main()
{
    setlocale(0, "");
    srand(time(0));

    int A[N][N];

     {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                A[i][j] = 0;
            }

        Show(A);

        int* end = A[0] + N * N - 1; 

        HANDLE hStdout;
        COORD destCoord;
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        for (int* pt = A[0], i = 0, x = 0, y = 0; pt <= end + (N - 1); pt++, i++, y++) {
            if (i % N == 0 && i != 0) {
                x++;
                y = 0;
                if (x % 2 == 0)
                    pt = &A[x][y];
                else
                    pt = &A[x][y + N - 1];
            }
            if (x % 2 == 0) {
                destCoord.X = x * 4;
                destCoord.Y = y;
                SetConsoleCursorPosition(hStdout, destCoord);
                *pt = 1 + rand() % (N * N);
                cout << *pt;
                Sleep(50);
            }
            else {
                destCoord.X = x * 4;
                destCoord.Y = N - y - 1;
                SetConsoleCursorPosition(hStdout, destCoord);
                *(pt - y - y) = 1 + rand() % (N * N);
                cout << *(pt - y - y);
                Sleep(50);
            }
        }

        cout << "\r";
        for (int i = 1; i <= N; i++)
            cout << "\n";
        system("pause");
    }

    {
        system("cls");
        ShakeA(A);
        Show(A);
        Sleep(2000);

        system("cls");
        ShakeB(A);
        Show(A);
        Sleep(2000);

        system("cls");
        ShakeC(A);
        Show(A);
        Sleep(2000);

        system("cls");
        ShakeD(A);
        Show(A);

        cout << "\n";
        system("pause");
    }

    {
        system("cls");
        Sort(A);
        Show(A);

        cout << "\n";
        system("pause");
    }

    {
        int input;
        string sign;

    Menu: {
        cout << "Напишите через пробел действие ('+', '-', '*', '/') и на сколько вы хотите его выполнить\n";
        cout << "Пример: '+ 5'\n";
        cin >> sign >> input;
        }

    if (sign == "+") {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                A[i][j] += input;
    }
    else if (sign == "-") {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                A[i][j] -= input;
    }
    else if (sign == "*") {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                A[i][j] *= input;
    }
    else if (sign == "/") {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                A[i][j] /= input;
    }
    else {
        goto Menu;
    }

    system("cls");
    Show(A);

    cout << "\n";
    }
}