#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


struct Node{
	int x;
	int y;
	int sizeOfStruct;
	int weight;
};


struct Node* Initiallization(int *size){
	srand(time(NULL));
	struct Node *arr;
	int N;
	printf("Enter the count of points: ");
	scanf("%d", &N);
	*size = N;
	arr = (struct Node*) malloc (N * sizeof(struct Node));
	arr->sizeOfStruct = N;
	int i;
	for(i = 0; i < N; i++){
		(arr + i)->x = rand() % 20;
		(arr + i)->y = rand() % 20;
		(arr + i)->weight = (rand() % 89) + 10;
		/*
		printf("\nEnter X for [%d] point:", i);
		scanf("%d", &(arr + i)->x);
		printf("Enter Y for [%d] point:", i);
		scanf("%d", &(arr + i)->y);
		printf("Enter weight for [%d] point:", i);
		scanf("%d", &(arr + i)->weight);	*/	
	}		
	return arr;
}



void PrintNodes(struct Node* arr){
	int i; 
	for (i = 0; i < arr->sizeOfStruct; i++){
		//printf("arr[%d] = %d, address = %p\n", i, (arr[i]), &arr[i]);
		printf("ADRESS = %p,  Point #%2d: (%2d, %2d) weigth = %d, SIZE = %d\n",(arr+i), i, (arr + i)->x, (arr + i)->y, (arr + i)->weight, arr->sizeOfStruct);
	}
	printf("\n");	
}

struct Node* RemoveNode(struct Node** arr, int index){
	struct Node* temp = (*arr + index);
	int i;
	for (i = index; i <= (*arr)->sizeOfStruct-1; i++){
		((*arr) + i)->x = ((*arr) + i + 1)->x;
		((*arr) + i)->y = ((*arr) + i + 1)->y;
		((*arr) + i)->weight = ((*arr) + i + 1)->weight;
	}
	(*arr)->sizeOfStruct--;
	arr = (struct Node**) realloc (*arr, (*arr)->sizeOfStruct * sizeof(struct Node));
	return temp;	
}

int FindMin(struct Node* arr){
	struct Node* min = (arr + 0);
	int i, index = 0;
	for (i = 0; i < arr->sizeOfStruct; i++){
		if (((arr+i)->weight) < ((min)->weight)){
			min = (arr + i);
			index = i;
		}
		
	}
	return index;
}

void FindClosest (struct Node** arr){
	int minIndex = FindMin(*arr);
	struct Node* node = ((*arr) + minIndex);
	printf("MIN WEIGHT =  %d\n",node->weight);
	int i;

	double minLen = 9999999;//sqrt( (((*arr) + 0)->x - node->x) * (((*arr) + 0)->x - node->x)        +        (((*arr) + 0)->y - node->y)  *   (((*arr) + 0)->y - node->y) );;
	int cosestIndex = 0;
	if ((*arr)->sizeOfStruct != 1){
		for (i = 1; i < (*arr)->sizeOfStruct; i++){
			double len = ( (((*arr) + i)->x - node->x) * (((*arr) + i)->x - node->x)        +        (((*arr) + i)->y - node->y)  *   (((*arr) + i)->y - node->y) );
			if (minLen != 0){
				if ((len < minLen) && (len != 0)){
					minLen = len;
					cosestIndex = i;	
				}
			}
			
			
		}
		
		printf("Our element:\n x = %d, y = %d, weight = %d\nClosest element:\n x = %d, y = %d, weight = %d\n\n", node->x, node->y, node->weight,	((*arr) + cosestIndex)->x, ((*arr) + cosestIndex)->y, ((*arr) + cosestIndex)->weight );
		//if(cosestIndex == 0 && ((*arr)->sizeOfStruct == 2)) ((*arr) + 0)->weight = ((*arr) + 0)->weight + ((*arr) + 1)->weight;
		((*arr) + cosestIndex)->weight = ((*arr) + cosestIndex)->weight + node->weight;
		RemoveNode(arr, minIndex);
	}
	
}


int main(){
    int i;
	int size;
    struct Node *arr = Initiallization(&size);
	PrintNodes(arr);
	/*RemoveNode(&arr, 0);
	RemoveNode(&arr, 0);
	RemoveNode(&arr, 0);*/
	for (i = 0; i < size-1; i++){
		FindClosest(&arr);
		PrintNodes(arr);
	}
	
    return 0; 
}


