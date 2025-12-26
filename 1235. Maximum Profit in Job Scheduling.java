/*
Problem credits: https://leetcode.com/problems/maximum-profit-in-job-scheduling/

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.


Solution:
    Sort if end time and figire out max profit achieved by this end date.

    Pick Job and see max project by start time of current job. Save the things to TreeMap
*/

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