//Given a string str[0..n-1] and a pattern pat[0..m-1].Write a C++ proram that prints all occurrences of pat[] in str[].You may assume that n > m.
/*
Input:  str[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10
Input:  str[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
*/



// C++ program for implementation of KMP pattern searching algorithm-

#include <bits/stdc++.h>
using namespace std;

// Fills pat_arr[] for given patttern pat[0..M-1]
void compute_pattern(string pat,int m,int pat_arr[])
{
    int len=0; // length of the previous longest prefix suffix
    int i=1;
    pat_arr[0]=0;
    while(i<m)
    {
        if(pat[len]==pat_arr[i])
        {
            len++;
            pat_arr[i]=len;
            i++;
        }
        else if(len!=0)
        {
            len=pat_arr[len-1];
        }
        else  //if (len==0)
        {
            pat_arr[i]=len;
            i++;
        }

    }
}

void KMPSearch(string str, string pat)
{
    int n=str.size();
    int m=pat.size();
    // create pat_arr[] that will hold the longest prefix suffix values for pattern
    int pat_arr[m];
 
    compute_pattern(pat,m,pat_arr); // Preprocess the pattern (calculate pat_arr[] array) 
    int i=0;  //index for str[]
    int j=0; //index for pat[]
    while(i<n)
    {
        if(pat[j]==str[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<"\nPattern found at index:"<<i-j;
            j=pat_arr[j-1];
        }
        else if(i<n && pat[j]!=str[i])
        {
            if(j!=0)
                j=pat_arr[j-1];
            else
                i++;
        }
    }
}

int main()
{
    string str,pat;
    cout<<"Enter the main sring:";
    cin>>str;
    cout<<"\nEnter the pattern to find in main string:";
    cin>>pat;

    KMPSearch(str,pat); 

    return 0;
}
