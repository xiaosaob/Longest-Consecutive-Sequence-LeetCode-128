// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

// Your algorithm should run in O(n) complexity.

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(!num.size()) return 0;
        unordered_map<int, int> lenByNum;
        int maxLen = 1;
        for(int i = 0; i < num.size(); ++i) {
            if(!lenByNum.count(num[i])) {
                lenByNum[num[i]] = 1;
                if(lenByNum.count(num[i]-1)) {
                    int len = lenByNum[num[i]-1];
                    lenByNum[num[i]-len] = len+1;
                    lenByNum[num[i]] = len+1;
                    maxLen = max(maxLen, len+1);
                } 
                if(lenByNum.count(num[i]+1)) {
                    int rlen = lenByNum[num[i]+1];
                    int llen = lenByNum[num[i]];
                    lenByNum[num[i]+rlen] = llen+rlen;
                    lenByNum[num[i]-llen+1] = llen+rlen;
                    maxLen = max(maxLen, llen+rlen);
                }
            }
        }
        return maxLen;
    }
};
