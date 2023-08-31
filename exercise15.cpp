// Write a C++ program to calculate the average of numbers stored in a file.
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using std::filesystem::current_path;

int main()
{
    // get the current working directory
    string currentDirectory = current_path();
    string fileName = "/numbers.txt";
    string file = currentDirectory + fileName;

    // initialise file handlers
    ifstream myFile;

    // initialise counter
    int counter = 0;

    // open the file with append write mode passed as second param
    myFile.open(file);

    // check if the file is open
    if (myFile.is_open())
    {
        double total;
        double number;
        while (myFile >> number)
        {
            total = total + number;
            counter++;
        }

        myFile.close();

        double average = total / counter;

        cout << "The average of the numbers in the file is " << average;
    }

    return 0;
}