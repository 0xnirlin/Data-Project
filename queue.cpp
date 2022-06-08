#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Node.cpp"

using namespace std;

class PQueue
{
private:
    NodeL *front;
    NodeL *rear;

public:
    PQueue()
    {

        front = NULL;
    }
    void insert(NodeL *newNode)
    {
        // cout << "COming Item is: " << newNode->value << endl;
        // cout << "COming Frequency is: " << newNode->freq << endl;
        NodeL *ptr1, *ptr2;
        ptr1 = new NodeL;
        ptr1->value = newNode->value;
        ptr1->freq = newNode->freq;
        ptr1->left = newNode->left;
        ptr1->right = newNode->right;
        if (front == NULL || newNode->freq < front->freq)
        {
            ptr1->next = front;
            front = ptr1;
        }
        else
        {
            ptr2 = front;
            while (ptr2->next != NULL && ptr2->next->freq <= newNode->freq)
                ptr2 = ptr2->next;
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
        }
    }

    void insertUn(NodeL *newNode){
           NodeL *ptr = new NodeL;
            ptr->value = newNode->value;
            ptr->freq = newNode->freq;
            ptr->left = newNode->left;
            ptr->right = newNode->right;
            ptr->next = NULL;


            // If inserting the first element/node
            if (front == NULL)
            {
                front = ptr;
                rear = ptr;
            }
            else
            {
                rear->next = ptr;
                rear = ptr;
            }
    }
    void Remove()
    {
        NodeL *t;
        NodeL *rt;
        if (front == NULL) // if queue is null
            cout << "Queue is Empty\n";
        else
        {
            t = front;
            // cout << "Removed Item is: " << t->value << endl;
            // cout << "Frequency of removed item: " << t->freq << endl;
            front = front->next;
        }
    }

    NodeL *top()
    {
        NodeL t;
        if (front == NULL)
        {
            cout << "QUEUE is empty" << endl;
        }
        else
        {
            return front;
        }
    }

    void Display() // print queue {
    {
        NodeL *ptr;
        ptr = front;
        if (front == NULL)
            cout << "Queue is empty\n";
        else
        {
            cout << "Queue is :\n";
            // cout << "Priority Item\n";
            while (ptr)
            {
                cout << ptr->value << " " << ptr->freq << endl;
                ptr = ptr->next;
            }
        }
    }
};
