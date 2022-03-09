#include <stdio.h>
#include <stdlib.h>
void merge(float arr[],int pr[],int wt[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m; 
	float L[n1], R[n2];
    int pr1[n1],pr2[n2];
    int wt1[n1],wt2[n2];

	
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
        for (i = 0; i < n1; i++)
		pr1[i] = pr[l + i];
        for (i = 0; i < n1; i++)
	     wt1[i] = wt[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
        for (j = 0; j < n2; j++)
		pr2[j] = pr[m + 1 + j];
        for (j = 0; j < n2; j++)
		wt2[j] = wt[m + 1 + j];


	
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
            wt[k]=wt1[i];
            pr[k]=pr1[i];

			i++;
		}
		else {
			arr[k] = R[j];
            wt[k]=wt2[j];
            pr[k]=pr2[j];
			j++;
		}
		k++;
	}

	
	while (i < n1) {
		arr[k] = L[i];
        wt[k]=wt1[i];
        pr[k]=pr1[i];
		i++;
		k++;
	}

	
	while (j < n2) {
		arr[k] = R[j];
        wt[k]=wt2[j];
        pr[k]=pr2[j];
		j++;
		k++;
	}
}


void mergeSort(float arr[],int pr[],int wt[], int l, int r)
{
	if (l < r) {
		
		int m = l + (r - l) / 2;
		mergeSort(arr,pr,wt, l, m);
		mergeSort(arr,pr,wt, m + 1, r);

		merge(arr,pr,wt, l, m, r);
	}
}


void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
    int w;
    printf("enter weight of knap=");
    scanf("%d",&w);
    int n;
    printf("enter size of array=");
    scanf("%d",&n);
    int pr[n];
    int wt[n];
    printf("enter elements in profit=");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pr[i]);
    }
    printf("enter weights of elements=");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&wt[i]);
    }
    float rt[n];
    for(int i=0;i<n;i++)
    {
        rt[i]=((float)pr[i]/(float)wt[i]);
    }
    mergeSort(rt,pr,wt,0,n-1);
    float profit=0;
    int temp=w;
    
        for(int i=n-1;i>=0;i--)
        {
            if(wt[i]<temp)
            {
                profit=profit+pr[i];
                temp=temp-wt[i];
            }
            else if(wt[i]>temp)
            {
                if(rt[i]>temp)
                {
                    break;
                }
                else
                {
                    profit=profit+(rt[i]*temp);
                    temp=0;
                }
            }
        }
        printf("profit/weight ratio array sorted=");
        for(int i=0;i<n;i++)
        {
        	printf("%f ",rt[i]);
		}
		printf("\n");
		printf("weight array after arrangement=");
		for(int i=0;i<n;i++)
        {
        	printf("%d ",wt[i]);
		}
		printf("\n");
		printf("profit array after arrangement=");
		for(int i=0;i<n;i++)
        {
        	printf("%d ",pr[i]);
		}
		printf("\n");
    printf("max profit is=%f",profit);
    return 0;
}
