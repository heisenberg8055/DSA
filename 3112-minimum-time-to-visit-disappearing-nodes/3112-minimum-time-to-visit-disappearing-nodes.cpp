class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
          vector<int>minTime(n,-1);
    
    vector<vector<pair<int,long>>>edge(n);
    
    for(auto x:edges){
          edge[x[0]].push_back({x[1],x[2]});
          edge[x[1]].push_back({x[0],x[2]});
    }
    
    priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>>pq;
    pq.push({0,0});
    
    while(!pq.empty()){
        
        
         pair<long,int>p=pq.top();
         pq.pop();
         
         if(p.first>=disappear[p.second] or minTime[p.second]!=-1)continue;
         minTime[p.second]=p.first;
        
         for(auto x:edge[p.second]){
             pq.push({p.first+x.second,x.first});
         }
        
    }
    
  return minTime;  
    }
};