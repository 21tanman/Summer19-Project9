#include "proj9T.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
List4::List4()
{
 head = new doubleNode;
 tail = new doubleNode;
 tail->next = nullptr;
 head->prev = nullptr;
 tail->item = '\0';
 head->item = '\0';
 head->next = tail;
 tail->prev = head;
 length = 0;
}

List4::~List4()
{
 while(length>0)
 {
  doubleNode* cur = new doubleNode;
  cur = head;
  head = cur->next;
  cur->item = '\0';
  cur = cur->next;
  length--;
  cur->item = '\0';
  cur = nullptr;
  delete cur;
  }
 delete head;
 delete tail;
 return;
}

doubleNode* List4::FindPosition(int pos)
{
 doubleNode* cur = new doubleNode;
 cur = head;
 for(int i = 0; i < pos; i++)
  cur = cur->next;
 return cur;
}


void List4::Insert(itemType item, int pos)
{
 doubleNode* cur = new doubleNode;
 doubleNode* tmp = new doubleNode;
 tmp = head->next;
 cur->item = item; 
//special circumstance routes///////////////////////////////
 if(pos > length+1 || pos < 1)
 {
  printf("input-position:%d is not a valid position\n", pos);
  return;
 }
 if(length == 0)
 {
  head->next = cur;
  cur->prev = head;
  cur->next = tail;
  tail->prev = cur;
  length++;
  return;
 }
////////////////////////////////////////////////////////
/*In case the pos = 0
if(pos == 1); 
 {cout << "pos 1.1" << endl;
  cur->next = head->next;
  cur->prev = head;
  cout << "pos1.2" << endl;
  if(length >0)
  pre->next->prev = cur;
cout<< "pos1.21" << endl;
  head->next = cur;
cout << "pos 1.22" << endl;
  length++;
 cout << "pos1.3" << endl;
  return;
 }*/

//When pos > 0
 tmp = FindPosition(pos-1);
 cur->next = tmp->next;
 cur->prev = tmp;
 tmp->next = cur;
 tmp = cur->next;
 tmp->prev = cur;
 cur = nullptr;
 delete cur;
 length++;
 //this->PrintForward();
 return;
}
 
void List4::PrintForward()
{
 printf("\n-Printing-\n");
 for(int i = 1; i < length+1; i++)
 {
  doubleNode* value = this->FindPosition(i);
  printf("#%d :-: %i \n", i, value->item);
 }
 return;
}

void List4::PrintBackwards()
{
 printf("\n ~Printing Backwards~ \n");
 for(int i = 0; i < length; i++)
 {
  doubleNode* value = this->FindPosition(length-i);
  printf("#%d :~: %i \n", length-i, value->item);
 }
 return;
}

doubleNode* List4::Find(itemType item)
{
 doubleNode* cur = new doubleNode;
 cur = head->next;
 while(cur!= tail)
 {
  if(cur->item == item)
  {
	 cout << "Item: " << item << " found!" << endl;
   return cur;
  }
  cur = cur->next;
 }
cout << "Item: " << item << " not found." << endl;
return 0;
}

void List4::Delete(int pos)
{cout << "inside delete" << endl;
 doubleNode* cur = new doubleNode;
 cur = FindPosition(pos);
 cout << "past FindPos:" << endl;
 cout << "cur item is: "<< cur->item << endl;
 cur->prev->next = cur->next;
 cout << "cp1" << endl;
 cur->next->prev = cur->prev;
 cout << "cp2" << endl;
 cur->item = '\0';
 cur = nullptr;
 delete cur;
 length--;
 cout << "finished delete" << endl;
 return;
}

int List4::DeleteItem(itemType item)
{
 doubleNode* cat = new doubleNode;
 cat = head->next;
 int pos = 1;
 int deletions = 0;
 while(cat != tail)
 {
  if(cat->item == item)
  {
   this->Delete(pos-deletions);
   deletions++;
  }
  cat = cat->next;
  pos++;
 }
 cat = nullptr;
 delete cat;
 return deletions;
}










  
