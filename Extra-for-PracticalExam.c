// Insertion Sort

#include <stdio.h>

void main() {
    int i, j, temp, n, a, counter = 0, arr[100];
    printf("Enter the size of list: ");
    scanf("%d", &n);
    printf("Enter %d values: ", n);
    for (a = 0; a < n; a++) {
        scanf("%d", &arr[a]);
    }
    printf("\nList before sorting is: ");
    for (a = 0; a < n; a++) {
        printf("%d ", arr[a]);
    }
    counter++;
    for (i = 1; i < n; i++) {
        counter++;
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            counter ++; 
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        counter++; 
        arr[j + 1] = temp;
    }

    printf("\nList after sorting is: ");
    for (a = 0; a < n; a++) {
        printf("%d ", arr[a]);
    }
    printf("\nTime Complexity = %d\n", counter);
}




/*OUTPUT
Enter the size of list: 5
Enter 5 values: 1 2 3 4 5
List before sorting is: 1 2 3 4 5 
List after sorting is: 1 2 3 4 5 
Time Complexity = 9

Enter the size of list: 5
Enter 5 values: 5 1 4 2 3
List before sorting is: 5 1 4 2 3 
List after sorting is: 1 2 3 4 5 
Time Complexity = 15

Enter the size of list: 5
Enter 5 values: 5 4 3 2 1
List before sorting is: 5 4 3 2 1 
List after sorting is: 1 2 3 4 5 
Time Complexity = 19
*/
