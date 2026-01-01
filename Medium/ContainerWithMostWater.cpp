//leetcode - 11
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height)
{
    int left = 0;
    int right = height.size()-1;
    int current_area;
    int max_area = 0;

    while(left < right)
    {
        current_area =  min(height[left], height[right]) * (right-left);
        max_area = max(max_area, current_area);

        if(height[left]<height[right])
            left++;
        else
            right--;
    }

    return max_area;
}
int main()
{
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(v);
}