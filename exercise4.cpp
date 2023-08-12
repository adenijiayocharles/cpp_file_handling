// Write a C++ program to count the number of words in a text file.
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;
using std::filesystem::current_path;

int main()
{
    int numberOfWords;

    // get the current working directory
    string currentDirectory = current_path();
    string fileName = "/exercise1.txt";
    string file = currentDirectory + fileName;

    // initialise ostream file handler
    ifstream myFile;

    // open the file with append write mode passed as second param
    myFile.open(file);

    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            stringstream words(line);
            string Word;
            while (words >> Word)
            {
                numberOfWords++;
            }
        }
        cout << "The total number of words in the file is " << numberOfWords;
        // close the file
        myFile.close();
    }

    return 0;
}