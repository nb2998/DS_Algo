#include<stdio.h>

int main() {
   int i, j, n, temp, a[20];

   printf("enter the no of elements you want to sort ");
   scanf("%d", &n);

   printf("enter the elements: ");
   for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }

   for (i = 1; i < n; i++) {
      temp = a[i];
      j = i - 1;
      while ((temp < a[j]) && (j >= 0)) {
         a[j + 1] = a[j];
         j = j - 1;
      }
      a[j + 1] = temp;
   }

   printf("Sorted array is ");
   for (i = 0; i < n; i++) {
      printf(" %d ", a[i]);
   }
return 0;
}
