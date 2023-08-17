// Write a C++ program to find and replace a specific word in a text file.
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using std::filesystem::current_path;

int main()
{
    // get the current working directory
    string currentDirectory = current_path();
    string fileName = "/file.txt";
    string file = currentDirectory + fileName;
    string fileName2 = "/file_copy.txt";
    string file2 = currentDirectory + fileName2;
    string wordToSearch = "Lorem";
    string replacement = "Test";

    // initialise file handlers
    ifstream myFile;
    ofstream outputFile;

    // open the file with append write mode passed as second param
    myFile.open(file);

    if (myFile.is_open())
    {
        string lineContent;
        while (getline(myFile, lineContent))
        {
            size_t position = lineContent.find(wordToSearch);
            while (position != string::npos)
            {
                lineContent.replace(position, wordToSearch.length(), "Test");
                position = lineContent.find(wordToSearch, replacement.length());
            }

            outputFile.open(file2, ios::app);
            outputFile << lineContent;
            outputFile.close();
        }

        myFile.close();
    }

    return 0;
}