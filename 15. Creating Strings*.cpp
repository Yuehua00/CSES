/*
Time limit: 1.00 s
Memory limit: 512 MB

Given a string, your task is to generate all different strings that can be created using its characters.

Input
  The only input line has a string of length n. Each character is between a–z.
Output
  First print an integer k: the number of strings. Then print k lines: the strings in alphabetical order.
Constraints
  1 <= n <= 8

Example
  Input:
    aabac
  Output:
    20
    aaabc
    aaacb
    aabac
    aabca
    aacab
    aacba
    abaac
    abaca
    abcaa
    acaab
    acaba
    acbaa
    baaac
    baaca
    bacaa
    bcaaa
    caaab
    caaba
    cabaa
    cbaaa
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef unsigned long long int ull;

int main(){
    string s;
    vector<string> arr;
    while(cin >> s){
        sort(s.begin(), s.end());
        do{
            arr.emplace_back(s);
        }while(next_permutation(s.begin(), s.end()));

        printf("%d\n", arr.size());
        for(auto i : arr){
            cout << i << endl;
        }
    }

    return 0;
}

/*
我覺得很猛 0.02s 遞迴
#include<bits/stdc++.h>
using namespace std;
set<string> container;
 
void generate_permutation(string& str, int l, int r){
 
    if(l==r){
        container.insert(str);
    }
    else{
        for(int i=l;i<=r;i++){
            swap(str[l],str[i]);
            generate_permutation(str,l+1,r);
            swap(str[l],str[i]);
        }
    }
}
 
int main(){
    int n;
    string str;
    cin>>str;
 
    generate_permutation(str,0,str.size()-1);
    cout << (int)container.size() << "\n";
    for (auto it = container.begin(); it != container.end(); it++)
    cout << *it << "\n";
}
*/

/*
其他人作法
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void f(vector<string>&ans,string& nums,int s)
 {
            if(s==nums.size())
            {
                ans.push_back(nums);
                return;
            }
       unordered_map<int,bool>m;                         // unordered_map 
       for(int i=s;i<nums.size();i++)
       {
           if(m.find(nums[i])!=m.end()) continue;
           m[nums[i]]=true;
           swap(nums[i],nums[s]);
           f(ans,nums,s+1);
           swap(nums[i],nums[s]);
       }
 }
int main()
{
    string nums;
    cin>>nums;
    vector<string>ans;
    f(ans,nums,0);
    set<string>s;
    for(int i=0;i<ans.size();i++)
    {
        s.insert(ans[i]);
    }
    cout<<s.size()<<'\n';
    for(auto val : s)
    {
        cout<<val<<'\n';    
    }   
}
*/
