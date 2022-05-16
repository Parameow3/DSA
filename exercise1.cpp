// exercise1.cpp

#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Link {
    public:
    int iData;
    string strData;
    Link* pNext;
//-------------------------------------------------------------
    Link(int id, string sd) : //constructor
    iData(id), strData(sd), pNext(NULL) 
    { } 
//-------------------------------------------------------------
    void displayLink() //display ourself {22, 2.99}
    {
    cout << "{" << iData << ", " << strData << "} ";
    }
//-------------------------------------------------------------
};  //end class Link
////////////////////////////////////////////////////////////////
class LinkList {
    private:
    int countSize = 0; // count link of the list
    Link* pFirst, * tail; //pointer to first link on list
    public:
//-------------------------------------------------------------
    LinkList() : pFirst(NULL) //constructor
    { } //(no links on list yet)
//-------------------------------------------------------------
    bool isEmpty() //true if list is empty
    { return pFirst==NULL; }
//-------------------------------------------------------------
    //insert at start of list
    void insertFirst(int id, string sd)
    { //make new link
    Link* pNewLink = new Link(id, sd);
    pNewLink->pNext = pFirst; //newLink-->old first
    pFirst = pNewLink; //first-->newLink
    countSize++;
    }
//-------------------------------------------------------------
    Link* getFirst() //return first link
    { return pFirst; }
//-------------------------------------------------------------
    void displayList()
    {
    cout << "List (first-->last): ";
    Link* pCurrent = pFirst; //start at beginning of list
    while(pCurrent != NULL) //until end of list,
    {
    pCurrent->displayLink(); //print data
    pCurrent = pCurrent->pNext; //move to next link
    }
    cout << endl;
    }
//-------------------------------------------------------------
    void size() // Link in the list
    { cout << "Size of link in the list is: " << countSize; }
//-------------------------------------------------------------
    void insertToPosition(int intData, string strData, int pos)
    {
        
    }
//-------------------------------------------------------------
};  //end class LinkList
////////////////////////////////////////////////////////////////