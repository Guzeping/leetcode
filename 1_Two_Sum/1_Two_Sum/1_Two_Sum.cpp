#include<cstdio>
#include<vector>
#include<algorithm>
using namespace::std;

vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int> vnums = nums;
	sort(vnums.begin(), vnums.end(),less<int>());
	int first = 0, second = nums.size() - 1;
	while (vnums[first] + vnums[second] != target) {
		if (vnums[first] + vnums[second] > target)
		{
			second--;
		}
		else if(vnums[first] + vnums[second] < target)
		{
			first++;
		}
		else 
		{
			int i=0, j = 0;
			while (nums[i] != vnums[first]) {
				i++;
			}
			while (nums[j] != vnums[second]) {
				j++;
			}
			vector<int> result;
			result.push_back(i);
			result.push_back(j);
			return result;
		}
	}

	
}

bool my_less(const int &a, const int &b) {
	return a < b;
}
bool my_greater(const int &a, const int &b) {
	return a > b;
}
int main() 
{
	vector<int> a;
	int n;
	scanf_s("%d", &n, 1);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf_s("%d", &tmp, 1);
		a.push_back(tmp);
	}
	int target;
	scanf_s("%d", &target, 1);
	vector<int> result=twoSum(a, target);
	return 0;
}