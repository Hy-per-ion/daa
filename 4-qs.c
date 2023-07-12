#include<stdio.h>
#include<time.h>
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]); return (i+1);
}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int pi = partition(a,low,high);
        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}
int main()
{
    int a[25],n;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements to be sorted\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    clock_t start=clock();
    quicksort(a,0,n-1);
    clock_t end=clock();
    printf("The sorted elements are\n");
    for(int k=0;k<=4;k++)
    {
        printf("%d\t",a[k]);
    }
    printf("\nStart time is %lf\n",(double)start);
    printf("End time is %lf\n",(double)end);
    printf("Total time is %lf\n",(double)(end-start));
    return 0;
}