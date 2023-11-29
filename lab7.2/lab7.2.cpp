/* Вариант 11
Для любого задания лабораторных работ №5 и №6 реализовать ввод,
формирование/обработку и вывод массивов с применением функций.
*/
#include <iostream>

using namespace std;

void _lab5(int n);
int lab5();
void _lab6(int strm, int stn, int k);
int lab6();

int main() {
	setlocale(LC_ALL, "ru");
	int num;
	cout << "Введите 1, чтобы выполнить код к лабораторной номер 5" << endl <<
		"Введите 2, чтобы выполнить код к лабораторной номер 6" << endl;
	cin >> num;
	switch (num) {
	case 1:
		return lab5();
	case 2:
		return lab6();
	default:
		cerr << "Ошибка!!! Такого нет в списке." << endl;
		return 1;
	}
}

/* lab5
Дан массив размера N (N — четное число).
Поменять местами его первый элемент со вторым,
третий — с четвертым и т. д.
*/
int lab5() {
	int n;
	cout << "Введите чётную длину массива n>0: ";
	cin >> n;
	if (n % 2 != 0) {
		cerr << "Не соответствует условию!";
		return 1;
	}
	_lab5(n);
	return 0;
}
void _lab5(int n) {
	int* a = new int[n];
	for (size_t i = 0; i < n; i++) {
		cout << "Введите элемент массива: ";
		cin >> a[i];
	}

	for (size_t i = 0; i < n - 1; i += 2) {
		int f = a[i];
		a[i] = a[i + 1];
		a[i + 1] = f;
	}
	for (size_t i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

/*lab6
Дана матрица размера M × N и
целое число K (1 ≤ K ≤ M).
Удалить строку матрицы с номером K.
*/
int lab6() {
	int strm, stn, k;
	cout << "Введите размер матрицы m x n (m и n не больше 10)" << endl;
	cin >> strm >> stn;
	cout << "Введите целое число K (1 <= K <= M )" << endl;
	cin >> k;
	if ((k < 1) && (k > strm)) {
		cerr << "Ошибка: k не соответствует условию!!!" << endl;
		return 1;
	}
	_lab6(strm, stn, k);
	return 0;
}
void _lab6(int strm, int stn, int k) {
	int** arr = new int* [strm];
	for (int i = 0; i < stn; i++) {
		arr[i] = new int[stn];
	}
	for (size_t i = 0; i < strm; i++) {
		for (size_t j = 0; j < stn; j++) {
			cout << "Введите элемент: ";
			cin >> arr[i][j];
		}
	}

	for (size_t i = k - 1; i < strm - 1; i++) {
		for (size_t j = 0; j < stn; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	strm--;

	for (size_t i = 0; i < strm; i++) {
		for (size_t j = 0; j < stn; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	for (size_t i = 0; i < stn; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	cout << endl << endl;
}