
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size();
        int n = num2.size();

        vector<int> res(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int product = a * b;
                int sum = product + res[i + j + 1];

                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        string ans;
        for (int digit : res) {
            if (!(ans.empty() && digit == 0)) {
                ans += to_string(digit);
            }
        }

        return ans;
    }
};
