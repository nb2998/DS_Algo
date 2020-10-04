#include<stdio.h>
int min(int a,int b)
{
            if(a>b)
                        return b;
            else return a;
}
 
int max(int a,int b)
{
            if(a>b)
                        return a;
            else return b;
}
 
void minmax(int a[], int i, int j, int *fmin, int *fmax)
{
            int m,gmin,gmax,hmin,hmax;
            if(i==j)
            {
                        *fmin=*fmax=a[i];
                        return;
            }
            if(i==j-1)
            {
                        *fmin = min(a[i],a[j]);
                        *fmax = max(a[i],a[j]);
                        return;
            }
            m = (i+j)/2;
            minmax(a,i,m,&gmin,&gmax);
            minmax(a,m+1,j,&hmin,&hmax);
            *fmin = min(hmin,gmin);
            *fmax = max(hmax,gmax);
            return;
}
 
void main()
{
            int i,a[100],n,fmin,fmax;
            printf("Enter no. of integers:");
            scanf("%d",&n);
            for(i=0;i<n;i++)
                        scanf("%d",&a[i]);
            minmax(a,0,n-1,&fmin,&fmax);
            printf("maximum = %d\nminimum = %d\n",fmax,fmin);
}
