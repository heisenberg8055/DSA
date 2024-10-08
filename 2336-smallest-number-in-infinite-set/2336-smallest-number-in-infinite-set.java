class SmallestInfiniteSet {
    SortedSet<Integer>s = new TreeSet<>();
    public SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
        {
            s.add(i);
        }
    }
    
    public int popSmallest() {
        int ans = s.first();
        s.remove(ans);
        return ans;
    }
    
    public void addBack(int num) {
        if(s.contains(num)==false){
            s.add(num);
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */