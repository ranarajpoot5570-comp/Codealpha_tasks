#include<iostream>
using namespace std;
bool is_Valid(int grid[9][9],int row,int col,int num){ 
    for(int x=0;x<9;x++){ 
    if(grid[row][x]==num || grid[x][col]==num)
    return false;
    }
    int startrow=row-row%3;
    int startcol=col-col%3;
    for(int i=0;i<3;i++){ 
        for(int j=0;j<3;j++){ 
            if(grid[startrow + i][startcol + j]==num)
            return false;
        }
    }
    return true;
}
bool Sudoku_Solver(int grid[9][9]){ 
    for(int i=0;i<9;i++){ 
        for(int j=0;j<9;j++){ 
            if(grid[i][j]==0){ 
                for(int n=1;n<=9;n++){ 
                    if(is_Valid(grid,i,j,n)){ 
                        grid[i][j]=n;
                        if(Sudoku_Solver(grid))
                        return true;
                        grid[i][j]=0;
                    }

                }
                return false;
            }
        }
   
    }
    return true;
}
int main(){ 
    int box[9][9];
   cout<<"Enter your Sudoku puzzle."<<endl;
cout<<"Rules:"<<endl;
cout<<"- Enter 9 numbers in each row"<<endl;
cout<<"- Separate numbers with spaces"<<endl;
cout<<"- Use 0 for blank cells"<<endl;
cout<<endl;
cout<<"Now enter the puzzle:"<<endl;
    for (int i=0;i<9;i++){ 
        for(int j=0;j<9;j++){ 
            cin>>box[i][j];
        }
    }
    Sudoku_Solver(box);
    cout<<"Sudoku solved puzzle"<<endl;
    for (int i=0;i<9;i++){ 
        for(int j=0;j<9;j++){ 
            cout<<box[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}