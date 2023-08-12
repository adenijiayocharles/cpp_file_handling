// 2. Write a C++ program to open an existing text file and display its contents on the console.
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


    ifstream myFile; 
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
