#include "proj9T.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
 List4* lst = new List4;
 lst->Insert(1,1);
 lst->Insert(0,0);
 for(int i = 0; i< 10; i++)
  lst->Insert(i,i);
 lst->PrintForward();
 lst->DeleteItem(1);
 lst->PrintForward();
 return 0;
}
