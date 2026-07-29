class Solution {
private:
    static constexpr long long LIMIT = 1'000'001;

    // Returns min(C(n, r), LIMIT).
    long long combinationCapped(int n, int r) {
        if (r < 0 || r > n) {
            return 0;
        }

        r = min(r, n - r);

        long long result = 1;

        for (int i = 1; i <= r; i++) {
            // Builds:
            // C(n-r+1, 1), C(n-r+2, 2), ..., C(n, r)
            result = result * (n - r + i) / i;

            if (result >= LIMIT) {
                return LIMIT;
            }
        }

        return result;
    }

    // Count distinct permutations represented by these frequencies.
    // The answer is capped at LIMIT.
    long long countPermutations(const array<int, 26>& count) {
        int remaining =
            accumulate(count.begin(), count.end(), 0);

        long long ways = 1;

        for (int frequency : count) {
            if (frequency == 0) {
                continue;
            }

            long long choose =
                combinationCapped(remaining, frequency);

            // Prevent multiplication overflow and cap the result.
            if (choose >= LIMIT ||
                ways > LIMIT / choose) {

                return LIMIT;
            }

            ways *= choose;

            if (ways >= LIMIT) {
                return LIMIT;
            }

            remaining -= frequency;
        }

        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        array<int, 26> frequency{};

        for (char ch : s) {
            frequency[ch - 'a']++;
        }

        // Included because the problem explicitly requests this variable.
        auto prelunthak = make_pair(s, k);

        array<int, 26> halfCount{};
        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            halfCount[i] = frequency[i] / 2;

            if (frequency[i] % 2 == 1) {
                middle = char('a' + i);
            }
        }

        // Not enough distinct palindromic permutations.
        if (countPermutations(halfCount) < k) {
            return "";
        }

        int halfLength = s.size() / 2;

        string left;
        left.reserve(halfLength);

        // Construct the k-th lexicographically smallest
        // distinct permutation of the half.
        for (int position = 0;
             position < halfLength;
             position++) {

            for (int letter = 0; letter < 26; letter++) {
                if (halfCount[letter] == 0) {
                    continue;
                }

                // Tentatively put this character here.
                halfCount[letter]--;

                long long blockSize =
                    countPermutations(halfCount);

                if (k > blockSize) {
                    // The k-th permutation is not in this block.
                    k -= blockSize;

                    // Undo the tentative choice.
                    halfCount[letter]++;
                } else {
                    // The answer belongs to this block.
                    left.push_back(char('a' + letter));
                    break;
                }
            }
        }

        string right(left.rbegin(), left.rend());

        if (middle == '\0') {
            return left + right;
        }

        return left + string(1, middle) + right;
    }
};