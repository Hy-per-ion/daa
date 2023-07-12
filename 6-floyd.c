#include<stdio.h>
#include<time.h>
void floyd(int a[10][10], int n)
{
for(int k=0;k<n;k++)
{
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(a[i][j]>a[i][k]+a[k][j])
{
a[i][j]=a[i][k]+a[k][j];
}
 }
 }
}
printf("All Pairs Shortest Path is :\n");
for(int i=0;i<n;i++)
{
 for(int j=0;j<n;j++)
 {
 printf("%d ",a[i][j]);
}
 printf("\n");
}
}
int main()
{
int cost[10][10],n;
printf("Enter the number of vertices\n");
 scanf("%d",&n);
 printf("Enter the cost adjacency matrix\n");
 for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
 scanf("%d",&cost[i][j]);
}
}
clock_t start=clock();
floyd(cost,n);
clock_t end=clock();
printf("Start time is %lf\n",(double)start);
printf("End time is %lf\n",(double)end);
printf("Total time is %lf\n",(double)(end-start));
return 0;
}