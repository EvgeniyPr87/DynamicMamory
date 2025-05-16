#include "functions.h"
#include"stdafx.h"

void Print(const int* arr, const int& n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 100;
		}
	}
}
int* push_front(int* arr, int& n,int a)
{
	int* buffer = new int[n + 1];
	if (buffer == nullptr)
	{
		cout << "! Erorr.Memory is not allocated !" << endl;
		delete[]arr;
		arr = nullptr;
		return nullptr;
	}
		buffer[0] = a;
	for (int i = 0; i < n ; i++) {
		buffer[i+1] = arr[i];
	}
	delete[]arr;
	arr = nullptr;
	n++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int& cols)
{
	int** buffer = new int* [rows + 1];

	if (buffer == nullptr) {
		cout << "! Erorr.Memory is not allocated !" << endl;
		return nullptr;
	}

	for (int i = 0; i < rows; i++) {
		buffer[i+1]=arr[i];
	}
	delete[]arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** push_col_front(int** arr, const int& rows, int& cols)
{
	int** buffer = new int* [rows];
	if (buffer == nullptr) {
		cout << "! Erorr.Memory is not allocated !" << endl;
		return nullptr;
	}

	for (int i = 0; i < rows; i++) {
		buffer[i] = new int[cols + 1] {};
	//buffer[i][0] = 0;
		for (int j = 0; j < cols; j++) {
		buffer[i][j + 1] = arr[i][j];
	}
	}
Clear(arr, rows, cols);
	//for (int i = 0; i < rows; i++) {
	//	delete[]arr[i];
	//}
	//delete[]arr; 
	cols++;
	return buffer;
}
int* push_back(int* arr, int& n)
{
	int* buffer = new int[n + 1] {0};
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = nullptr;
	n++;
	return buffer;
}
int** push_row_back(int** arr, int& rows, const int& cols)
{
	int** buffer = new int* [rows + 1];
	if (buffer == nullptr) {
		cout << "! Erorr.Memory is not allocated !" << endl;
		return nullptr;
	}

	for (int i = 0; i < rows; i++) {
		buffer[i] = arr[i];
	}
	delete[]arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** push_col_back(int** arr, const int& rows, int& cols)
{
	int** buffer = new int* [rows];
	if (buffer == nullptr) {
		cout<< "! Erorr.Memory is not allocated !" << endl;
		return nullptr;
	}
	for (int i = 0; i < rows; i++) {
		buffer[i] = new int[cols + 1]{};
		if (buffer == nullptr) {
			cout << "! Erorr.Memory is not allocated !" << endl;
			for (int j = 0; j < i; j++) {
				delete[]arr[j];
			}
			delete[]buffer;
			return nullptr;
			
		}
		for (int j = 0; j < cols; j++) {
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr,rows,cols);
	cols++;
	return buffer;
}
int* insert(int* arr, int& n, const int& index)
{
	int* buffer = new int[n + 1] {0};
	if(buffer==nullptr)
	{
		cout << "! Erorr.Memory is not allocated !" << endl;
		delete[]arr;
		arr = nullptr;
		return nullptr;
	}
		for (int i = 0; i < index; i++) {
			buffer[i] = arr[i];
		}
		for (int i = index; i < n ; i++) {
			buffer[i+1] = arr[i];
		}
	delete[]arr;
	arr = nullptr;
	n++;
	return buffer;
}
int** insert_row(int** arr, int& rows, const int& cols, int index_rows)
{
	int** buffer = new int* [rows + 1];

	if (buffer == nullptr) {
		cout << "! Erorr.Memory is not allocated !" << endl;
		return nullptr;
	}

		for (int i = 0; i < index_rows; i++) {
			buffer[i] = arr[i];
		}
		for (int i = index_rows; i<rows+1 ; i++) {
			buffer[i + 1] = arr[i];
	}
	
	delete[]arr;
	rows++;
	buffer[index_rows] = new int[cols] {};
	return buffer;
}
int** insert_col(int** arr, const int& rows, int& cols, int index_cols)
{
	int** buffer = new int* [rows];

	for (int i = 0; i < rows; i++) {
		buffer[i] = new int [cols + 1];

		buffer[i][index_cols] = 0;
		for (int j = 0; j < index_cols; j++) {
			buffer[i][j] = arr[i][j];
		}
		for (int j = index_cols; j < cols; j++) {
			buffer[i][j+1] = arr[i][j];
		}
	}
	Clear(arr, rows, cols);
	////удаляем массив
	//for (int i = 0; i < rows; i++) {
	//	delete[]arr[i];
	//}
	//delete[]arr;
	cols++;
	return buffer;
}
int* pop_back(int* arr, int& n)
{
	if (n <= 0)
	{
		cout << "Error" << endl;
		return arr;
	}
	int* buffer = new int[n - 1];
	if (buffer == nullptr)
	{
		cout << "! Erorr.Memory is not allocated !" << endl;
		delete[]arr;
		arr = nullptr;
		return nullptr;
	}
	for (int i = 0; i < n-1 ; i++) {
		buffer[i] = arr[i];
	}
	n--;
	delete[]arr;
	arr = nullptr;
	return buffer;
}
int** pop_row_back(int** arr, int& rows, const int& cols)
{
	if (rows <= 0) {
		cout << "Error" << endl;
		return arr;
	}
	int** buffer = new int* [rows - 1];
	if (buffer == nullptr) {
		cout << "! Erorr.Memory is not allocated !" << endl;
		return nullptr;
	}
	for (int i = 0; i < rows-1; i++) {
		buffer[i] = arr[i];
	}
	rows--;
	delete[]arr;
	return buffer;
}
int** pop_col_back(int** arr, const int& rows, int& cols)
{
	int** buffer = new int* [rows];

	for (int i = 0; i < rows; i++) {
		buffer[i] = new int[cols - 1];

		for (int j = 0; j < cols-1; j++) {
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr, rows, cols);
	/*for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[]arr;*/
	cols--;
	return buffer;
}
int* pop_front(int* arr, int& n)
{
	if (n <= 0)
	{
		cout << "Error" << endl;
		return arr;
	}
	int* buffer = new int[n - 1];
	if (buffer == nullptr)
	{
		cout << "! Erorr.Memory is not allocated !" << endl;
		delete[]arr;
		arr = nullptr;
		return nullptr;
	}
	for (int i = 0; i < n-1; i++) {
		buffer[i] = arr[i+1];
	}
		n--;
		delete[]arr;
		arr = nullptr;
		return buffer;
}
int** pop_row_front(int** arr, int& rows, const int& cols)
{
	if (rows <= 0) {
		cout << "Error" << endl;
		return arr;
	}
	int** buffer = new int* [rows - 1];
	if (buffer == nullptr) {
		cout << "! Erorr.Memory is not allocated !" << endl;
		return nullptr;
	}
	for (int i = 0; i < rows; i++) {
		buffer[i] = arr[i+1];
	}
	rows--;
	delete[]arr;
	return buffer;
}
int** pop_col_front(int** arr, const int& rows, int& cols)
{
	int** buffer = new int* [rows];

	for (int i = 0; i < rows; i++) {
		buffer[i] = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++) {
			buffer[i][j] = arr[i][j+1];
		}
	}
	Clear(arr, rows, cols);
	/*for (int i = 0; i < rows; i++) {
		delete[]arr[i];
	}
	delete[]arr;*/
	cols--;
	return buffer;
}
int* erase(int* arr, int& n, const int& index)
{
	if (n <= 0)
	{
		cout << "Error" << endl;
		return arr;
	}
	int* buffer = new int[n - 1];
	if (buffer == nullptr)
	{
		cout << "! Erorr.Memory is not allocated !" << endl;
		delete[]arr;
		arr = nullptr;
		return nullptr;
	}
	
	for (int i = 0; i < index; i++) {
		buffer[i] = arr[i];
	}
	for (int i = index; i < n - 1; i++) {
		buffer[i] = arr[i+1];
	}
		n--;
		delete[]arr;
		arr = nullptr;
		return buffer;
	}
int** erase_row(int** arr, int& rows, const int& cols, int index_rows)
{
	if (rows <= 0) {
		cout << "Error" << endl;
		return arr;
	}
	int** buffer = new int* [rows - 1];

	if (buffer == nullptr) {
		cout<< "! Erorr.Memory is not allocated !" << endl;
		return nullptr;
	}

	for (int i = 0; i < index_rows; i++) {
		buffer[i] = arr[i];
	}
	for (int i = index_rows; i < rows-1; i++) {
		buffer[i] = arr[i+1];
	}
	rows--;
	delete[]arr;
	return buffer;
}
int** erase_col(int** arr,  int& rows, int& cols, int index_col)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++) {
		buffer[i] = new int[cols - 1];
		for (int j = 0; j < index_col; j++) {
			buffer[i][j] = arr[i][j];
		}
		for (int j = index_col; j < cols; j++) {
			buffer[i][j] = arr[i][j+1];
		}
	}
	Clear(arr, rows, cols);
	/*for (int i = 0; i < rows; i++) {
		delete[]arr[i];
	}
	delete[]arr;*/
	cols--;
	return buffer;
}
void Clear(int** arr, const int& rows, int& cols)
{
	//сначала удаляем строки
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	//удаляем массив указателей
	delete[]arr;
}
void Allocate(int**arr,const int& rows, const int& cols)
{
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
}
