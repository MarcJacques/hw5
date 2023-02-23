#include <iostream>
using namespace std;
void swapValue(int, int);
void swapReference(int &, int &);

int main() 
{
  int i =10,n = 20;
  swapValue(i, n);
  cout<<i <<"\t" << n<<endl; //---1
 
  i =10,n = 20;
  swapReference(i, n);
  cout<<i <<"\t" << n<<endl; //---2
  
  return 0;
}

void swapValue(int a, int b)
{
   int temp = a;
   a = b;
   b = a;
}

void swapReference(int &a, int &b)
{
   int temp = a;
   a = b;
   b = temp;
}