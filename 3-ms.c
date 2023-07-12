#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int l,int m,int r)
{
    int i,j,k,n1,n2;
    n1=m-l+1;
    n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(j=0;j<n2;j++)
        R[j]=a[m+1+j];    
    i=0;
    j=0;
    k=l;
    while (i<n1&&j<n2) 
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}
void sort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        sort(a,l,m);
        sort(a,m+1,r);
        merge(a,l,m,r);
    }
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    clock_t start = clock();
    sort(a,0,n-1);
    clock_t end = clock();
    printf("The sorted array is: \n");
    print(a,n);
    printf ("\nStart time is %lf\n",(double)start);
    printf ("End time is %lf\n",(double)end);
    printf ("Total time is %lf\n",(double)(end-start));
    return 0;
}