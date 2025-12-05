class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int maxi = 0;
        for(int i :candies)
            maxi = Math.max(maxi, i);
        List<Boolean> l = new ArrayList<>(candies.length);
        for(int i : candies) 
            l.add(i + extraCandies >= maxi);
        return l;
    }
}