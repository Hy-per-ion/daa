#include<stdio.h>
#include<time.h>
int bs(int a[],int l,int r,int x)
{
    if(r>=1)
    {
        int mid = l+(r-l)/2;
        if(a[mid]==x)
        {
            return mid;
        }
        else if (a[mid]> x)
        {
            return bs(a,l,mid-1,x);
        }
        else
        {
            return bs(a,mid+1,r,x);
        }
    }
    return -1;
}
int main()
{
    int n,x;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the sorted array: ");
    for (int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the key: ");
    scanf("%d",&x);
    clock_t start = clock();
    int result = bs(a,0,n-1,x);
    clock_t end = clock();
    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at index %d",result);
    printf ("\nStart time is %lf\n",(double)start);
    printf ("End time is %lf\n",(double)end);
    printf ("Total time is %lf\n",(double)(end-start));
    return 0;
}