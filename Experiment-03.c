// Merge Sort C Program

#include <stdio.h>
void Mergesort( int a[], int size ){
if(size<=1){
  return;
}
int mid=size/2;
int left_half[mid];
int right_half[size - mid];
for(int i=0; i<mid; i++){
    left_half[i]=a[i];
}
for(int i=mid; i<size; i++){
    right_half[i-mid]=a[i];
}
Mergesort(left_half, mid);
Mergesort(right_half, size-mid);
Merge(a,left_half, right_half, mid, size - mid);
   }

    void Merge(int a[], int left[], int right[], int left_size, int right_size){
    int i=0,j=0,k=0;
    while(i<left_size && j<right_size)    {
        if(left[i]<=right[j])  {
            a[k]=left[i];
            i++;
        }
        else {
            a[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<left_size)    {
        a[k]=left[i];
        i++;
        k++;
    }
    while(j<right_size)    {
        a[k]=right[j];
        j++;
        k++;
    }
   }
   int main() {
    int arr[100],n;
    printf("Enter no of elements in array: ");
    scanf("%d",&n);
    printf("Enter elements in array: ");
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Initial array: ");
    for(int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    Mergesort(arr, n);
    printf("\nSorted array: ");
    for(int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
      }


/*OUTPUT
Enter no of elements in array: 5
Enter elements in array: 2 29 4 11 31
Initial array: 2 29 4 11 31 
Sorted array: 2 4 11 29 31
*/
