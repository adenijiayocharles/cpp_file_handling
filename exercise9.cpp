// Create a C++ program to combine several text files into one.

#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using std::filesystem::current_path;

int main()
{
    // get the current working directory
    string currentDirectory = current_path();
    vector<string> files = {"/word1.txt", "/word2.txt", "/word3.txt", "/word4.txt"};

    for (string file : files)
    {
        // created the file handler for the files to be combined together
        ifstream wordFile;
        string filePath = currentDirectory + file;
        wordFile.open(filePath);

        if (wordFile.is_open())
        {
            // create file hanlder for combined file

            string lineContent;
            while (getline(wordFile, lineContent))
            {
                string fileName = "/combined-wordlist.txt";
                string file = currentDirectory + fileName;
                ofstream combinedFile;
                combinedFile.open(file, ios::app);

                if (combinedFile.is_open())
                {
                    combinedFile << lineContent << endl;
                    combinedFile.close();
                }
                else
                {
                    cout << "Unable to open file" << endl;
                }
            }
        }

        wordFile.close();
    }

    return 0;
}