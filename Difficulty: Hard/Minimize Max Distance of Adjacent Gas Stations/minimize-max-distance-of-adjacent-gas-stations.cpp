class Solution {
public:
    bool check(vector<int>& stations, int k, double dist) {
        int required = 0;

        for (int i = 1; i < stations.size(); i++) {
            double gap = stations[i] - stations[i - 1];
            required += ceil(gap / dist) - 1;
//-1 because no of stations= number of segments-1
            if (required > k)
                return false;
        }

        return true;
    }

    double minMaxDist(vector<int> &stations, int k) {

        double low = 0;
        double high = 0;

        for (int i = 1; i < stations.size(); i++)
            high = max(high, (double)(stations[i] - stations[i - 1]));

        while (high - low > 1e-6) {

            double mid = (low + high) / 2;

            if (check(stations, k, mid))
                high = mid;
            else
                low = mid;
        }

        return high;
    }
};