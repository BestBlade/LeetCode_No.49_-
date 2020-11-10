/*----------------------------------------------------------------------|
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-----------------------------------------------------------------------*/

/*	map
*
*	执行用时：48 ms, 在所有 C++ 提交中击败了99.46%的用户
*	内存消耗：19.8 MB, 在所有 C++ 提交中击败了24.25%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs){

	vector<vector<string>> res;
	unordered_map<unsigned int, vector<string>> stringmap;

	//使用unsigned int防止溢出
	unsigned int plus, multiply;
	for (auto s : strs) {
		plus = 0;
		multiply = 1;
		for (auto x : s) {
			multiply *= x;
			plus += x;
		}
		stringmap[multiply + plus].emplace_back(s);
	}

	for (auto x : stringmap) {
		res.emplace_back(x.second);
	}
	return res;
}