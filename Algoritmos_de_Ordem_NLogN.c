#include <stdio.h>
#include <stdlib.h>



void Merge(int *vet, int p, int q, int r, int *cont){
	
	int sizeEsq = q-p+1;
	int sizeDir = r-q;
	int *vetEsq = (int*)malloc((sizeEsq+1)*sizeof(int));
	int *vetDir = (int*)malloc((sizeDir+1)*sizeof(int));
	int i,j,k;
	for (i=0;i<sizeEsq;i++)
		vetEsq[i]=vet[p+i];
	for (j=0;j<sizeDir;j++)
		vetDir[j]=vet[q+j+1];
	vetEsq[sizeEsq]=99999;
	vetDir[sizeDir]=99999;
	i=0;
	j=0;
	k = p;
    	while (i < sizeEsq && j < sizeDir) {
		*cont+=1;
        	if (vetEsq[i] <= vetDir[j]) {
            		vet[k] = vetEsq[i];
            		i++;
        	}
        	else {
            		vet[k] = vetDir[j];
            		j++;
        	}
        	k++;
    	}

	while (i < sizeEsq) {
        	vet[k] = vetEsq[i];
        	i++;
    	   	k++;
    	}

	while (j < sizeDir) {
        	vet[k] = vetDir[j];
        	j++;
        	k++;
    	}
	
	free(vetDir);
	free(vetEsq);

}

void Merge_Sort(int *vet, int p, int r, int *cont){
	int q;
	if (p<r){
		q = p+(r-p)/2;
		Merge_Sort(vet,p,q,cont);
		Merge_Sort(vet,q+1,r,cont);
		Merge(vet,p,q,r,cont);	
	}

}

void Print_Vet(int *vet, int size){
	for(int i = 0;i<size;i++)
		printf("%d ",vet[i]);
	printf("\n");
}

void Fill_Vet(int *vet, int size, int op){
	int i;
	switch(op){
		case 0:
			scanf("%d",&vet[0]);
			for(i = 1;i<size;i++)
				scanf(" %d",&vet[i]);
			break;
		default:
			for(i= 0;i<size;i++)
				vet[i]=size-i;
			break;
	}
}

int main(){
	int size;
	int *vet;
	int contMS=0;
	scanf("%d",&size);
       	vet = (int*)malloc(size*sizeof(int));
	Fill_Vet(vet,size,0);
	Print_Vet(vet,size);
	Merge_Sort(vet,0,size-1,&contMS);
	Print_Vet(vet,size);
	printf("%d",contMS);
	free(vet);
	return 0;
}
