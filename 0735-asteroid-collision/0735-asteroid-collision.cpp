class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto asteroid:asteroids)
        {
            int flag = 1;
            while(st.empty() == false && (st.top() > 0 && asteroid < 0))
            {
                if(abs(st.top()) < abs(asteroid))
                {
                    st.pop();
                    continue;
                }
                else if(abs(st.top()) == abs(asteroid))
                {
                    st.pop();
                }
                flag = 0;
                break;
            }
            if(flag)
            {
                st.push(asteroid);
            }
        }
        vector<int>ans(st.size());
        for(int i = st.size() -1 ; i >= 0 ; i--)
        {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};