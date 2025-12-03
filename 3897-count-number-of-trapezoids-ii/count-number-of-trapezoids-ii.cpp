

class Solution {
public:
    long long countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0;

        map<pair<int, int>, map<long long, int>> slope_map;
        map<pair<int, int>, map<pair<int, int>, int>> mid_map;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int g = std::gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0 && dy < 0) {
                    dy = -dy;
                }

                pair<int, int> slope = {dy, dx};
                long long intercept = (long long)dx * points[i][1] - (long long)dy * points[i][0];
                
                slope_map[slope][intercept]++;

                pair<int, int> mid_pt = {points[i][0] + points[j][0], points[i][1] + points[j][1]};
                mid_map[mid_pt][slope]++;
            }
        }

        long long total_trapezoids = 0;

        for (auto const& [slope, lines] : slope_map) {
            long long total_segments = 0;
            long long same_line_pairs = 0;

            for (auto const& [intercept, count] : lines) {
                total_segments += count;
                same_line_pairs += (long long)count * (count - 1) / 2;
            }

            long long all_pairs = total_segments * (total_segments - 1) / 2;
            total_trapezoids += (all_pairs - same_line_pairs);
        }

        long long parallelograms = 0;
        for (auto const& [mid, slopes] : mid_map) {
            long long total_pairs = 0;
            long long same_slope_pairs = 0;

            for (auto const& [slope, count] : slopes) {
                total_pairs += count;
                same_slope_pairs += (long long)count * (count - 1) / 2;
            }

            long long valid_parallelograms = total_pairs * (total_pairs - 1) / 2;
            parallelograms += (valid_parallelograms - same_slope_pairs);
        }

        return total_trapezoids - parallelograms;
    }
};