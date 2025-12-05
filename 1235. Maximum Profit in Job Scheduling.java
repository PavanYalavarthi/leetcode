class Solution {
    class Job {
        int startTime, endTime, profit;
        Job(int st, int et, int pt){
            startTime = st;
            endTime = et;
            profit = pt;
        }
    }
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        List<Job> jobs = new ArrayList<>();
        for(int i = 0; i<startTime.length; i++)
            jobs.add(new Job(startTime[i], endTime[i], profit[i]));
        jobs.sort(Comparator.comparingInt(job -> job.endTime));
        TreeMap<Integer,Integer> mp = new TreeMap<>();
        int maxProfit = 0;
        for(Job job : jobs){
            Integer beforeStart = mp.floorKey(job.startTime);
            int maxProfitTillNow = beforeStart == null ? 0 : mp.get(beforeStart);
            maxProfit = Math.max(maxProfit, maxProfitTillNow + job.profit);
            mp.put(job.endTime, maxProfit);
        }
        return maxProfit;
    }
}