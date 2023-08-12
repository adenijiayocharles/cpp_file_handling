// Question: Write a C++ program to create a new text file and write some text into it.
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using std::filesystem::current_path;

int main()
{
    ofstream myFile;

    // get the current working directory
    string currentDirectory = current_path();
    string fileName = "/exercise1.txt";
    string file = currentDirectory + fileName;

    // open a new file with the ofstream file handler
    myFile.open(file);

    // check if the file is opened
    // write text into the file
    if (myFile.is_open())
    {
        myFile << "Charles Ayodipupo Adeniji: This is the first exercise in file handling";
        // close the file
        myFile.close();
        cout << "file written to and closed";
    }
    else
    {
        cout << "Unable to open the file for writing" << endl;
    }

    return 0;
}
