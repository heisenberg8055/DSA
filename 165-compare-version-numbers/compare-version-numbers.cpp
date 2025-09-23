class Solution {
private:
    vector<int> parse(string& s) {
        vector<int>ans;
        stringstream ss(s);
        string temp;
        while(getline(ss, temp, '.')) {
            ans.push_back(stoi(temp));
        }
        return ans;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int>arr1 = parse(version1);
        vector<int>arr2 = parse(version2);
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = max(n1, n2);
        for(int i = 0; i < n; i++)
        {
            int c1 = 0, c2 = 0;
            if(i < n1) {
                c1 = arr1[i];
            }
            if (i < n2) {
                c2 = arr2[i];
            }
            if(c1 < c2) {
                return -1;
            }
            if(c1 > c2) {
                return 1;
            }
        }
        return 0;
    }
};