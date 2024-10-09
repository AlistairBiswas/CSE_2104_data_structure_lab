#include <iostream>
#include <conio.h>
using namespace std;

void min_heapify(int *a, int m, int rightc){
   int leftc, large;
   large= a[m];
   leftc = 2 * m;

   while (leftc <= rightc) {
      if (leftc < rightc && a[leftc+1] < a[leftc])
         leftc = leftc + 1;
      if (large < a[leftc])
         break;
      else if (large >= a[leftc]) {
         a[leftc/2] = a[leftc];
         leftc = 2 * leftc;
      }
   }
   a[leftc/2] = large;
   return;
}
void build_minheap(int *a, int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      min_heapify(a,k,n);
   }
}
int main() {
   int n, i;
   cout<<"Enter no of elements of array : ";
   cin>>n;
   int a[n];
   for (i = 1; i <= n; i++) {
      cout<<"Enter element : "<<" "<<(i)<<endl;
      cin>>a[i];
   }
   build_minheap(a, n);
   cout<<"Min Heap\n";
   for (i = 1; i <= n; i++) {
      cout<<a[i]<<endl;
   }
}
