// 有一种速记方式，针对重复内容有一套独特的缩写规则：

// 重复的部分会被以 "(重复内容)<重复次数>" 形式记录，并且可能存在嵌套缩写关系。不重复的部分按照原样记录。
// 现给一个符合此速记方式的字符串 records，请以字符串形式返回复原后的内容。
// 注： records 仅由小写字母、数字及<, >, (, )组成。

// 示例 1：

// 输入：records = "abc(d)<2>e"

// 输出："abcdde"

// 解释：字符串中出现 "(d)<2>"，表示 "d" 重复出现 2 次，因此返回复原后的内容 "abcdde"。

// 示例 2：

// 输入：records = "a(b(c)<3>d)<2>e"

// 输出："abcccdbcccde"

// 解释：字符串中出现 "a(b(c)<3>d)<2>"，其中 "(c)<3>" 表示 "c" 出现 3 次，复原为 "ccc"；"(bcccd)<2>" 表示 "bcccd" 重复出现 2 次，复原为 "bcccdbcccd"。最终返回复原后内容 "abcccdbcccde"

// 提示：

// 1 <= records.length <= 200
// 2 <= 重复次数 <= 10
// 题目保证返回结果字符串长度小于等于 10^4
// 输入保证合法，确保括号与尖括号成对出现
// 嵌套深度不超过 13

#include <bits/stdc++.h>
using namespace std;

string get_string(string& str, int& idx){
    string substr = "";
    string ss = "";
    while(idx < str.size()){
        char ch = str[idx];
        if(ch == '('){
            idx++;
            ss = get_string(str, idx);
        }
        else if(ch == ')'){
            idx++;
            return substr;
        }
        else if(ch == '<'){
            idx++;
            int times = str[idx] - '0';
            idx++;
            while(str[idx] - '0' >= 0 && str[idx] - '0' <= 9){
                idx++;
                times *= 10;
                times += str[idx] - '0';
            }
            while(times--){
                substr = substr + ss;
            }
            idx++;
        }
        else{
            substr += str[idx];
            idx++;
        }
    }
    return substr; 
}
int main(){
    string str = "a(b(c)<3>d)<2>e";
    int idx = 0;
    cout << get_string(str, idx) << endl;
    return 0;
}