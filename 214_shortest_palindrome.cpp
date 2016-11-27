/* Solution 1*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s.rbegin(),s.rend());// get reverse string
        const int s_size(s.size());
        int len(s_size);// the minimum length from the reverse string we need to add before s
        for (len=s_size;len>=0;--len) {
			if (s.substr(0,len) == rev.substr(s_size-len)) break;
        }
        return rev.substr(0,s_size-len)+s;
    }
};

/* Solution 2*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rever(s.rbegin(),s.rend());
        string mirror = s + '#' + rever;
        vector<int> kmp = get_kmp(mirror);
        int len = kmp[mirror.size()-1];
        return rever.substr(0,s.size()-len) + s;
    }
private:
    vector<int> get_kmp(const string & s) {
        const int N(s.size());
        vector<int> res(N,0);
        int pos(1),len(0);
        while(pos<N){
            if(s[pos] == s[len]) {
                res[pos] = len + 1;
                ++ pos;
                ++ len;
            } else {
                if(len==0) {
                    res[pos] = 0;
                    ++ pos;
                } else {
                    len = res[len-1];
                }
            }
        }
        return res;
    }
};
