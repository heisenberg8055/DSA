class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i = 0;
        int n = students.size();
        deque<int>q;
        for(int i = 0; i < n; i++)
        {
            q.push_back(students[i]);
        }
        int cnt = 0;
        while(i < n && cnt < q.size())
        {
            int temp = q.front();
            q.pop_front();
            if(temp == sandwiches[i])
            {
                i++;
                cnt = 0;
            }
            else{
                cnt++;
                q.push_back(temp);
            }
        }
        return q.size();
    }
};