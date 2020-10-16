/*Write a program to input an array of integers containing 10 elements and sort them in
ascending order.*/
#include<stdio.h>
void Merge(int *a,int p,int q,int r)
{
	int i,j,k;
	int L[q-p+1],R[r-q];
	for(i=0;i<(q-p+1);i++)
		L[i]=a[p+i];
	for(j=0;j<(r-q);j++)
		R[j]=a[q-j+1];
	i=j=0;
	for(k=p;i<(q-p+1)&&j<(r-q);k++)
	{
		if(L[i]<R[j])
			a[k]=L[i++];
		else
			a[k]=R[j++];
	}
	while (i < (q-p+1)) 
    	{ 
        	a[k++] = L[i++]; 
    	}
    	while (j < (r-q)) 
    	{ 
        	a[k++] = R[j++]; 
	} 
}
void Merge_sort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=p+(r-p)/2;
		Merge_sort(a,p,q);
		Merge_sort(a,q+1,r);
		Merge(a,p,q,r);
	}
}
void print(int *a)
{
	int i;
	for(i=0;i<10;i++)
		printf("%d\t",a[i]);
}
int main()
{
	int a[]={5,8,1,6,2,0,9,3,4,7};
	Merge_sort(a,0,9);
	printf("\n");
	print(a);
	return 0;
}
