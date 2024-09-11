#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size();

    set<int> s(nums.begin(), nums.end());

    if (s.size() > n / 2) return n / 2;

    return s.size();
}