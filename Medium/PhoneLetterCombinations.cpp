#include <iostream>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits)
{
    const int len = digits.length();
    int sizeOfComb = 1;

    for(char ch: digits)
    {
        if(ch=='7' || ch=='9')
            sizeOfComb *= 4;
        else
            sizeOfComb *= 3;
    }

    vector<string> combinations(sizeOfComb);
    fill(combinations.begin(), combinations.end(), digits);

    string pres;
    int n = 1;

    for(int i=len-1; i>=0; i--)
    {
        switch(digits[i])
        {
            case '2': pres = "abc";break;
            case '3': pres = "def";break;
            case '4': pres = "ghi";break;
            case '5': pres = "jkl";break;
            case '6': pres = "mno";break;
            case '7': pres = "pqrs";break;
            case '8': pres = "tuv";break;
            case '9': pres = "wxyz";break;
        }

        int j=0;

        while(j<sizeOfComb)
            for(char ch: pres)
                for(int k=0; k<n; k++)
                    combinations[j++][i] = ch;

        n *= pres.size();
    }

    return combinations;
}

int main()
{
    vector<string> v = letterCombinations("23");
    for(string str: v)
        cout<<str<<", ";

    return 0;
}