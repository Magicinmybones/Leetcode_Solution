#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int firstUniqChar(string s);

int main() {
    string s = "leetcode";
    int index = firstUniqChar(s);

    if (index != -1) {
        cout << "The first unique character is at index: " << index << endl;
    } else {
        cout << "There is no unique character in the string." << endl;
    }
    
}
int firstUniqChar(string s) {
    int n = s.size();
    unordered_map<char,int> hash;
    queue <int> q;
    for(int i = 0;i<n;i++){
        if(hash[s[i]]==0){
            q.push(i);
        }
        if(hash[s[i]]<=1){
        hash[s[i]]++;
        }
    }
    while(!q.empty()){
        if(hash[s[q.front()]]==1){
            return q.front();
        }
        q.pop();
    }
    return -1;
}