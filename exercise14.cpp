// Create a C++ program that will read an Excel/CSV file and provide its information in tabular form.
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;
using std::filesystem::current_path;

std::vector<std::string> splitString(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

int main()
{
    // get the current working directory
    string currentDirectory = current_path();
    string fileName = "/test.csv";
    string file = currentDirectory + fileName;
    int encryptionKey = 1;

    // initialise file handlers
    ifstream myFile;

    // variable c to store each character in the text file
    char c;

    // open the file with append write mode passed as second param
    myFile.open(file);

    // check if the file is open
    if (myFile.is_open())
    {
        string lineContent;
        while (getline(myFile, lineContent))
        {
        }
    }

    return 0;
}