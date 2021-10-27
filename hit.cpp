#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct library
{
	char *book_title;
	char *author;
	int publication_year;
	float price;
};
int main()
{
	int n,pos;
	printf("enter number of records you need=");
	scanf("%d",&n);
	struct library* st=(struct library*)malloc(n*sizeof(struct library));
	for(int i=0;i<n;i++)
	{
		printf("enter book title=");
		st[i].book_title=(char*)malloc(sizeof(char));
		scanf("%s",st[i].book_title);
		printf("enter author name=");
		st[i].author=(char*)malloc(sizeof(char));
		scanf("%s",st[i].author);
		printf("enter publication year=");
		scanf("%d",&st[i].publication_year);
		printf("enter price=");
		scanf("%f",&st[i].price);
		
	}
	for(int i=0;i<n;i++)
	{
		int min=st[i].publication_year;
		int pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(st[j].publication_year>min)
			pos=j;
			else if(st[j].publication_year==min)
			{
				if(strcmp(st[j].author,st[pos].author)<0)
				pos=j;
			}
		}
		char *tempt=st[i].book_title;
		char *tempa=st[i].author;
		int tempp=st[i].publication_year;
		float tempr=st[i].price;
		st[i].book_title=st[pos].book_title;
		st[i].author=st[pos].author;
		st[i].publication_year=st[pos].publication_year;
		st[i].price=st[pos].price;
		st[pos].book_title=tempt;
		st[pos].author=tempa;
		st[pos].publication_year=tempp;
		st[pos].price=tempr;
	}
    float lrange,urange;
	printf("enter lower price range for books=");
	scanf("%f",&lrange);
	printf("enter upper price range for books=");
	scanf("%f",&urange);
	for(int i=0;i<n;i++)
	{
		if(st[i].price>=lrange && st[i].price<=urange)
		{
			printf("%s \t",st[i].book_title);
			printf("%s \t",st[i].author);
			printf("%d \t",st[i].publication_year);
			printf("%f \n",st[i].price);
		}
	}
	return 0;
	
}
