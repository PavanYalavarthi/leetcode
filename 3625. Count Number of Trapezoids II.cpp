/*
Problem credits: https://leetcode.com/problems/count-number-of-trapezoids-ii/description/

You are given a 2D integer array points where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

Return the number of unique trapezoids that can be formed by choosing any four distinct points from points.

A trapezoid is a convex quadrilateral with at least one pair of parallel sides. Two lines are parallel if and only if they have the same slope.

Solution:
    As we needed to pick parallel sides but differ by intercept, we hold a map with count per slope per intercept

    As in case of parallelogram, we count them twice due to 2 parallel sides,

    Subtracting parallelograms, parallelograms dialognals biset at the same point, So counting freq /midpoint per slope
*/
class Solution {
    struct Slope {
        int dy, dx;
        bool operator==(const Slope& other) const {
            return dy == other.dy && dx == other.dx;
        }
    };

    struct HashSlope {
        size_t operator()(const Slope& s) const {
            return (static_cast<uint64_t>(s.dy) << 32) ^ (uint32_t)s.dx;
        }
    };

    // slope -> intercept -> count of segments
    unordered_map<Slope, unordered_map<long long, int>, HashSlope> lineMap;

    // midpoint -> slope -> count of diagonals
    unordered_map<long long, unordered_map<Slope, int, HashSlope>> midPointCnt;

    // It counts parallelogram twice. So subtracting it
    long long countTrapezoidsRaw() {
        long long ans = 0;
        for (auto &[_slope, interceptMap] : lineMap) {
            long long total = 0, sameLine = 0;
            for (auto &[_, f] : interceptMap) {
                sameLine += 1LL * f * (f - 1) / 2;
                total += f;
            }
            ans += total * (total - 1) / 2 - sameLine;
        }
        return ans;
    }

    long long countParallelograms() {
        long long ans = 0;
        for (auto &[_, slopeMap] : midPointCnt) {
            long long total = 0, sameSlope = 0;
            for (auto &[__, f] : slopeMap) {
                sameSlope += 1LL * f * (f - 1) / 2;
                total += f;
            }
            // removes degenerate (collinear) parallelograms
            ans += total * (total - 1) / 2 - sameSlope;
        }
        return ans;
    }

public:
    int countTrapezoids(vector<vector<int>>& points) {
        lineMap.clear();
        midPointCnt.clear();

        int n = points.size();
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];

                // -------- slope normalization (exact) --------
                int dy = y2 - y1;
                int dx = x2 - x1;

                if (dx == 0) {
                    dy = 1; dx = 0;
                } else if (dy == 0) {
                    dy = 0; dx = 1;
                } else {
                    int g = gcd(abs(dy), abs(dx));
                    dy /= g;
                    dx /= g;
                    if (dx < 0) dy = -dy, dx = -dx;
                }

                Slope slope{dy, dx};

                // line constant: dx*y - dy*x
                long long intercept = 1LL * dx * y1 - 1LL * dy * x1;
                lineMap[slope][intercept]++;

                // -------- midpoint (safe integer key) --------
                long long mx = x1 + x2;
                long long my = y1 + y2;

                // making keys positive
                long long key = (mx + 2000) * 10000 + (my + 2000);
                midPointCnt[key][slope]++;
            }
        }

        long long trapezoids = countTrapezoidsRaw();
        long long parallelograms = countParallelograms();

        // parallelograms were counted twice -> subtract once
        return (int)(trapezoids - parallelograms);
    }
};