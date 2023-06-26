class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x == y){
            return (2 * z) + (4 * y);
        }
        return (2 * z) + (2 * (1 + min(x, y))) + (2 * min(x, y));
    }
};