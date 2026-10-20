class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for(int i = 0; i<n; i++){
            int dig = digits[i]+carry;
            digits[i] = dig%10;
            carry = dig/10;
        }
        if(carry!=0){
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
