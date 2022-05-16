//linkList.cpp
//demonstrates linked list
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Link
{
public:
int iData; //data item
double dData; //data item
Link* pNext; //ptr to next link in list
//-------------------------------------------------------------
Link(int id, double dd) : //constructor
iData(id), dData(dd), pNext(NULL) 
{ } 
//-------------------------------------------------------------
void displayLink() //display ourself {22, 2.99}

{
cout << "{" << iData << ", " << dData << "} ";
}
//-------------------------------------------------------------
}; //end class Link
////////////////////////////////////////////////////////////////
class LinkList
{
private:
Link* pFirst; //ptr to first link on list
public:
//-------------------------------------------------------------
LinkList() : pFirst(NULL) //constructor
{ } //(no links on list yet)
//-------------------------------------------------------------
bool isEmpty() //true if list is empty
{ return pFirst==NULL; }
//-------------------------------------------------------------
//insert at start of list
void insertFirst(int id, double dd)
{ //make new link
Link* pNewLink = new Link(id, dd);
pNewLink->pNext = pFirst; //newLink-->old first
pFirst = pNewLink; //first-->newLink
}
//-------------------------------------------------------------
Link* getFirst() //return first link
{ return pFirst; }
//-------------------------------------------------------------
void removeFirst() //delete first link
{ //(assumes list not empty)
Link* pTemp = pFirst; //save first
pFirst = pFirst->pNext; //unlink it: first-->old next
delete pTemp; //delete old first
}
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
}; //end class LinkList
////////////////////////////////////////////////////////////////
int main()
{
LinkList theList; //make new list
theList.insertFirst(22, 2.99); //insert four items
theList.insertFirst(44, 4.99);
theList.insertFirst(66, 6.99);
theList.insertFirst(88, 8.99);
theList.displayList(); //display list
while( !theList.isEmpty() ) //until it’s empty,
{
Link* pTemp = theList.getFirst(); //get first link
//display its key
cout << "Removing link with key  "<< pTemp->iData << endl;
theList.removeFirst(); //remove it 
}
theList.displayList(); //display empty list
return 0;
} //end main()