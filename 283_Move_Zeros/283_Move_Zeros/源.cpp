#include<vector>
using namespace::std;
void moveZeros(vector<int>& nums);
void main() {
	vector<int> a1;
	a1.push_back(1);
	a1.push_back(0);
	a1.push_back(3);
	moveZeros(a1);


}
void moveZeros(vector<int>& nums) {
	vector<int>::iterator itr = nums.begin();
	int length = nums.size();
	int i = 0;
	while (i<length) //限制循环次数
	{
		i++;
		if (*itr == 0) {
			itr=nums.erase(itr);
			nums.push_back(0);
		}
		else
		{
			itr++;
		}
	}
}
void moveZeroes2(std::vector<int>& nums) {
	int pos = 0;
	int length = nums.size();
	for (int i = 0; i < length; i++)
	{
		if (nums[i]) {
			nums[pos++] = nums[i];
		}
	}
	for (int i = pos; i < length; i++) {
		nums[i] = 0;
	}
}