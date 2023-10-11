// N Queen's Problem C Program

#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10 // Maximum board size

int queens[MAX_N]; // Array to store column positions of queens

int absDiff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

bool isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        // Check if the queens threaten each other in the same column or diagonals
        if (queens[i] == col || absDiff(queens[i], col) == absDiff(i, row)) {
            return false;
        }
    }
    return true;
}

void printSolution(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", queens[i]);
    }
    printf("\n");
}
int counter=0;

void solveNQueens(int row, int n) {
    
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            queens[row] = col;
            if (row == n) {
                printSolution(n);
            } 
            else {
                counter++;
                solveNQueens(row + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &n);

    if (n == 2 || n == 3) {
        printf("No solution exist for N = %d.\n", n);
    } 
    else if (n >= 1 && n <= MAX_N) {
        printf("Solutions for N = %d:\n",n);
        solveNQueens(1, n);
        printf("Time Complexity = %d\n", counter);
    } 
    else {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_N);
    }
}




/*OUTPUT
Enter the size of the chessboard (N): 0
Invalid input. Please enter a number between 1 and 10.


Enter the size of the chessboard (N): 3
No solution exist for N = 3.


Enter the size of the chessboard (N): 5
Solutions for N = 5:
1 3 5 2 4 
1 4 2 5 3 
2 4 1 3 5 
2 5 3 1 4 
3 1 4 2 5 
3 5 2 4 1 
4 1 3 5 2 
4 2 5 3 1 
5 2 4 1 3 
5 3 1 4 2 
Time Complexity = 43
*/



/* Reason for time complexity not coming N!
In the N-Queens problem, you're trying to place N chess queens on an N×N chessboard in such a way that no two queens threaten each other. 
The number of different ways you can arrange these queens grows very quickly as the size of the board (N) increases.

For N=5, there are indeed 120 different ways to place the queens (expressed as 5!). 
But not all arrangements need to be explored to find a solution. 
The algorithm you're using employs a technique called backtracking. 
It systematically explores different combinations of queen placements but "backtracks" when it realizes that a certain arrangement cannot lead to a solution.

In N=5 case, the algorithm explored 43 different combinations before finding a solution. 
These 43 combinations represent the number of recursive calls made by the algorithm for this specific scenario. 
The reason it's less than 120 is due to backtracking - the algorithm doesn't blindly try all possible combinations 
but prunes the search space intelligently based on the constraints of the problem.

If you were to try N=8, the total number of possible combinations would be 8! = 40,320. 
The algorithm would still make far fewer than 40,320 recursive calls due to backtracking, 
but it would be significantly more than the 43 calls made for N=5.

So, in summary, the number of recursive calls (43 for N=5) represents the specific path the algorithm took through the search space, 
but the total number of possible combinations (N!) illustrates the vastness of the problem space.
*/
