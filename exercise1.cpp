// Question: Write a C++ program to create a new text file and write some text into it.
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myFile;
    string filePath = "/Users/adenijiayocharles/Documents/programming/cpp-projects/exercises/file_handling/exercise1.txt";
    // open a new file with the ofstream file handler
    myFile.open(filePath);

    // check if the file is opened
    // write text into the file
    if (myFile.is_open())
    {
        myFile << "Charles Adeniji: This is the first exercise in file handling";
        // close the file
        myFile.close();
    }
    else
    {
        cout << "Unable to open the file for writing" << endl;
    }

    return 0;
}
