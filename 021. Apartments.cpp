/*
Time limit: 1.00 s
Memory limit: 512 MB

There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

Input
  The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.
  The next line contains n integers a_1, a_2, \ldots, a_n: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x-k and x+k.
  The last line contains m integers b_1, b_2, \ldots, b_m: the size of each apartment.
Output
  Print one integer: the number of applicants who will get an apartment.
Constraints
  1 <= n, m <= 2 * 10^5
  0 <= k <= 10^9
  1 <= a_i, b_i <= 10^9

Example
  Input:
    4 3 5
    60 45 80 60
    30 60 75
  Output:
    2
*/

/* 我寫的，時間複雜度較高
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n, m, k, ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    int applicant[n+5], apartment[m+5];
    for(int i = 0; i < n; i++){
        cin >> applicant[i];
    }
    for(int i = 0; i < m; i++){
        cin >> apartment[i];
    }
    sort(applicant, applicant+n);
    sort(apartment, apartment+m);


    int now = 0, nowa = 0;
    for(int i = 0; i < m; i++){
        for(int j = now; j < n; j++){
            if(apartment[i] < applicant[j]-k) break;
            if((apartment[i] <= (applicant[j]+k)) && (apartment[i] >= (applicant[j]-k))){
                ans++;
                now = j+1;
                nowa = i+1;
                break;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;

const int nmax=1e6+7;
int a[nmax],b[nmax];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++)
        cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int i=1,j=1,ans=0;
    while (i<=n&&j<=m){
        if (a[i]-k<=b[j]&&a[i]+k>=b[j]){
            ans++;
            i++;
            j++;
        }
        else if (a[i]>b[j])
            j++;
        else
            i++;
    }
    cout<<ans;
    return 0;
}
