#include<iostream>
#include<fstream>
#include"LinkedList.cpp"
using namespace std;
void readFile(string fileName)
{
    ifstream infile(fileName);

    while (!infile.eof())
    {
        string myText;
        getline(infile, myText);
        rawText += myText;
    }
}
