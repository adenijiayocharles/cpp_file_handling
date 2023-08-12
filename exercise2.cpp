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

    // open a new file with the ifstream file handler
    ifstream myFile;
    myFile.open(file);

    // check if the file is opened
    // read from the file
    if (myFile.is_open())
    {
        string lineFromFile;
        // close the file
        while (std::getline(myFile, lineFromFile))
        {
            cout << lineFromFile << endl;
        }
        myFile.close();
    }
    else
    {
        cout << "Unable to open the file for reading" << endl;
    }

    return 0;
}
