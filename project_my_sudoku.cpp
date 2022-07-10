#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 9
int sudoku_matrix[N][N];
bool check(int row, int col, int num);
bool Empty(int &row, int &col);

/* assign values to all the zero (not assigned) values for Sudoku solution
 */
bool Solve()
{
    int row, col;
    if (!Empty(row, col))
       return 1;
    for (int num = 1; num <= 9; num++)
    {
        if (check(row, col, num))
        {
            sudoku_matrix[row][col] = num;
            if (Solve())
                return 1;
            sudoku_matrix[row][col] = 0;
        }
    }
    return 0;
}

/* Check for entries that don't have an assigned value. */
bool Empty(int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (sudoku_matrix[row][col] == 0)
                return 1;
    return 0;
}

/* To check whether the number matches with any number in the same row */

bool row_match(int prow, int number)
{
    for (int col = 0; col < N; col++)
        if (sudoku_matrix[prow][col] == number)
            return 1;
    return 0;
}

/* To check whether the number matches with any number in the same column */
bool col_match(int pcol, int number)
{
    for (int row = 0; row < N; row++)
        if (sudoku_matrix[row][pcol] == number)
            return 1;
    return 0;
}

//Checking if the value used is already in the grid box
bool box_match(int boxBeginRow, int boxBeginCol, int number)

{
    bool tf = 0;
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (sudoku_matrix[row+boxBeginRow][col+boxBeginCol] == number)
                tf = 1;
    return tf;
}

/* Checks if num can be assigned to the given location. */
bool check(int prow, int pcol, int number)
{
    return !row_match(prow, number) && !col_match(pcol, number) &&
           !box_match(prow - prow % 3 , pcol - pcol % 3, number);
}

void printSudoku()
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout<< sudoku_matrix[row][col]<<"  ";
        cout<<endl;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int flag = 0, row, col, value;
    cout << "do you want to enter values at particular place in the sudoku? if yes press 1 else 0" << endl;
    cin >> flag;
    while(flag){
        cout << "enter position of row, column and value at this position" << endl;
        cin >> row >> col >> value;
        sudoku_matrix[row][col] = value;
        cout << "do you want to enter values at particular place in the sudoku? if yes press 1 else 0" << endl;
        cin >> flag;
    }

    if (Solve()==1)
          printSudoku();
    else
        cout<<"No solution found"<<endl;

    return 0;
    
}