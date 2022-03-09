#include <stdio.h>
#include <stdlib.h>
#include <cstring>
char* initializeMaxop()
{
	char* ptr=(char*)malloc(1001*sizeof(char));
	for(int i=0;i<1001;i++)
	{
		ptr[i]='0';
	}
	ptr[1000]='\0';
	return ptr;
}
void compareMaxop(char arr1[],char arr2[],int length1,int length2)
{
	if(length1>length2)
	{
		printf("1");
		return;
	}
	else if(length1<length2)
	{
		printf("-1");
		return;
	}
	else if(length1==length2)
	{
		int i=length1-1;
		while(i>-1)
		{
			if(arr1[i]>arr2[i])
			{
				printf("1");
				return;
			}
			if(arr1[i]<arr2[i])
			{
				printf("-1");
				return;
			}
			i-=1;
		}
		printf("0");
	}
}
	void sumMaxOP(char arr1[],char arr2[],int size1,int size2)
	{
	//char * arr3=(char*)malloc(1001*sizeof(char));
	
    int lar;
    int num1[size1];
    int num2[size2];
    if(size1>size2)
    {
    	lar=size1+1;
	}
	else
	lar=size2+1;
    int sum[lar];
    for(int i=0;i<size1;i++)
    {
    	num1[i]=arr1[i]-'0';
	}
	

    
    for(int i=0;i<size2;i++)
    {
    	num2[i]=arr2[i]-'0';
	}
	int carry =0;
	int k=0;
	int i=size1-1;
	int j=size2-1;
	
	for(;i>=0&&j>=0;i--,j--,k++)
	{
		sum[k]=(num1[i]+num2[j]+carry)%10;
		carry=(num1[i]+num2[j]+carry)/10;
	}
	if(size1>size2)
	{
		while (i >= 0) {
			sum[k++] = (num1[i] + carry) % 10;
			carry = (num1[i--] + carry) / 10;
		}

	}
	
	else if (size1 < size2)
	{
		while (j >= 0) {
			sum[k++] = (num2[j] + carry) % 10;
			carry = (num2[j--] + carry) / 10;
		}
	}
	else
	{
		if (carry > 0)
			sum[k++] = carry;
	}
		printf("sum=");
		for(int i=k-1;i>=0;i--)
		{
			printf("%d",sum[i]);
		}
		printf("\n");
		return;
	}

void findDiff(char arr1[],char arr2[],int size1,int size2)
{
    int n1 = size1, n2 = size2;
    char newar1[n1];
    char newar2[n2];
    int max;
    if(n1>n2)
    max=n1;
    else
    max=n2;
    char res[max];
    int c=n1-1;int d=n2-1;int t,s,i;
    for(t=0;t<n1;t++)
    {
    	newar1[t]=arr1[c--];
	}
	for(s=0;s<n2;s++)
    {
    	newar2[s]=arr2[d--];
	}
    int carry = 0;int x=0;
    for (i = 0; i < n2; i++) {
        
 
        int sub= ((newar1[i] - '0') - (newar2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 		res[x]=(int)(sub);
 		x++;
    }
    for (i = n2; i < n1; i++) {
        int sub = ((newar1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        res[x]=(int)(sub);
        x++;
    }
    int z;
    printf("difference=");
    for(z=x-1;z>=0;z--)
    {
    	printf("%d",(int)res[z]);
	}
	return;
}
void Multiplymax(char arr1[],char arr2[],int size1,int size2)
{
	int n1 = size1, n2 = size2;
	if(arr1[0]=='0' || arr2[0]=='0')
	printf("0");
    char newar1[n1];
    char newar2[n2];
    char res[1000]={0};
    int c=n1-1;int d=n2-1;int t,s,i,j,Carry,k,l;
    for(t=0;t<n1;t++)
    {
    	newar1[t]=arr1[c--];
	}
	for(s=0;s<n2;s++)
    {
    	newar2[s]=arr2[d--];
	}
	for (i = 0; i <= n1- 1;++i) {
         for (j = 0; j <= n2- 1;++j) {
             Carry=(newar1[i]-48) * (newar2[j]-48);
             k = i + j;
             res[k] = res[k] + Carry;
             Carry = res[k];
             for (l = 0; res[k + l] >= 10;++l) {
                 res[k+l] = res[k + l] % 10;
                 res[k + l + 1] = Carry / 10 + res[k + l+1];
                 Carry = res[k+l+1];
             }
         }
     }
 
     //Output multiplied number
     for (i = 19; res[i] == 0;i--) {
         if (res[i]==0) {
             res[i] = '\0';
         }
     }
     j = i + 1;
     for (i = 0; i <=(j - 1)/2;++i) {
         k = res[i];
         res[i] = res[j-i - 1];
         res[j - i - 1] = k;
     }
     printf("product=");
     for (i = 0; i < j;++i) {
         printf("%d",res[i]);
     }
     return;
}
int multiply(int x, int res[], int size)
{
	int carry = 0; 

	
	for (int i=0; i<size; i++)
	{
		int prod = res[i] * x + carry;


		res[i] = prod % 10;

		carry = prod/10;
	}

	
	while (carry)
	{
		res[size] = carry%10;
		carry = carry/10;
		size++;
	}
	return size;
}
void factorial(int n)
{
	int MAX=1000;
	int res[MAX];
	
	
	res[0] = 1;
	int size = 1;


	for (int x=2; x<=n; x++)
		size = multiply(x, res,size);


	for (int i=size-1; i>=0; i--)
		printf("%d",res[i]);
}

int main()
{
	#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt","w",stdout);
   #endif
    int n1,n2;
    scanf("%d",&n1);
    scanf("%d",&n2);
    char a1[n1+1];char b1[n2+1];
    char *a=(char*)malloc(sizeof(char)*n1);
    char *b=(char*)malloc(sizeof(char)*n2);
    scanf("%s",a1);
    scanf("%s",b1);
    for(int i=0;i<n1-1;i++)
    {
    	a[i]=(char)a1[i];
    }
     for(int i=0;i<n1;i++)
    {
    	printf("%d",a[i]);
    }

	if(sizeof(a)/sizeof(a[0])>=sizeof(b)/sizeof(b[0]))
	findDiff(a,b,sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0]));
	else
	findDiff(b,a,sizeof(b)/sizeof(b[0]),sizeof(a)/sizeof(a[0]));
	printf("\n");
	sumMaxOP(a,b,sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0]));
	Multiplymax(a,b,sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0]));
	printf("\n");
	compareMaxop(a,b,sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0]));
	int i;
	sscanf(a,"%d", &i);
	factorial(i);
	return 0;
}