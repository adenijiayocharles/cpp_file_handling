// Create a C++ program to alphabetically organise the lines in a text file.
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
    string fileNameSorted = "/wordlist_sorted.txt";
    string file = currentDirectory + fileName;
    string fileSorted = currentDirectory + fileNameSorted;

    // initialise file handlers
    ifstream myFile;

    // open the file with append write mode passed as second param
    myFile.open(file);

    // string vector variables to store all the lines in the text file
    vector<string> words;

    // check if the file is open
    if (myFile.is_open())
    {
        string lineContent;
        while (getline(myFile, lineContent))
        {
            words.push_back(lineContent);
        }

        myFile.close();
    }

    // sort the vector alphabetically
    sort(words.begin(), words.end());

    // writ sorted lines back into the file
    ofstream inputFile;
    inputFile.open(fileSorted, std::ios::app);
    for (string word : words)
    {
        inputFile << word << endl;
    }

    return 0;
}