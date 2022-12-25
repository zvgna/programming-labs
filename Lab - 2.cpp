#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void shakerSort(int A[]) {
	for (int n = 100; n > 0; --n) {
		for (int i = 0; i < n - 1; ++i) {
			if (A[i] > A[i + 1])
				swap(A[i], A[i + 1]);
		}
		for (int i = n - 2; i > 0; --i) {
			if (A[i] < A[i - 1])
				swap(A[i], A[i - 1]);
		}
	}
}

void viewArray(int A[], int n=100) {
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\n";
}

void twoArray(int A[]) {
	int B[50], C[50];
	for (int i = 0; i < 50; i++)
		B[i] = A[i];

	for (int i = 50; i < 100; i++)
		C[i-50] = A[i];
	cout << "Изначальный массив";
	viewArray(A);
	cout << "\n";
	cout << "Первая половина изначального массива\n";
	viewArray(B, 50);
	cout << "\n";
	cout << "Вторая половина изначального массива\n";
	viewArray(C, 50);
	cout << " \n";
	for (int i = 0; i < 50; i++) {
		if (B[i] % 2 != 0) {
			for (int j = 0; j < 50; j++) {
				if (C[j] % 2 == 0) {
					swap(B[i], C[j]);
					break;
				}
			}
		}
	}
	cout << "Результат задания\n";
	viewArray(B, 50);
	cout << "\n";
	cout << "Результат задания\n";
	viewArray(C, 50);
	cout << "\n";
	for (int i = 0; i < 50; i++)
		if (C[i] % 2)
			C[i]++;
	cout << "Результат задания\n";
	viewArray(C, 50);
	cout << "\n";
	int result = 0;
	for (int i = 0; i < 50; i++)
		if (B[i] > C[i])
			result++;
	cout << "Количество эллементов " << result << endl;
}

void menu() {
	cout << "1. Сгенерировать новый массив\n";
	cout << "2. Отсортировать заданный массив сортировкой (от меньшего к большему)\n";
	cout << "3. Найти максимальный и минимальный элемент массива\n";
	cout << "4. Выводит среднее значение максимального и минимального значения в отсортированном и неотсортированном массиве\n";
	cout << "5. Найти количество элементов меньших числа X\n";
	cout << "6. Найти количество элементов больших числа X\n";
	cout << "7. Поиск числа в массиве\n";
	cout << "8. Поменять местами элементы массива\n";
	cout << "9. Индивидуальное задание\n";
	cout << "0. Выход из программы\n";
	cout << "Введите номер операции: \n";
}

void handleForCase1(int Ar[]) {
	cout << "Новый массив:\n";
	srand(time(0));
	for (int i = 0; i < 100; ++i)
		Ar[i] = -99 + rand() % 199;
	viewArray(Ar);
	cout << "\n";
}

void handleForCase2(int A[]) {
	auto start = chrono::steady_clock::now();
	shakerSort(A);
	auto end = chrono::steady_clock::now();
	duration<double> sec = end - start;
	viewArray(A);
	cout << "\nВремя затраченное на сортировку:" << chrono::duration_cast<chrono::microseconds>(end - start).count() << " микросекунд\n\n";
}

void handleForCase3(int A[]) {
	shakerSort(A);
	int min, max;
	auto start = chrono::steady_clock::now();
	min = A[0];
	max = A[99];
	auto end = chrono::steady_clock::now();

	cout << "Максимальный элемент: " << max << "\nМинимальный элемент: " << min << "\n";
	cout << "Отсортированный: ";
	cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n";

	min = A[0];
	max = A[0];
	start = chrono::steady_clock::now();
	for (int i = 0; i < 100; i++) {
		if (A[i] > max)
			max = A[i];
		if (A[i] < min)
			min = A[i];
	}
	end = chrono::steady_clock::now();

	cout << "Неотсортированный: ";
	cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n\n";
}

void handleForCase4(int A[]) {
	shakerSort(A);
	int max = A[99], min = A[0];
	double mid = round((max + min) / 2);
	cout << "Среднее значение: " << mid << "\n";

	auto start = chrono::steady_clock::now();
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (A[i] == mid)
			count += 1;
	}
	auto end = chrono::steady_clock::now();

	cout << "Найдено " << count << " похожих чисел. Они находятся на позициях: ";

	for (int i = 0; i < 100; i++) {
		if (A[i] == mid)
			cout << i + 1 << " ";
	}
	cout << "\nВремя поиска: ";
	cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n\n";
}

void handleForCase5(int A[]) {
	int x, count = 0;
	cout << "Введите число X: ";
	cin >> x;

	shakerSort(A);
	for (int i = 0; i < x; i++) {
		if (A[i] < x)
			count += 1;
		else break;
	}
	cout << "Кол-во элементов меньших " << x << " = " << count << "\n\n";
}

void handleForCase6(int A[]) {
	int x, count = 0;
	cout << "Введите число X: ";
	cin >> x;

	shakerSort(A);
	for (int i = 99; i >= 0; i--) {
		if (A[i] > x)
			count += 1;
		else break;
	}
	cout << "Кол-во элементов больших " << x << " = " << count << "\n\n";
}

void handleForCase7(int A[]) {
	shakerSort(A);
	int left = -99, right = 99;
	int mid, key;

	cout << "Введите искомое число: ";
	cin >> key;
	auto start = chrono::steady_clock::now();
	while (left < right) {
		mid = (left + right) / 2;

		if (A[mid] > key)
			right = mid;
		else
			left = mid + 1;
	}
	right -= 1;
	auto end = chrono::steady_clock::now();

	if (A[right] == key)
		cout << "\nТакое число в массиве есть\n";
	else
		cout << "\nТакого числа в массиве нет\n";

	cout << "Время поиска: ";
	cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n";

	start = chrono::steady_clock::now();
	bool k = false;
	for (int i = 0; i < 100; i++) {
		if (A[i] == key) {
			k = true;
		}
	}

	end = chrono::steady_clock::now();
	cout << "Время поиска перебором: ";
	cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n\n";
}

void handleForCase8(int A[]) {
	int x1, x2;
	cout << "Введите 2 элемента, которые вы хотите поменять местами: ";
	cin >> x1 >> x2;
	cout << "\n";

	auto start = chrono::steady_clock::now();
	swap(A[x1 - 1], A[x2 - 1]);
	auto end = chrono::steady_clock::now();

	viewArray(A);

	cout << "Скорость обмена: ";
	cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n\n";
}

int main() {
	setlocale(0, "");

	int input = 1;
	int A[100];

	srand(time(0));

	cout << "Так выглядит изначальный массив:\n";

	for (int i = 0; i < 100; ++i)
		A[i] = -99 + rand() % 199;

	viewArray(A);
	cout << "\n";
}
	

{	while (input) {
	menu();
	cin >> input;
	cout << "\n";
	switch (input) {
	case 1: {
		handleForCase1(A);
		break;
	}

	case 2: {
		handleForCase2(A);
		break;
	}

	case 3: {
		handleForCase3(A);
		break;
	}

	case 4: {
		handleForCase4(A);
		break;
	}

	case 5: {
		handleForCase5(A);
		break;
	}

	case 6: {
		handleForCase6(A);
		break;
	}

	case 7: {
		handleForCase7(A);
		break;
	}

	case 8: {
		handleForCase8(A);
		break;
	}


	case 9: {
		twoArray(A);
		break;
	}
	case 0: {
		exit;
	}

	default: {
		cout << "Что-то снова пошло не так, давай заново. \n\n";
	}
	}
}
}