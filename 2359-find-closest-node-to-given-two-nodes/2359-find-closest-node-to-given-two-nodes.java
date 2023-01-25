class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        boolean[] v1 = new boolean[edges.length];
        boolean[] v2 = new boolean[edges.length];
        v1[node1] = true;
        v2[node2] = true;
        while(true)
        {
            if(v1[node2] && v2[node1])
            {
                return Math.min(node1,node2);
            }
            if(v1[node2])
            {
                return node2;
            }
            if(v2[node1])
            {
                return node1;
            }
            if(edges[node1] == -1 && edges[node2] == -1)
            {
                return -1;
            }
            if(edges[node1]>=0)
            {
                node1=edges[node1];
            }
            if(edges[node2]>=0)
            {
                node2 = edges[node2]; 
            }
            if(v1[node1] && v2[node2])
            {
                return -1;
            }
            v1[node1]=true;
            v2[node2]=true;
        }
    }
}