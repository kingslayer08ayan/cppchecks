#include <stdio.h>
int main()
{
	int mem,bs,nob,pr,ef,tif=0,i;
	printf("enter total memory=");
	scanf("%d",&mem);
	printf("enter block size=");
	scanf("%d",&bs);
	nob=mem/bs;
	ef=mem-(nob*bs);
	printf("enter no of process=");
	scanf("%d",&pr);
	int mp[pr];
	printf("enter memory required for each process=\n");
	for(i=0;i<pr;i++)
	{
		scanf("%d",&mp[i]);
	}
	printf("number of blocks in memory=%d \n",nob);
	int k=0;
	printf("P Size  Frag  Check\n");
	for(i=0;i<pr && k<nob;i++)
	{
		printf("%d   %d  ",i+1,mp[i]);
		if(mp[i]>bs)
		
		printf("--   NO \n");
	
		else
		{
			printf("%d   YES",bs-mp[i]);
			tif+=(bs-mp[i]);
			k++;
			printf("\n");
		}
	}
	printf("Total internal fragmentation=%d \n",tif);
	printf("Total external fragmentation=%d\n",ef);
	return 0;
}
