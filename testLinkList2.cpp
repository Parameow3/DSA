//linkList2.cpp
//demonstrates linked list
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Link
{
public:
int iData; //data item (key)
double dData; //data item
Link* pNext; //next link in list
//-------------------------------------------------------------
Link(int id, double dd) : //constructor
iData(id), dData(dd), pNext(NULL)
{ }
//-------------------------------------------------------------
void displayLink() //display ourself: {22, 2.99}
{
cout << "{" << iData << ", " << dData << "} ";
}
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
~LinkList() //destructor (deletes links)
{
Link* pCurrent = pFirst; //start at beginning of list
while(pCurrent != NULL) //until end of list,
{
Link* pOldCur = pCurrent; //save current link
pCurrent = pCurrent->pNext; //move to next link
delete pOldCur; //delete old current
}
}
//-------------------------------------------------------------
void insertFirst(int id, double dd)
{ //make new link
Link* pNewLink = new Link(id, dd);
pNewLink->pNext = pFirst; //it points to old first link
pFirst = pNewLink; //now first points to this
}

//-------------------------------------------------------------
Link* find(int key) //find link with given key
{ //(assumes non-empty list)
Link* pCurrent = pFirst; //start at ‘first’
while(pCurrent->iData != key) //while no match,
{
if(pCurrent->pNext == NULL) //if end of list,
return NULL; //didn’t find it
else //not end of list,
pCurrent = pCurrent->pNext; //go to next link
}
return pCurrent; //found it
}
//-------------------------------------------------------------
bool remove(int key) //remove link with given key
{ //(assumes non-empty list)
Link* pCurrent = pFirst; //search for link
Link* pPrevious = pFirst;
while(pCurrent->iData != key)
{
if(pCurrent->pNext == NULL)
return false; //didn’t find it
else
{
pPrevious = pCurrent; //go to next link
pCurrent = pCurrent->pNext;
}
} //found it
if(pCurrent == pFirst) //if first link,
pFirst = pFirst->pNext; //change first
else //otherwise,
pPrevious->pNext = pCurrent->pNext; //bypass it
delete pCurrent; //delete link
return true; //successful removal 
}
//-------------------------------------------------------------
void displayList() //display the list
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
LinkList theList; //make list
theList.insertFirst(22, 2.99); //insert 4 items
theList.insertFirst(44, 4.99);
theList.insertFirst(66, 6.99);
theList.insertFirst(88, 8.99);
theList.displayList(); //display list
int findKey = 44; //find item
Link* pFind = theList.find(findKey);
if( pFind != NULL)
cout << "Found link with key " << pFind->iData << endl;
else
cout << "Can't find link" << endl;
int remKey = 66; //remove item
bool remOK = theList.remove(remKey);
if( remOK )
cout << "Removed link with key " << remKey << endl;
else
cout << "Can't remove link" << endl;
theList.displayList(); //display list
return 0;
} //end main()