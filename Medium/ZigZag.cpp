//leetcode - 6
#include <iostream>
#include <string>

using namespace std;

string convert(string s, int numRows)
{
    int n = s.length();
    int step = 2*(numRows-1);

    if(n<=numRows || numRows==1)
        return s;

    string ans = "";

    for(int i=0; i<n; i+=step)
    {
        ans += s[i];
    }

    for(int i=1; i<numRows-1; i++)
        for(int j=0; j<n; j+=step)
        {
            if(j+i<n)
                ans += s[j+i];
            if(j+step-i<n)
                ans += s[j+step-i];
        }

    for(int i=numRows-1; i<n; i+=step)
    {
        ans += s[i];
    }

    return ans;
}

int main()
{
    string s = "ABCDEFGHIJKLMNOQRSTUVWXYZ";
    int numRows = 3;

    cout<<convert(s,numRows)<<endl;
}