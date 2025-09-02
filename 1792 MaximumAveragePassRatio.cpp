class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](double pass, double total) {
            return (pass + 1) / (total + 1) - pass / total;
        };

        priority_queue<tuple<double, double, double>> pq;
        for (auto& cls : classes) {
            double pass = cls[0], total = cls[1];
            pq.emplace(gain(pass, total), pass, total);
        }

        while (extraStudents--) {
            auto [_, pass, total] = pq.top(); pq.pop();
            pass += 1;
            total += 1;
            pq.emplace(gain(pass, total), pass, total);
        }

        double totalAvg = 0;
        while (!pq.empty()) {
            auto [_, pass, total] = pq.top(); pq.pop();
            totalAvg += pass / total;
        }

        return totalAvg / classes.size();
    }
};
