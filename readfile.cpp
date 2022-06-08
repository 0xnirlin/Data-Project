#pragma once
#include <iostream>
#include <fstream>
#include "LinkedList.cpp"
using namespace std;

bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

void readFile(string fileName)
{
    ifstream infile(fileName);
    bool isEmpty = infile.peek() == EOF;
    if (!infile)
    {
        cout<<"\nF I L E  I S  N O N  E X I S T E N T  B Y E B Y E ! ! ! \n"<<endl;
        exit(1);
    }

    if (isEmpty)
    {
        
        cout<<"\nF I L E  I S  E M P T Y  B Y E B Y E ! ! ! \n"<<endl;
        exit(1);
    }

    while (!infile.eof())
    {
        string myText;
        getline(infile, myText);
        rawText += myText;
    }
}
