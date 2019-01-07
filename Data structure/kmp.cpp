#include <iostream>
#include<string>
using namespace std;

int kmp(const std::string &text,const std::string &pattern){
    // calculate Next function
    int pattern_length = pattern.length();
    int *next = new int[pattern_length + 1];
    next[0] = -1;
    int k = -1,j = 0;

    while(j<pattern_length){
        if(k == -1 || pattern[j] == pattern[k]){
            j++;
            k++;
            if(pattern[j] != pattern[k] )
                next[j] = k;
            else
                next[j] = next[k];
        }else{
            k = next[k];
        }
    }

    /* match */
    k = -1;
    j = -1;
    int text_length = text.length();
    while(k < pattern_length && j < text_length){
        if(k == -1 || pattern[k] == text[j]){
            k++;
            j++;
        }else{
            k = next[k];
        }
    }

    // match ok!
    if(k == pattern_length ){
        return j - k ;
    }else{
        return -1;
    }

    delete next;
}

int main()
{

    freopen("data.txt","r",stdin);
    string pattern,text;
    while(cin>>text>>pattern){

        clock_t startTime = clock();
        int kmpIndex = kmp(text,pattern);
        clockid_t endTime = clock();
        cout<< "kmp: "<<endTime - startTime <<" ms \t";

        startTime = clock();
        int stringIndex = text.find(pattern);
        endTime = clock();
        cout<< "string index: "<<endTime - startTime <<" ms\n";

        if(stringIndex != kmpIndex){
            cout<<" error " <<endl;
        }

       // cout<< stringIndex <<" " <<kmpIndex <<endl;
    }
    return 0;
}
