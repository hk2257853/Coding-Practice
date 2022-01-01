#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

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

	for (int p = 0; p < 5; p++)
	{
		for (int q = p + 1; q < 5; q++)
		{
			if (n1[p] > n1[q])
			{
				temp = n1[p];
				n1[p] = n1[q];
				n1[q] = temp;
			}
		}
	}
	temp = 0;
	for (int p = 0; p < 3; p++)
	{
		for (int q = p + 1; q < 3; q++)
		{
			if (n2[p] > n2[q])
			{
				temp = n2[p];
				n2[p] = n2[q];
				n2[q] = temp;
			}
		}
	}

	while (i < 5 && j < 3)
	{
		if (n1[i] <= n2[j])
		{
			n3[k] = n1[i];
			k++;
			i++;
		}
		else
		{
			n3[k] = n2[j];
			k++;
			j++;
		}
	}
	while (i < 5)
	{
		n3[k] = n1[i];
		i++;
		k++;
	}
	while (j < 3)
	{
		n3[k] = n2[j];
		j++;
		k++;
	}
	file.open("final_list.txt", ios::out);
	file.write((char *)&n3, sizeof n3);
	file.close();

	file.open("list1.txt", ios::in);
	file.read((char *)&n1, sizeof(n1));
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
