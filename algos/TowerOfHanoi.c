#include<stdio.h>

void TOH(int n, char S, char A, char T)
{
    if(n==1)
    printf("Shift %d from %c to %c \n",n,S,T);

    else
    {
        TOH(n-1,S,T,A);
        printf("Shift %d from %c to %c \n",n,S,T);
        TOH(n-1,A,S,T);
    }
}

int main()
{
    int n;
    printf("Enter the number of disks");
    scanf("%d",&n);
    TOH(n,'A','B','C');
    return 0;
}