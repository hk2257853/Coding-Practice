#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
// read from files n not arry for 3rd one

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int n1[5], n2[3], n3[8], i = 0, j = 0, k = 0, temp;
	cout << "enter 5 elements of the first file: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> n1[i];
	}
	cout << "\nenter the 3 elements of the second file: ";
	for (int i = 0; i < 3; i++)
	{
		cin >> n2[i];
	}

	// store in file 1 n 2
	fstream file;
	file.open("list1.txt", ios::out);
	file.write((char *)&n1, sizeof(n1));
	file.seekg(0, ios::beg);
	file.close();
	file.open("list2.txt", ios::out);
	file.write((char *)&n2, sizeof(n2));
	file.seekg(0, ios::beg);
	file.close();

	cout << "\----ndetails stored successfully in the file----\n";
	// display file 1 n 2
	file.open("list1.txt", ios::in);
	file.read((char *)&n1, sizeof(n1)); // array n1 will have file 1's content
	cout << "Elements of File List 1 are: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << n1[i] << endl;
	}
	file.close();
	file.open("List2.txt", ios::in);
	file.read((char *)&n2, sizeof(n2));
	cout << "Elements of File List 2 are: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << n2[i] << endl;
	}
	file.close();

	// sort b4 putting in file 3
	for (int i = 0; i < 5; i++)
	{
		n3[i] = n1[i];
	}
	for (int i = 5, j = 0; i < 8; i++, j++)
	{
		n3[i] = n2[j];
	}
	insertionSort(n3, 8);

	// store n display
	file.open("final_list.txt", ios::out);
	file.write((char *)&n3, sizeof n3);
	file.close();

	file.open("final_list.txt", ios::in);
	file.read((char *)&n3, sizeof(n3));
	cout << "Elements of File Ascending are: " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << n3[i] << endl;
	}
	file.close();
	return 0;
}
