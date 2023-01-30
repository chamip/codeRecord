/*
  leetcode.68
  给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
  你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 
  maxWidth 个字符。
  要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
  文本的最后一行应为左对齐，且单词之间不插入额外的空格。
  注意:
    单词是指由非空格字符组成的字符序列。 
    每个单词的长度大于 0，小于等于 maxWidth。
    输入单词数组 words 至少包含一个单词。
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  
  string blank(int n) {
    return string(n, ' ');
  }

  string join(vector<string> &words, int left, int right, string sep) {
    string s = words[left];
    for (int i = left + 1; i < right; ++i) {
      s += sep + words[i];
    }
    return s;
  }

public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> res;
    int right = 0, n = (int)words.size();
    while (true) {
      int left = right;
      int subLen = 0;
      while (right < n && subLen + words[right].size() + right - left <= maxWidth) {
        subLen += words[right++].size();
      }
      cout << "----" << subLen << endl;
      cout << "left: " << left << ", right: " << right << endl; 
      if (right == n) {
        string s = join(words, left, right, " ");
        res.emplace_back(s + blank(maxWidth - s.size()));
        break;
      }
      
      int numWords = right - left;
      int numSpaces = maxWidth - subLen;

      if (numWords == 1) {
        res.emplace_back(words[left] + blank(numSpaces));
        continue;
      }

      int avgSpaces = numSpaces / (numWords - 1);
      int extraSpaces = numSpaces % (numWords - 1);
      string s1 = join(words, left, left + extraSpaces + 1, blank(avgSpaces + 1));
      string s2 = join(words, left + extraSpaces + 1, right, blank(avgSpaces));
      res.emplace_back(s1 + blank(avgSpaces) + s2);
    }
    return res;
  }
};
int main(int argc, char const *argv[])
{
	//int n;
	//cin >> n;
	//cout << n * n << endl << "hello, world!" << endl;
	vector<string> words {"This", "is", "an", "example", "of", "text", "justification."};
  int maxWidth = 16;
  Solution *s = new Solution();
  vector<string> res = s->fullJustify(words, maxWidth);
  for (const auto &str : res) {
    cout << str << endl;
  }
  return 0;
}
