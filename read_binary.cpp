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
    string fileName = "/numbers.dat";
    string file = currentDirectory + fileName;

    // numbers array
    int numbers[3];

    // open a new file with the ifstream file handler
    ifstream myFile;
    myFile.open(file, ios::binary);

    // check if the file is opened
    // read from the file
    if (myFile.is_open())
    {
        int number;
        while (myFile.read(reinterpret_cast<char *>(&number), sizeof(number)))
        {
            cout << number;
        }
        myFile.close();
    }
    else
    {
        cout << "Unable to open the file for writing" << endl;
    }

    return 0;
}
