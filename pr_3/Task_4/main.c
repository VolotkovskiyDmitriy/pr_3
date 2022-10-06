#include <stdio.h>
#include <stdlib.h>

int *arr = NULL;
int size = 0;

void AddNum(int num){
    arr = (int*) realloc(arr, (size+1) * sizeof(int));
    arr[size] = num;
   // printf("Address %d = %p\n",num,&arr[size]);
    size++;    
}

void InsertNum(int index, int num){
  int i;
  arr = (int*) realloc(arr, (++size) * sizeof(int));
  for (i = size; i >= index; i--) arr[i] = arr[i-1];
  arr[index] = num;
}

int GetSize (){
  return size;
}

int RemoveNum(int index){
  int i;
  int temp = arr[index];
  for (i = index; i <= size-1; i++){
    arr[i] = arr[i+1];
  }
  arr = (int*) realloc(arr, (--size) * sizeof(int));
  return temp;
}

void SetNum(int index, int num){
  arr[index] = num;  
}

int GetNum(int index){
  return arr[index];
}

void prtArr(){
  int i;
  for (i = 0; i < size; i++){
       printf("arr[%d] = %d, address = %p\n", i, (arr[i]), &arr[i]);  
    }
}

int main(){
    int i;
    
    //CHECK ADD()
    for (i = 0; i < 10; i++){
      AddNum(i);
    }
  prtArr();
    printf("\n");
    
    //CHECK INSERT()
    InsertNum(5, 99);
    InsertNum(6, 999);
    InsertNum(7, 9999);
    prtArr();
    printf("\n");
    
     //CHECK SIZE()
     printf("Array size = %d\n\n", GetSize());
     
     //CHECK REMOVE()
     for (i = 0; i < 5; i++){
      RemoveNum(0);
    }
     prtArr();
    printf("\n");
    
     //CHECK SET()
     for (i = size/2; i < size; i++){
      SetNum(i, i*4);
    }
     prtArr();
    printf("\n");
    
     //CHECK GET()
     printf("Get arr[0] = %d\n\n", GetNum(0));
    return 0; 
}
