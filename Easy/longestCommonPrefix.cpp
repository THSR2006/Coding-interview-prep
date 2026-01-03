#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    const int n = strs.size();
    int minLen = 201;
    if(n==1)
        return strs[0];

    for(int i=0; i<n; i++)
        minLen = min(minLen, (int)strs[i].length());

    int j=0;
    char pres;

    while(j<minLen)
    {
        pres = strs[0][j];
        for(int i=1; i<n; i++)
        {
            if(strs[i][j]!=pres)
                return strs[0].substr(0, j);
        }
        j++;
    }
    return strs[0].substr(0, j);
}
int main()
{
    vector<string> v = {"flow", "flower", "flour"};
    cout<<longestCommonPrefix(v);

    return 0;
}