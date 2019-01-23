/*************************************************************************
	> File Name: generate-data.cpp
	> Author: Lewin 
	> Mail: 2596736318@qq.com
	> Created Time: Fri 07 Dec 2018 09:31:13 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    cout<<t<<endl;
    while(t--){
        int n =rand()%991;
        cout<<n<<endl;
        while(n--){
            cout<<rand()%1111<<" ";
        }
        cout<<endl;
    }
}
