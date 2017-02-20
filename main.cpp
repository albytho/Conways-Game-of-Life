//
//  main.cpp
//  Conway
//
//  Created by Alby Thomas on 2/18/17.
//  Copyright © 2017 Alby Thomas. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct coordinate{
    coordinate(char mark_in, int row_in, int column_in):  mark(mark_in), row(row_in), column(column_in){}
    char mark;
    int row;
    int column;
};

bool atBorder(int size, int row, int column){
    if(row == 0 || row == size-1 || column == 0 || column == size-1){
        return true;
    }
    return false;
}

int non_Border_NeighborCount(vector<vector<coordinate>> &map, int row, int column){
    int count = 0;
    
    //Direct Sides
    if(map[row+1][column].mark == 'X'){
        ++count;
    }
    if(map[row][column-1].mark == 'X'){
        ++count;
    }
    if(map[row-1][column].mark == 'X'){
        ++count;
    }
    if(map[row][column+1].mark == 'X'){
        ++count;
    }
    
    //Diagonals
    if(map[row-1][column+1].mark == 'X'){
        ++count;
    }
    if(map[row-1][column-1].mark == 'X'){
        ++count;
    }
    if(map[row+1][column+1].mark == 'X'){
        ++count;
    }
    if(map[row+1][column-1].mark == 'X'){
        ++count;
    }
    
    return count;
}

int row_0_NeighborCount(vector<vector<coordinate>> &map, int row, int column, int size){
    int count = 0;
    
    if(map[row+1][column].mark == 'X'){
        ++count;
    }
    
    if(column == 0){
        if(map[row][column+1].mark == 'X'){
            ++count;
        }
        if(map[row+1][column+1].mark == 'X'){
            ++count;
        }
    }
    else if(column == size-1){
        if(map[row][column-1].mark == 'X'){
            ++count;
        }
        if(map[row+1][column-1].mark == 'X'){
            ++count;
        }
    }
    else{
        if(map[row][column-1].mark == 'X'){
            ++count;
        }
        if(map[row][column+1].mark == 'X'){
            ++count;
        }
        if(map[row+1][column-1].mark == 'X'){
            ++count;
        }
        if(map[row+1][column+1].mark == 'X'){
            ++count;
        }
    }
    
    return count;
}

int row_last_NeighborCount(vector<vector<coordinate>> &map, int row, int column, int size){
    int count = 0;
    
    if(map[row-1][column].mark == 'X'){
        ++count;
    }
    
    if(column == 0){
        if(map[row][column+1].mark == 'X'){
            ++count;
        }
        if(map[row-1][column+1].mark == 'X'){
            ++count;
        }
    }
    else if(column == size-1){
        if(map[row][column-1].mark == 'X'){
            ++count;
        }
        if(map[row-1][column-1].mark == 'X'){
            ++count;
        }
    }
    else{
        if(map[row][column-1].mark == 'X'){
            ++count;
        }
        if(map[row][column+1].mark == 'X'){
            ++count;
        }
        if(map[row-1][column-1].mark == 'X'){
            ++count;
        }
        if(map[row-1][column+1].mark == 'X'){
            ++count;
        }
    }
    
    return count;
}

int col_one_between_firstandlast_row_NeighborCount(vector<vector<coordinate>> &map, int row, int column, int size){
    int count = 0;
    
    if(map[row+1][column].mark == 'X'){
        ++count;
    }
    if(map[row-1][column].mark == 'X'){
        ++count;
    }
    if(map[row][column+1].mark == 'X'){
        ++count;
    }
    if(map[row-1][column+1].mark == 'X'){
        ++count;
    }
    if(map[row+1][column+1].mark == 'X'){
        ++count;
    }
    
    return count;
}

int col_last_between_firstandlast_row_NeighborCount(vector<vector<coordinate>> &map, int row, int column, int size){
    int count = 0;
    
    if(map[row+1][column].mark == 'X'){
        ++count;
    }
    if(map[row-1][column].mark == 'X'){
        ++count;
    }
    if(map[row][column-1].mark == 'X'){
        ++count;
    }
    if(map[row-1][column-1].mark == 'X'){
        ++count;
    }
    if(map[row+1][column-1].mark == 'X'){
        ++count;
    }
    
    return count;
}

int main() {
    int size = 0;
    int cycle_count = 0;
    vector<vector<coordinate>> map;
    vector<coordinate> temp;
    
    cout<<"Enter the size of the grid:  ";
    cin>>size;
    
    cout<<"Enter the number of cycles:  ";
    cin>>cycle_count;
    
    char mark;
    
    for(uint row=0; row<size; ++row){
        for(uint column=0; column<size; ++column){
            if(rand() % 2 == 0){
                mark = '.';
            }
            else{
                mark = 'X';
            }
            temp.push_back(coordinate(mark,row,column));
        }
        map.push_back(temp);
        temp.clear();
    }
    
    
    int neigbhors = 0;
    while(cycle_count != 0){
        for(uint r = 0; r<map.size(); ++r){
            for(uint c = 0; c<map.size(); ++c){
                cout<<map[r][c].mark<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
        for(uint r=0; r<map.size(); ++r){
            for(uint c=0; c<map.size(); ++c){
                
                //Actions if the coordinate is and X or "Alive"
                if(map[r][c].mark == 'X'){
                    //If the coordinate is NOT at border of map
                    if(!atBorder(size, r, c)){
                        neigbhors = non_Border_NeighborCount(map, r, c);
                        if(neigbhors > 3 || neigbhors < 2){
                            map[r][c].mark = '.';
                        }
                    }
                    
                    //If the coordinate IS at the border of map
                    else{
                        if(r == 0){
                            if(row_0_NeighborCount(map, r, c, size) < 2){
                                map[r][c].mark = '.';
                            }
                        }
                        else if(r == size-1){
                            if(row_last_NeighborCount(map, r, c, size) < 2){
                                map[r][c].mark = '.';
                            }
                        }
                        else if(c == 0){
                            if(col_one_between_firstandlast_row_NeighborCount(map, r, c, size) < 2){
                                map[r][c].mark = '.';
                            }
                        }
                        else if(c == size-1){
                            if(col_last_between_firstandlast_row_NeighborCount(map, r, c, size) < 2){
                                map[r][c].mark = '.';
                            }
                        }
                    }
                }
                
                //Actions if the coordinate is and O or "Dead"
                else{
                    //If the coordinate is NOT at border of map
                    if(!atBorder(size, r, c)){
                        neigbhors = non_Border_NeighborCount(map, r, c);
                        if(neigbhors == 3){
                            map[r][c].mark = 'X';
                        }
                    }
                    
                    //If the coordinate IS at the border of map
                    else{
                        if(r == 0){
                            if(row_0_NeighborCount(map, r, c, size) == 3){
                                map[r][c].mark = 'X';
                            }
                        }
                        else if(r == size-1){
                            if(row_last_NeighborCount(map, r, c, size) == 3){
                                map[r][c].mark = 'X';
                            }
                        }
                        else if(c == 0){
                            if(col_one_between_firstandlast_row_NeighborCount(map, r, c, size) == 3){
                                map[r][c].mark = 'X';
                            }
                        }
                        else if(c == size-1){
                            if(col_last_between_firstandlast_row_NeighborCount(map, r, c, size) == 3){
                                map[r][c].mark = 'X';
                            }
                        }
                    }
                }
                
                //Resets neigbhor back to 0
                neigbhors = 0;
            }
        }
        
        --cycle_count;
    }
    
    
    
    return 0;
}
