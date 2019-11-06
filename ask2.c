#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sizeRandom 5

int main(int argc, char * argv[]){
	int size,i,j;
	int ** pointers;

	size = atoi(argv[1]);
	if (size>0 && argc >=2){
		pointers=(int **)malloc(size*sizeof(int *));
		for (i = 1; i <=size; i++)
		{
			*(pointers+i-1)= (int *)malloc(i*sizeof(int));
			if (*(pointers+i-1)==NULL) return 1;
		}
		for (i = 1; i <=size; i++)
		{
			for (j = 0; j < i; j++)
			{	
				*(*(pointers+i-1)+j)=1;
			}
		}
		for (i = 1; i <=size; i++)
		{
			for (j = 0; j <i; j++)
			{	
				printf("%d ",*(*(pointers+i-1)+j));
			}
			printf("\n");
		}
		printf("\n");
		for(i=0;i<= size;i++){
			for(j=0;j<i;j++){
				if(i==0 || i==1){
					continue;
				}
				else{
					*(*(pointers+i)+j+1)=*(*(pointers+i-1)+j)+*(*(pointers+i-1)+j+1);
				}
			}
		}
		for (i = 1; i <=size; i++)
		{
			for (j = 0; j <i; j++)
			{	
				printf("%d ",*(*(pointers+i-1)+j));
			}
		}
	}
	return 0;
}