#include <bits/stdc++.h>
using namespace std;

// 首先我们先证明一个定理
// 如果s-t为无向图的最长路径（s,t为节点标号）
// 那么从任意节点深搜得到的最深的节点一定是s或者t
// 首先，无向图从任意节点出发可以访问全图（连通图）
// 如果从任意节点走到最深节点的路径没有经过s-t，那么与s-t是最长路径矛盾
// 那么如果经过s-t里的节点，并没有沿着s-t这条路径走
// 设走到与s-t路径相交的节点前的路径长度为x1，沿着s-t路径走的话最长余下长度为x2，
// 不沿着s-t路径走的最长余下长度为x3，s-t路径长度减去x2的长度为x4
// x2+x4为最长 x1+x3>x1+x2 推出 x3>x2 推出 x2+x4<x3+x4
// 故矛盾
// 所以我们知道结论正确

int find_longest_node(vector<int>& values, vector<vector<int>>& nodes, int idx){
    
}
int main(){
    int n;
    cin >> n;
    vector<int> values;
    vector<vector<int>> nodes(n);
    queue<int> has;
    int idx = 0;
    int flag = 0;
    for(int i=0;i<n;i++){
        int pp;
        cin >> pp;
        if(has.empty()){
            flag = 0;
            values.push_back(pp);
            has.push(idx);
            idx++;
        }
        else{
            if(pp == -1){
                flag++;
            }else{
                
                int curnode = has.front();

                values.push_back(pp);

                nodes[idx].push_back(curnode);
                nodes[curnode].push_back(idx);
                
                // 新节点加入队列
                has.push(idx);

                idx++;
                flag++;
            }

            if(flag >= 3){
                has.pop();
                flag = 0;
            }
        }

    }

    // wait();
    int nod = find_longest_node(values, nodes);

    return 0;
}