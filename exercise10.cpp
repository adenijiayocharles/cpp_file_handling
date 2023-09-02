// Create a C++ program to divide a big text file into equal-sized smaller ones.
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;
using std::filesystem::current_path;

int main()
{
    // get the current working directory
    string currentDirectory = current_path();
    string fileName = "/wordlist_sorted.txt";
    string file = currentDirectory + fileName;

    int chunkSize = 400;

    // initialise file handlers
    ifstream myFile;
    myFile.open(file, ios::binary);
    if (myFile.is_open())
    {
        // get file size
        myFile.seekg(0, ios::end);
        streampos fileSize = myFile.tellg();
        myFile.seekg(0, ios::beg);

        // number of chunks
        int chunk = (fileSize + chunkSize - 1) / chunkSize;

        for (int i = 0; i < chunk; i++)
        {
            ofstream outputFile;
            outputFile.open(i + "_file.txt", ios::binary);

            if (outputFile.is_open())
            {
                vector<char> buffer(chunkSize);
                myFile.read(buffer.data(), chunkSize);

                outputFile.write(buffer.data(), myFile.gcount());

                outputFile.close();
            }
        }
        myFile.close();
    }
    else
    {
        cout << "haa haa";
    }

    return 0;
}