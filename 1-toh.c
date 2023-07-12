#include<stdio.h>
#include<time.h>
void toh(int n,char src,char dest,char aux)
{
    if (n==1)
    {
        printf("Move disk 1 from rod %c to rod %c\n",src,dest);
        return;
    }
    toh(n-1,src,aux,dest);
    printf("Move disk %d from rod %c to rod %c\n",n,src,dest);
    toh(n-1,aux,dest,src);
}
int main()
{
    int n;
    printf("Enter the number of disks:");
    scanf("%d",&n);
    clock_t start = clock();
    toh(n,'A','C','B');
    clock_t end = clock();
    printf ("\nStart time is %lf\n",(double)start);
    printf ("End time is %lf\n",(double)end);
    printf ("Total time is %lf\n",(double)(end-start));
    return 0;
}