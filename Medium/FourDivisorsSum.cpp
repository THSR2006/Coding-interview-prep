#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int sumFourDivisors(vector<int>& nums)
{
    int ans = 0;

    int len = nums.size();
    int count, limit, sumOfDivisors;

    for(int i=0; i<len; i++)
    {
        count = 0;
        limit = sqrt(nums[i]);
        sumOfDivisors = 0;

        for(int j=2; j<=limit; j++)
        {
            if(nums[i]%j==0)
            {
                if(j*j==nums[i])
                {
                    sumOfDivisors += j;
                    count+=1;
                }
                else
                {
                    sumOfDivisors += (j + nums[i]/j);
                    count+=2;
                }

                if(count>2)
                    break;
            }
        }
        if(count==2)
                ans += (sumOfDivisors + nums[i] + 1);
    }
    return ans;
}

int main()
{
    vector<int> v = {21,21,5,7};
    cout<<sumFourDivisors(v)<<endl;
}