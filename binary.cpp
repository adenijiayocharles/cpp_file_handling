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
    int numbers[] = {1000000, 2000000, 3000000};

    // open a new file with the ifstream file handler
    ofstream myFile;
    myFile.open(file, ios::binary);

    // check if the file is opened
    // read from the file
    if (myFile.is_open())
    {
        myFile.write(reinterpret_cast<char *>(&numbers), sizeof(numbers));
        myFile.close();
    }
    else
    {
        cout << "Unable to open the file for writing" << endl;
    }

    return 0;
}
