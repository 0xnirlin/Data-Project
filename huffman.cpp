#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Node.cpp"
#include "queue.cpp"
#include "LinkedList.cpp"
#include "readfile.cpp"


string bigStr;
void print_codes(NodeL *node, string str,linkedList &LL)
{

    if (node != nullptr)
    {

        if (node->value != '*')
        {

            // cout << node->value << ": " << str << endl;
            node->code = str;
            LL.assignCode(str, node->value);
        }

        print_codes(node->left, str + "0", LL);
        print_codes(node->right, str + "1", LL);
    }
   
}

NodeL* encodeHuffman(PQueue &queue, int length, linkedList &LL, bool optimised)
{
    NodeL *child1;
    NodeL *child2;
    NodeL *top;
     
    int  i = 1;

    while (i < length)
    {

        child1 = queue.top();
        queue.Remove();
        child2 = queue.top();
        queue.Remove();

        top = new NodeL('*', child1->freq + child2->freq, child1, child2);
        if(optimised == true)
        {
        queue.insert(top);

        }
        else{
            queue.insertUn(top);
        }
       i++;
    }
    // cout << "TT: " << top->left->left->left << endl;

    print_codes(top, "",LL);
        cout<<"Encoded String: "<<bigStr<<endl;

    return top;
}

void decode(NodeL *top, string str)
{
    NodeL* ptr = top;
     string decoded_str = "";
    for (int i=0;i<str.length();i++)
    {
        if (str[i] == '0')
           ptr = ptr->left;
        else
           ptr = ptr->right;
  
        // reached leaf node
        if (ptr->left==NULL and ptr->right==NULL)
        {
            decoded_str += ptr->value;
            ptr = top;
        }
    }
    cout<<endl;
    cout<<"\t\t"<<decoded_str<<endl;
    cout<<endl;
    


}

string encodedText(linkedList &LL){
    string result = "";
    for(int i=0; i<rawText.size(); i++)
    {
        result += LL.getCode(rawText[i]);
    }
    return result;
}



