class Solution {
public:
    int compareVersion(string v1, string v2) {
        if(v1 == v2) {
            return 0;
        }
        int n1 = v1.size();
        int n2 = v2.size();
        vector<int>arr1, arr2;
        string temp = "";
        for(int i = 0; i < n1; i++)
        {
            if(v1[i] != '.') {
                temp.push_back(v1[i]);
            } else {
                arr1.push_back(stoi(temp));
                temp.clear();
            }
        }
        arr1.push_back(stoi(temp));
        temp.clear();
        for(int i = 0; i < n2; i++)
        {
            if(v2[i] != '.') {
                temp.push_back(v2[i]);
            } else {
                arr2.push_back(stoi(temp));
                temp.clear();
            }
        }
        arr2.push_back(stoi(temp));
        n1 = arr1.size(), n2 = arr2.size();
        int n = max(n1, n2);
        for(int i = 0; i < n; i++) {
            int c1 = 0, c2 = 0;
            if(i < n1) {
                c1 = arr1[i];
            }
            if(i < n2) {
                c2 = arr2[i];
            }
            if(c1 > c2) {
                return 1;
            }
            if(c1 < c2) {
                return -1;
            }
        }
        return 0;
    }
};