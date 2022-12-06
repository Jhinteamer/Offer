// 内存中的数据由0和1的序列组成。1代表被置位，0代表未置位。因某种需求，要统计内存中数据块的分布情况。数据块为相邻的被置位的连续内存块。为了简便，只需要统计十字相连的内存位置。
// 1. 给定内存映像 mem 为 n*m 数组，例如：
// mem=[
//     ["1","0","1","0","1"],
//     ["0","1","0","1","0"],
//     ["0","0","1","1","0"],
//     ["0","1","0","1","0"],
//     ["1","0","0","0","1"]
//     ]
// 2. 需要返回数据块数量
// blockNum = 7
// 3. 需要返回数据块数量
// 1<= n,m <=100

#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& areas, int x, int y){
    areas[x][y] = 0;
    if(x > 0 && areas[x-1][y] == 1){
        dfs(areas, x-1, y);
    }
    if(x < areas.size()-1 && areas[x+1][y] == 1){
        dfs(areas, x+1, y);
    }
    if(x > 0 && areas[x][y-1] == 1){
        dfs(areas, x, y-1);
    }
    if(x > 0 && areas[x][y+1] == 1){
        dfs(areas, x, y+1);
    }
    return ;
}
int get_block_nums(vector<vector<int>>& areas){
    int n = areas.size();
    int m = areas[0].size();

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(areas[i][j] == 1){
                ans++;
                dfs(areas, i, j);
            }
        }
    }    
    return ans;
}

// mem=[
//     ["1","0","1","0","1"],
//     ["0","1","0","1","0"],
//     ["0","0","1","1","0"],
//     ["0","1","0","1","0"],
//     ["1","0","0","0","1"]
//     ]

int main(){
    vector<vector<int>> areas;
    vector<int> subarea1 = {1, 0, 1, 0, 1};
    vector<int> subarea2 = {0, 1, 0, 1, 0};
    vector<int> subarea3 = {0, 0, 1, 1, 0};
    vector<int> subarea4 = {0, 1, 0, 1, 0};
    vector<int> subarea5 = {1, 0, 0, 0, 1};
    areas.push_back(subarea1);
    areas.push_back(subarea2);
    areas.push_back(subarea3);
    areas.push_back(subarea4);
    areas.push_back(subarea5);
    cout << get_block_nums(areas) << endl;
    return 0;
}