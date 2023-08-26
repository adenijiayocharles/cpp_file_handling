// Create a C++ program that searches a text file for a particular string and displays the line number(s) it appears on.
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using std::filesystem::current_path;

int main()
{
    // get the current working directory
    string currentDirectory = current_path();
    string fileName = "/wordlist.txt";
    string file = currentDirectory + fileName;
    string wordToSearchFor = "Nigeria";

    // initialise file handlers
    ifstream myFile;

    // line number variable
    int lineNumber = 0;

    // open the file with append write mode passed as second param
    myFile.open(file);

    if (myFile.is_open())
    {
        string lineContent;
        while (getline(myFile, lineContent))
        {
            lineNumber++;
            if (lineContent == wordToSearchFor)
            {
                cout << "The word you searched for was found on line " << lineNumber << endl;
                break;
            }
        }

        myFile.close();
    }

    return 0;
}