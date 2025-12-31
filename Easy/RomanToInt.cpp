#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> m = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

    int i = s.length()-1;
    int j = s.length()-1;

    int ans = 0;

    ans += m[s[i--]];

    while(i>=0)
    {
        (m[s[i]]>=m[s[j]])? ans += m[s[i]]: ans -= m[s[i]];
        i--;
        j--;
    }

    return ans;
}

int romanToIntUsingSwitch(string s)
{   
    int ans=0;
    int num=0;
    int prev=0;

    for(int i=s.length()-1; i>=0; i--)
    {
        switch(s[i])
        {
            case 'I': num = 1; break;
            case 'V': num = 5; break;
            case 'X': num = 10; break;
            case 'L': num = 50; break;
            case 'C': num = 100; break;
            case 'D': num = 500; break;
            case 'M': num = 1000; break;
        }
        
        if(num>=prev)
            ans+=num;
        else
            ans-=num;

        prev = num;
    }
    return ans;
}
int main()
{
    string s = "XII";
    cout<<romanToInt(s)<<endl;
}