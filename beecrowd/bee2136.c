#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{char name[50], amg; int TAM;}amigo;
amigo vetor[10000];

int organizar(const void *ptr1, const void *ptr2){
	amigo *i = (amigo *)ptr1, *j = (amigo *)ptr2;
	if(i->amg < j->amg){
		return 1;
	}
	else if(i->amg > j->amg){
		return -1;
	}
	else{
		return strcmp(i->name, j->name);
	}
}

int main(){	
	amigo friend;
	char resp[20], name[50];
	friend.TAM = 0;
	int n=0;
	
	while(1){
		scanf(" %s %s ", name, resp);	
		if(strcmp(name, "FIM") == 0){
			break;
		}
		strcpy(vetor[n].name, name);
		vetor[n].TAM = strlen(vetor[n].name);
		if(strcmp(resp, "YES") == 0){
			vetor[n].amg = 1;
			if(vetor[n].TAM > friend.TAM){
				friend.TAM = vetor[n].TAM;
				strcpy(friend.name, vetor[n].name);
			}
		}else
			vetor[n].amg = 0;
		n++;
	}
	qsort(vetor, n, sizeof(amigo), organizar);
	printf("%s\n", vetor[0].name);
	
	for(int i=1; i<n; i++){
		if(strcmp(vetor[i].name, vetor[i-1].name) != 0){
			printf("%s\n", vetor[i].name);
		}
	}
	printf("\nAmigo do Habay:\n");
	printf("%s\n", friend.name);
	return 0;
}