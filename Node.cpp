#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class NodeL
{
public:
    char value;
    int freq;
    NodeL *left;
    NodeL *right;
    NodeL *next = NULL;
    string code;

    NodeL()
    {
        freq = 0;
        value = '\0';
        left = NULL;
        right = NULL;
        code = "";
    }
    NodeL(char value, int freq, NodeL *left, NodeL *right)
    {
        this->code = "";
        this->value = value;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};