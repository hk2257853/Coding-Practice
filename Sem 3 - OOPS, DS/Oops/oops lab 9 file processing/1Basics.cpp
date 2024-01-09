#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    fstream f1;
    f1.open("basics.txt", ios::in | ios::out | ios::app);

    // write
    f1 << "Hello word!" << endl;
    f1 << "Hello word!" << endl;

    // read
    f1.seekg(0, ios::beg); // seekg is used to move the pointer to the beginning of the file
    char ch;
    while (f1)
    {
        f1.get(ch);
        cout << ch;
    }
    cout << endl;

    f1.clear(); // clear the eof flag to enable further operations on the file
    // Search for a word
    f1.seekg(0, ios::beg);
    char word[20];
    cout << "Enter the word to be searched: ";
    cin >> word;
    int count = 0;
    char buffer[20];
    while (f1 >> buffer)
    {
        if (strcmp(buffer, word) == 0)
            count++;
    }
    cout << "The given word appears: " << count << " times" << endl;

    // update a word
    f1.clear();
    f1.close(); // close the file

    f1.open("basics.txt", ios::in | ios::out); // reopen the file in read-write mode

    // TODO: update (not working)
    f1.seekg(0, ios::beg); // move read pointer to the beginning
    f1.seekp(0, ios::beg); // move write pointer to the beginning
    char word1[20], word2[20];
    cout << "Enter the word to be replaced: ";
    cin >> word1;
    cout << "Enter the word to be replaced with: ";
    cin >> word2;
    while (f1 >> buffer)
    {
        if (strcmp(buffer, word1) == 0)
        {
            f1.seekp(-strlen(word1), ios::cur); // seekp is used to move the pointer to the current position. Here we are moving the pointer to the beginning of the word to be replaced
            f1 << word2;
        }
    }

    // read
    f1.clear();
    f1.seekg(0, ios::beg);
    while (f1)
    {
        f1.get(ch);
        cout << ch;
    }
    cout << endl;

    f1.close();
    return 0;
}
