// Create a C++ programme to decode a text file's contents that has been encrypted with the aforementioned algorithm.
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using std::filesystem::current_path;

int main()
{
    // get the current working directory
    string currentDirectory = current_path();
    string fileName = "/encrypted.txt";
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
        // create decrypted file handler
        string encryptedFileName = "/decrypted.txt";
        string encryptedFile = currentDirectory + encryptedFileName;

        ofstream outputFile;
        outputFile.open(encryptedFile, ios::app);

        // loop each xter and encrypt
        while (myFile >> noskipws >> c)
        {
            int temp = c - encryptionKey;
            outputFile << (char)temp;
        }

        outputFile.close();
        myFile.close();
    }

    return 0;
}