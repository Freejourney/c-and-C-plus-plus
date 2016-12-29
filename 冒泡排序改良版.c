#include <stdio.h>
int order(int arr[], int n);
int main()
{
	int i;
	int arr[5]={11,52,15,34,3};
	for(i=0;i<5;i++)
		printf("%d  ", arr[i]);
	order(arr, 5);
	putchar('\n'); 
	for(i=0;i<5;i++)
		printf("%d  ", arr[i]);
	return 0;
 } 
int order(int arr[], int n)
{
	int last;
	int j;
	int i=0;
	while(i<n-1)
	{
		last=n-1;
		for(j=n-1;j>i;j--)//程序从后向前比较，i以前的数不需要比较，i由每次循环最后次比较得来 
		{
			if(arr[j]<arr[j-1])
			{
				int temp;
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
				last = j;//之所以叫last是因为last是作为最后一次交换后的下标 
			}
		}
		i=last;//last的真正用途是省去前面不必要的比较。 
	}
}
