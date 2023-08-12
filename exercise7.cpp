// Write a C++ program to append new data to an existing text file.
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using std::filesystem::current_path;

int main()
{
    // get the current working directory
    string currentDirectory = current_path();
    string fileName = "/exercise1.txt";
    string file = currentDirectory + fileName;

    // initialise ostream file handler
    ofstream myFile;

    // open the file with append write mode passed as second param
    myFile.open(file, ios::app);

    if (myFile.is_open())
    {
        // ask user for a string to append to the file
        string word;
        cout << "Please input any sentence of your choice: ";
        getline(cin, word);

        // append word to end of file
        myFile << "\n"
               << word;

        // close the file
        myFile.close();
    }

    // print each line from the file to confirm code worked
    ifstream readFile;
    readFile.open(file);
    if (readFile.is_open())
    {
        string line;
        while (getline(readFile, line))
        {
            cout << line << endl;
        }
        readFile.close();
    }
    else
    {
        cout << "Unable to open file for reading";
    }

    return 0;
}