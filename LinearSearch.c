#include<stdio.h>
int main()
{
    int arr[50],i,a,b,count=0;
    printf("Enter the size of the array\n");
    scanf("%d",&a);
    printf("Enter the no in the array\n");
    for(i=0;i<a;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the value you want to search\n");
    scanf("%d",&b);
    for(i=0;i<a;i++)
    {
        if(arr[i]==b)
        {
            count++;
            printf("Index: %d \n",i+1);
        }
    }
    if(count<0)
    {
        printf("not found");
    }
               
    printf("\ntotal count:%d",count);
    return 0;
}
