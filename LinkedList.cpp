#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Node.cpp"
#include "queue.cpp"


string rawText;
class linkedList
{
public:
    NodeL *head;

    linkedList()
    {
        head = NULL;
    }
    void insertAtEnd(char value, int freq)
    {
        // make a temporary Node
        NodeL *temp = new NodeL;
        temp->value = value;
        temp->freq = freq;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            NodeL *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
                /* code */
            }

            ptr->next = temp;
        }
    }


    void display()
    {
        NodeL *ptr;
        ptr = head;
        cout << "\t\tT R E E" << endl;
        while (ptr)
        {
            cout << "\t\tValue: " << ptr->value << " Frequency: " << ptr->freq <<" Code: "<<ptr->code << endl;
            cout<<endl;
            ptr = ptr->next;
        }
        // cout << ptr->value << endl;
    }

    void assignCode(string code, char val){
        NodeL* ptr = head;
        while(ptr)
        {
            if(ptr->value == val){
                ptr->code = code;
                break;
            }
            ptr = ptr->next;
        }
    }

    string getCode(char ch)
    {
        NodeL* ptr = head; 
        while(ptr)
        {
            if(ptr->value == ch){
                return ptr->code;
            }
            ptr = ptr->next;
        }
    }

    bool checkDuplicate(char ch)
    {
        NodeL *temp;
        temp = this->head;
        while (temp)
        {
            if (temp->value == ch)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void insertIntoQueue(PQueue &queue)
    {
        NodeL *ptr;
        ptr = head;

        while (ptr)
        {
            NodeL *ptr2 = new NodeL;
            ptr2 = ptr;
            queue.insert(ptr2);
            ptr = ptr->next;
        }
        delete(ptr);
    }
    void insertIntoQueueUn(PQueue &queue)
    {
        NodeL *ptr;
        ptr = head;

        while (ptr)
        {
            NodeL *ptr2 = new NodeL;
            ptr2 = ptr;
            queue.insertUn(ptr2);
            ptr = ptr->next;
        }
        delete ptr;
    }

    int length()
    {
        int length = 0;
        NodeL *ptr = head;
        while (ptr)
        {
            ptr = ptr->next;
            length++;
        }
        return length;
    }

    double compressionRatio(){
        NodeL *ptr = head;
        double i = 0;
        double sum = 0;
        while(ptr){
            // cout<<"ptrvalue: "<<ptr->code<<endl;
            // cout<<"ptrfreq: "<<ptr->freq<<endl;
            sum += ptr->code.size()*ptr->freq;
            // cout<<"SUUU: "<<sum<<endl;
            i++;
            ptr = ptr->next;
        }
        // cout<<"SUM: "<<sum<<endl;
        

        double ratio = 8 / (sum / rawText.size()) ;
        cout<<"\t\t C O M P R E S S I O N   R A T I O: "<<ratio<<endl;
        return ratio;

    }
};