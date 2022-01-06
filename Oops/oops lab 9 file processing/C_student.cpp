#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <conio.h>
#define MAX 100
using namespace std;

class student
{
	char name[20], add[20], branch[20], roll_no[20];

public:
	student()
	{
		strcpy(name, "");
		strcpy(branch, "");
		strcpy(add, "");
		strcpy(roll_no, "");
	}
	void getdata();
	void showdata();
	void update_data(char *ID);
	char *get_rollno() { return roll_no; }
};

void student ::getdata()
{
	cin.ignore(); // if not put skips some inputs. On net it said its to skip some inputs.
	cout << "Enter details:-\n";
	cout << "NAME: ";
	cin.getline(name, 20);
	cout << "ADDRESS: ";
	gets(add);
	cout << "ROLL NO: ";
	gets(roll_no);
	cout << "BRANCH: ";
	gets(branch);
}

void student ::showdata()
{

	cout << "----------------------------------------------------------------------------" << endl;
	cout << left << setw(15) << "NAME" << setw(15) << "BRANCH" << setw(25) << "ADDRESS" << setw(15) << "ROLL NO" << endl;
	cout << left << setw(15) << name << setw(15) << branch << setw(25) << add << setw(4) << right << roll_no << endl;
	cout << "----------------------------------------------------------------------------" << endl;
}
void student ::update_data(char *ID)
{
	cin.ignore();
	strcpy(roll_no, ID);
	cout << "Enter details:-\n";
	cout << "NAME: ";
	cin.getline(name, 20);
	cout << "ADDRESS: ";
	gets(add);
	cout << "BRANCH: ";
	gets(branch);
}
int main()
{
	student *st[MAX];
	char ID[20];
	int found = 0;
	int n = 0, num, choice;
	cout.setf(ios::fixed | ios::showpoint);
	;

	while (1)
	{
		cout << "__STUDENT DATABASE__";
		cout << "\n(1) Enter student details: ";
		cout << "\n(2) Update student details: ";
		cout << "\n(3) Display Student details: ";
		cout << "\n(4) EXIT!";
		cout << "\nMake your choice : ";
		cin >> choice;

		switch (choice)
		{

		case 1:
		{
			st[n] = new student();
			st[n]->getdata();
			ofstream fout;
			fout.open(st[n]->get_rollno(), ios::trunc | ios::binary);

			fout.write((char *)&*st[n], sizeof(*st[n]));
			fout.close();
			cin.get();
			n++;
			break;
		}

		case 2:
		{

			cout << "Enter student ROLL NO: ";
			cin.ignore();
			gets(ID);
			ofstream fout;
			for (int i = 0; i < n; i++)
			{

				if (!strcmp(ID, st[i]->get_rollno()))
				{

					cout << "\n\nEnter new details of Student:-" << endl;
					cout << "\nPress any key to enter:-";
					st[i]->update_data(ID);

					fout.open(st[i]->get_rollno(), ios::trunc | ios::binary);
					fout.clear();
					fout.write((char *)&*st[i], sizeof(*st[i]));
					found++;
					break;
				}
			}
			fout.close();
			if (found == 0)
				cout << "\n---Record does not exist!---";
			cin.get();
			break;
		}

		case 3:
		{
			cout << "Enter student ROLL NO: ";
			cin.ignore();
			gets(ID);
			int flag = 0;
			student temp;
			ifstream fin;
			fin.open(ID);

			if (fin.good())
			{
				fin.read((char *)&temp, sizeof(temp));
				temp.showdata();
				flag++;
			}
			fin.close();
			if (flag == 0)
				cout << "\n---Record does not exist!---";
			cin.get(); // for accessing character array
			break;
		}

		case 4:
			exit(0);

		default:
			cout << "\aPlease make a correct choice!";
		}
		cout << "\n\n\n";
	}
	return 0;
}
