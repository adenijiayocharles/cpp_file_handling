// Write a C++ program to copy the contents of one text file to another.
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
    string fileName2 = "/exercise_copy.txt";
    string file2 = currentDirectory + fileName2;

    // initialise ostream file handler
    ifstream myFile;

    // open the file with append write mode passed as second param
    myFile.open(file);

    if (myFile.is_open())
    {
        string lineContent;
        while (getline(myFile, lineContent))
        {

            ofstream myFile2;
            myFile2.open(file2, ios::app);
            if (myFile2.is_open())
            {
                myFile2 << lineContent << "\n";
                myFile2.close();
            }
        }

        myFile.close();
    }

    return 0;
}