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
    string fileName = "/movies.csv";
    string file = currentDirectory + fileName;

    // open a new file with the ifstream file handler
    ofstream myFile;
    myFile.open(file);

    // check if the file is opened
    // read from the file 
    if (myFile.is_open())
    {
        myFile << "id, title, release_date \n";
        myFile << "1, Terminator 1, 1990 \n";
        myFile << "2, Terminator 3, 1992 \n";
        myFile << "3, Terminator 2, 1998 \n";
        myFile.close();
    }
    else
    {
        cout << "Unable to open the file for writing" << endl;
    }

    return 0;
}
