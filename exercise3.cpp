// Write a C++ program to count the number of lines and characters on each line in a text file.
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

    // number of lines variable
    int numberOfLines;

    // open a new file with the ifstream file handler
    ifstream myFile;
    myFile.open(file);

    // check if the file is opened
    // read from the file
    if (myFile.is_open())
    {
        string lineFromFile;
        int characterCount;
        // close the file
        while (std::getline(myFile, lineFromFile))
        {
            numberOfLines++;
            cout << "Line " << numberOfLines << endl;
            cout << lineFromFile << endl;
            cout << "Number of characters " << lineFromFile.length() << endl;
            cout << "---------------" << endl;
            cout << endl;
        }
        cout << "---------------" << endl;
        cout << "Number of lines " << numberOfLines;
        myFile.close();
    }
    else
    {
        cout << "Unable to open the file for reading" << endl;
    }

    return 0;
}
