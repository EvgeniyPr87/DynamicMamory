#include"stdafx.h"
#include"functions.h"

void main() {
	setlocale(LC_ALL, "");
int size = 10;
	int* array= new int [size] { 1,2,35,56,89,7,89,2,10,1 };
	int number;
	for (int i = 0; i < size; i++) {
		cout << array[i] << "\t";
	}cout << endl;

#ifdef PUSH_FRONT
	cout << "Введите элемент: "; cin >> number;
	array = push_front(array, size, number);
	Print(array, size);
	/*for (int i = 0; i < size; i++) {
		cout << array[i] << "\t";
	}cout << endl;*/
	
#endif // PUSH_FRONT

#ifdef INSERT
	int pos;
	int num_2;
	cout << "Введите позицию элемента /1... 10/: "; cin >> pos;
	cout << "Введите значение элемента: "; cin >> num_2;
	array = insert(array, size, num_2, pos);
	for (int i = 0; i < size; i++) {
		cout << array[i] << "\t";
	}cout << endl;

#endif // INSERT

#ifdef POP_BACK
	array = pop_back(array, size);
	Print(array, size);
#endif // POP_BACK

#ifdef POP-FONT
	array = pop_front(array, size);
	Print(array, size);
#endif // POP-FONT
#ifdef ERASE
	int index;
	cout << "Введите индех элемента: "; cin >> index;
	array = erase(array, size, index);
	Print(array, size);
	
#endif // ERASE
	delete[]array;
	array = nullptr;
}