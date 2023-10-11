#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        //pair<int, int> -> pair<score, id>
        unordered_set<string> pos_map, neg_map;
        for (auto str : positive_feedback) {
            pos_map.emplace(str);
        }
        for (auto str : negative_feedback) {
            neg_map.emplace(str);
        }
        int n = (int)report.size();
        vector<pair<int, int>> vpii(n);
        for (int i = 0; i < n; ++i) {
            string str = report[i];
            string tmp = "";
            int len = (int)str.size(), j = 0;
            while (j <= len) {
                if (j == len || str[j] == ' ') {
                    if (pos_map.find(tmp) != pos_map.end()) {
                        vpii[i].first += 3;
                    } else if (neg_map.find(tmp) != neg_map.end()) {
                        vpii[i].first -= 1;
                    }
                    tmp = "";
                    ++j;
                    continue;
                }
                tmp += str[j++];
            }
            vpii[i].second = student_id[i];
        }

        // cout << "--------------" << endl;
        // for (int i = 0; i < n; ++i) {
        //     cout << vpii[i].first << " " << vpii[i].second << endl;
        // }
        // cout << "--------------" << endl;
        
        sort(vpii.begin(), vpii.end(), [&] (pair<int, int> &a, pair<int, int> &b) -> bool {
            if (a.first > b.first) return true;
            if (a.first == b.first) return a.second < b.second;
            return false;
        });
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.emplace_back(vpii[i].second);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    vector<string> positive_feedback {"yewmhbgnq","vqhhuaejqw"};
    vector<string> negative_feedback {"zjeyq","oyuetqe","ks","vuvannpwa","qfd","xv","aauvtxrdt","gml","eaky","mwip"};
    vector<string> report {"lqiuderzod mwip vqhhuaejqw xrn aqjzkqjsi riuood yewmhbgnq xv nmcvqm onhkkmy",\
                           "uccz yewmhbgnq rcxdaqicbe vqhhuaejqw yewmhbgnq e vqhhuaejqw b yewmhbgnq vqhhuaejqw",\
                           "eaky yewmhbgnq eaky dwdzl yewmhbgnq yewmhbgnq ntqpnqtmnb qfd ks gvumi",\
                           "ecutvv vqhhuaejqw vqhhuaejqw inu vqhhuaejqw vqhhuaejqw uu eodzum zjeyq fxebx",\
                           "vqhhuaejqw m vuvannpwa mwip atvjp vqhhuaejqw eaky yewmhbgnq vqhhuaejqw yewmhbgnq"};
    vector<int> student_id {581094748,245764367,905556075,127263030,415068015};
    int k = 4;
    vector<int> res = s->topStudents(positive_feedback, negative_feedback, report, student_id, k);
    for (int i = 0, n = (int)res.size(); i < n; ++i) {
        cout << res[i] << " \n"[i == n - 1];
    }
    delete s;
    return 0;
}