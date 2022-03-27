#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
// search n display contact

class phoneBook
{
	char *ph_no;
	char *name;

public:
	phoneBook()
	{
		this->ph_no = new char[20];
		this->name = new char[50];
	}
	char *get_name()
	{
		return this->name;
	}
	void createContact();
	void updateContact();
	void displayContact();
};
void phoneBook::createContact()
{
	cout << "Enter Name: ";
	cin.getline(this->name, 50);
	cin.getline(this->name, 50);
	cout << "Enter Ph. no: ";
	cin.getline(this->ph_no, 20);
	cout << endl;
}
void phoneBook::updateContact()
{
	cout << "Enter new Ph. no: ";
	cin.getline(this->ph_no, 20);
	cout << "~Updated Contact\n";
}
void phoneBook::displayContact()
{
	cout << "Name: " << name << endl;
	cout << "Ph. No: " << ph_no << endl;
}
void print_menu(int &choice)
{
	cout << "(0)QUIT\t\t(1)Create New Contact\t\t(2)Display Contacts\t\t(3)Update Contacts\t\t(4)Search Contact\n";
	cout << "Your Choice: ";
	cin >> choice;
}
int main()
{
	phoneBook c1[100], c2[100];
	int choice, cnt = 0, i, flag = 0;
	char *search_name = new char[100];
	do
	{
		print_menu(choice);
		switch (choice)
		{
		case 0:
			break;
		case 1:
		{
			if (cnt == 0)
			{
				ofstream fout;
				fout.open("Phonebook.txt");
				c1[cnt].createContact();
				fout.write((char *)&c1[cnt], sizeof(c1[cnt]));
				fout.close();
			}
			if (cnt > 0)
			{
				ofstream fout;
				fout.open("Phonebook.txt", ios::app);
				c1[cnt].createContact();
				fout.write((char *)&c1[cnt], sizeof(c1[cnt]));
				fout.close();
			}
			cnt++;
			break;
		}
		case 2:
		{
			ifstream fin;
			fin.open("Phonebook.txt");
			fin.seekg(0);
			i = 0;
			while (fin.read((char *)&c1[i], sizeof(c1[i])))
			{
				cout << "\n----------\nContact " << i + 1 << "\n----------" << endl;
				c1[i].displayContact();
				i++;
			}
			cout << endl;
			fin.close();
			break;
		}
		case 3:
		{
			cout << "Enter the name of contact you want to update: ";
			// or use cin.ignore()
			cin.getline(search_name, 100);
			cin.getline(search_name, 100);
			flag = 0;
			i = 0;
			fstream file("Phonebook.txt", ios::in | ios::out);
			file.seekg(0);
			while (file.read((char *)&c1[i], sizeof(c1[i])))
			{
				if (strcmp(c1[i].get_name(), search_name) == 0)
				{
					flag = 1;
					c1[i].updateContact();
					file.write((char *)&c1[i], sizeof(c1[i]));
					file.close();
				}
				i++;
			}
			file.close();
			if (flag == 0)
				cout << "Contact Not Found!\n";
			break;
		}
		case 4:
			cout << "Enter name: ";
			// or use cin.ignore()
			cin.getline(search_name, 100);
			cin.getline(search_name, 100);
			flag = 0;
			i = 0;
			fstream file("Phonebook.txt", ios::in | ios::out);
			file.seekg(0);
			while (file.read((char *)&c1[i], sizeof(c1[i])))
			{
				if (strcmp(c1[i].get_name(), search_name) == 0)
				{
					flag = 1;
					c1[i].displayContact();
					file.close();
				}
				i++;
			}
			file.close();
			if (flag == 0)
				cout << "Contact Not Found!\n";
			break;
		}
	} while (choice != 0);

	return 0;
}
