#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int n = nums.size();
    int count = 1;
    int prev = nums[0];

    for(int i=1, j=1; i<n; i++)
    {
        if(prev!=nums[i])
        {
            nums[j++] = nums[i];
            count++;
            prev = nums[i];
        }
    }

    return count;
}
int main()
{
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(v);

    for(int i=0; i<k; i++)
    {
        cout<<v[i]<<',';
    }
}