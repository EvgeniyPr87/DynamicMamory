#include"stdafx.h"
#include"functions.h"

void main() {
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY
	int size = 10;
	int* array = new int [size] { 1, 2, 35, 56, 89, 7, 89, 2, 10, 1 };
	int number;
	for (int i = 0; i < size; i++) {
		cout << array[i] << "\t";
	}cout << endl;

#ifdef PUSH_FRONT
	cout << "������� �������: "; cin >> number;
	array = push_front(array, size, number);
	Print(array, size);
	/*for (int i = 0; i < size; i++) {
		cout << array[i] << "\t";
	}cout << endl;*/

#endif // PUSH_FRONT

#ifdef PUSH_BACK
	array = push_back(array, size);
	Print(array, size);
#endif // PUSH_BACK


#ifdef INSERT
	int pos;
	//int num_2;
	cout << "������� ������� �������� /1... 10/: "; cin >> pos;
	///cout << "������� �������� ��������: "; cin >> num_2;
	array = insert(array, size, pos);
	Print(array, size);

#endif // INSERT

#ifdef POP_BACK
	array = pop_back(array, size);
	Print(array, size);
#endif // POP_BACK

#ifdef POP_FRONT
	array = pop_front(array, size);
	Print(array, size);
#endif // POP_FRONT
#ifdef ERASE
	int index;
	cout << "������� ����� ��������: "; cin >> index;
	array = erase(array, size, index);
	Print(array, size);

#endif // ERASE
	delete[]array;
	array = nullptr;
#endif // DYNAMIC_MEMORY

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	//������� ������ ���������� 
	int** arr = new int* [rows];
	//�������� ������ ��� ������ ���������� ������������� �������
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
	//Allocate(arr, rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << line << endl;
	int index_r;
#ifdef PUSH_ROW_BACK
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
#endif // PUSH_ROW_BACK

#ifdef PUSH_ROW_FRONT
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
#endif // PUSH_ROW_FRONT

#ifdef INSERT_ROW
	
	cout << "������� ������� ������"; cin >> index_r;
	arr = insert_row(arr, rows, cols, index_r);
	Print(arr, rows, cols);
#endif // INSERT_ROW

#ifdef POP_ROW_BACK
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
#endif // POP_ROW_BACK

#ifdef POP_ROW_FRONT
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
#endif // POP_ROW_BACK

#ifdef ERASE_ROW
	cout << "������� ������� ������"; cin >> index_r;
	arr = erase_row(arr, rows, cols, index_r);
	Print(arr, rows, cols);
#endif // ERASE_ROW

#ifdef PUSH_COL_FRONT
	arr = push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
#endif // PUSH_COL_FRONT

#ifdef PUSH_COL_BACK
	arr = push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
#endif // PUSH_COL_BACK

#ifdef INSERT_COL
	cout << "������� ������� ������� "; cin >> index_r;
	arr = insert_col(arr, rows, cols, index_r);
	Print(arr, rows, cols);
#endif // INSERT_COL

#ifdef POP_COL_BACK
	arr = pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
#endif // POP_COL_BACK

#ifdef POP_COL_FRONT
	arr = pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
#endif // POP_COL_FRONT

#ifdef ERASE_COL
	cout << "������� ������� ������� "; cin >> index_r;
	arr = erase_col(arr, rows, cols, index_r);
	Print(arr, rows, cols);
#endif // ERASE_COL

	Clear(arr, rows, cols);
#endif // DYNAMIC_MEMORY_2

}
