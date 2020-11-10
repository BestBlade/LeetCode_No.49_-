/*----------------------------------------------------------------------|
����һ���ַ������飬����ĸ��λ�������һ����ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����

ʾ��:

����: ["eat", "tea", "tan", "ate", "nat", "bat"]
���:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/group-anagrams
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������|
-----------------------------------------------------------------------*/

/*	map
*
*	ִ����ʱ��48 ms, ������ C++ �ύ�л�����99.46%���û�
*	�ڴ����ģ�19.8 MB, ������ C++ �ύ�л�����24.25%���û�
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs){

	vector<vector<string>> res;
	unordered_map<unsigned int, vector<string>> stringmap;

	//ʹ��unsigned int��ֹ���
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