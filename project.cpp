#include <iostream>
#include <fstream>
#include <string>
#include "Node.cpp"
#include "queue.cpp"
#include "LinkedList.cpp"
#include "readfile.cpp"
#include "huffman.cpp"

using namespace std;





int main()
{

    // one character array
        linkedList LL;
        linkedList UnLL;

        string fileName;
        cout<< "\t\t E N T E R  T H E  F I L E  N A M E: ";
        cin>>fileName;


    readFile(fileName);

    // get the length of text
    int lenText = rawText.size();
    cout << lenText << endl;

    char ch;
    int counter = 0;
    for (int i = 0; i < lenText; i++)
    {
        ch = rawText[i];
        for (int j = 0; j < lenText; j++)
        {
            if (ch == rawText[j])
                counter++;
        }
        if (!LL.checkDuplicate(ch))
        {

            LL.insertAtEnd(ch, counter);
            UnLL.insertAtEnd(ch, counter);
        }

        
        ch = '\0';
        counter = 0;
    }

    PQueue queue;
    PQueue queueUn;
    LL.insertIntoQueue(queue);
    UnLL.insertIntoQueueUn(queueUn);

    int choice;

    // LL.display();
    // UnLL.display();
    // // Now take the node from linkedlist and pass it into queue and display the queue
    menu:
   cout<<"\t\t Choose From The Following Options: \n"<<endl;
   cout<<"\t\t 1. Optimised and Unoptimised Huffman Implementation \n"<<endl;
  
   cout<<"\t\t 2. EXIT \n"<<endl;
   cout<<"\t\t --Choice: ";
   cin>>choice;

   cout<<"\n\n"<<endl;

   if(choice == 1)
   {

        cout<<"\t\t O P T I M I S E D   I M P L E M E N T A T I O N"<<endl;
        cout<<endl;
        // queue.Display();
        // queueUn.Display();
        // optimised data
        NodeL *top = encodeHuffman(queue, LL.length(),LL,true);
        decode(top,bigStr);
        LL.display();
        string result = encodedText(LL);
        cout<<"\t\tEcnoded String: "<<result<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t D E C O D E D   S T R I N G   F O R  U N - O P T I M I S E D";
        cout<<endl;
        decode(top,result);
        cout<<endl;
        cout<<endl;
        cout<<endl;

        // unoptimised data
         cout<<"\t\t U N - O P T I M I S E D   I M P L E M E N T A T I O N"<<endl;
         cout<<endl;
        NodeL *topUn = encodeHuffman(queueUn, UnLL.length(),UnLL,false);
        decode(topUn,bigStr);
        UnLL.display();
        string resultUn = encodedText(UnLL);
        cout<<"\t\tEcnoded String Unoptimised: "<<resultUn<<endl;
          cout<<endl;
        cout<<endl;
        cout<<"\t\t D E C O D E D   S T R I N G   F O R   O P T I M I S E D";
        cout<<endl;
        decode(topUn,resultUn);

           cout<<"\t\t O P T I M I S E D  "<<endl;
        double oPercentage = LL.compressionRatio();
        cout<<endl;

           cout<<"\t\t U N O P T I M I S E D  "<<endl;
        double unPercentage = UnLL.compressionRatio();
        cout<<"\n\n";

        double percentage = (unPercentage/oPercentage)*100;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t C O M P R E S S I O N  P E R C E N T A G E:    "<<100 - percentage<<"%"<<endl;
        
        exit(0);

   } 


   else if(choice == 2)
   {
       cout<<"\n\t\tDestructing the trees and exiting the program......"<<endl;
       exit(0);
   }
   else
   {
       cout<<"\n\t\tInvalid Input\n";
       goto menu;
   }
   


 

}
