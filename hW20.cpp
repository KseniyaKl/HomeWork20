#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

template <typename T>
void fillArr(T arr[], const int length);

template <typename T>
void showArr(T arr[], const int length);

template <typename T>
int searchIndex(T arr[], const int length, T value, int begin = 0);

template <typename T>
int searchLastIndex(T arr[], const int length, T value, int begin = 0);
//
template <typename T>
T maxElement(T arr[], const int length);
template <typename T>
T minElement(T arr[], const int length);
template <typename T>
double meanValue(T arr[], const int length);

template <typename T>
void range(T arr[], const int length, T value1, T value2);

template <typename T>
T counter(T arr[], const int length, T value1);
int main() {
	setlocale(LC_ALL, "Russian");
	int n=0, m=0;
	const int size = 100;
	int arr[size];
	cout << "Домашнее задание №20.\nМассив: \n";
	fillArr(arr, size);
	showArr(arr, size);
	cout << endl << "Введите элемент, который хотите найти: ";
	cin >> n;
	if (searchIndex(arr, size, n) == -1)
		cout << "Данного элемента нет в массиве.\n";
	else {
		cout << "Первое вхождение элемента в массив: " << searchIndex(arr,size,n) << endl;
		cout << "Последнее вхождение элемента в массив: " << searchLastIndex(arr,size,n) << endl;
		cout << "Количество вхождений элемента в массив: " << counter(arr, size, n) << endl;
	}
	


	cout << endl << "Введите начало диапазона: ";
	cin >> n;
	cout << "Введите конец диапазона: ";
	cin >> m;
	cout << "Элементы массива, которые входят в переданный в функцию диапазон: ";
	range(arr, size, n, m);

	cout << "Максимальное число = " << maxElement(arr,size) << endl;
	cout << "Минимальное число = " << minElement(arr,size) << endl;
	cout << "Среднее арифметическое всех элементов = " << meanValue(arr, size) << endl;
	cout << "\nКонец!\n";

	return 0;
}
template <typename T>
void fillArr(T arr[], const int length) {
	srand(time(0));
	for (int i = 0; i < length; i++)
		arr[i] = rand()%(100+1+100)-100;
}
template <typename T>
void showArr(T arr[], const int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

template <typename T>
int searchIndex(T arr[], const int length, T value, int begin) {
	for (int i = begin; i < length; i++)
		if (arr[i] == value)
			return i;
	return -1; 
}
template <typename T>
int searchLastIndex(T arr[], const int length, T value, int begin) {
	for (int i = length - 1; i >= 0; i--) {
		if (arr[i] == value)
			return i;
	}
	return -1;
}
template <typename T>
T maxElement(T arr[], const int length) {
	T max = arr[0];
	for (int i = 0; i < length; i++) {
		max = (arr[i] > max) ? arr[i] : max;
	}
	return max;
}
template <typename T>
T minElement(T arr[], const int length) {
	T min = arr[0];
	for (int i = 0; i < length; i++) {
		min = (arr[i] < min) ? arr[i] : min;
	}
	return min;
}
template <typename T>
double meanValue(T arr[], const int length) {
	T sum = 0;
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}
	return sum/100.0;
}
template <typename T>
void range(T arr[], const int length, T value1, T value2) {
	for (int i = 0; i < length; i++) {
		if (arr[i] >= value1 and arr[i] <= value2)
			cout << arr[i] << ", ";
	}	
	cout << "\b\b.\n\n";
}
template <typename T>
T counter(T arr[], const int length, T value) {
	int count = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == value)
			count++;
	return count;
	}
