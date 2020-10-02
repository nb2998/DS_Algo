#include <stdio.h>

int main() {
  int i,n,j,temp;
  int arr[n];
  printf("enter the no. of elements you want to print ");
scanf("%d",&n);
printf("enter the elements");
for(i=0; i<n; i++)
{
  scanf("%d", &arr[i]);
}
for(i=0; i<n; i++)
{
  for(j=i+1; j<n ; j++)
  {
    if (arr[i]>arr[j])
    {
      temp = arr[i];
      arr[i] =arr[j];
      arr[j] = temp;
    }
  }
}
printf("the sorted elements are");
for(i=0; i<n; i++){
  printf(" %d ", arr[i]);
}
  return 0;
}