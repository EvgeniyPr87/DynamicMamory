#include "functions.h"
#include"stdafx.h"

void Print(const int* arr, const int& n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}cout << endl;
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
int* insert(int* arr, int& n, const int& index, const int& a)
{
	int* buffer = new int[n + 1];
	if(buffer==nullptr)
	{
		cout << "! Erorr.Memory is not allocated !" << endl;
		delete[]arr;
		arr = nullptr;
		return nullptr;
	}
	
				
	for (int i = 0; i < n ; i++) {
	
		for (int i = 0; i < index; i++) {
			buffer[i] = arr[i];
			for (int i = index; i < n+1; i++) {
				arr[index] = a;
				buffer[i] = arr[i];
			}
		}
	}
	delete[]arr;
	arr = nullptr;
	n++;
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
	for (int i = 0; i < n - 1; i++) {
		for (int i = 0; i < index; i++) {
			 buffer[i] = arr[i];
			for (int i = index ; i < n - 1; i++) {
				buffer[i] = arr[i];
			}
		}
		n--;
		delete[]arr;
		arr = nullptr;
		return buffer;
	}
}