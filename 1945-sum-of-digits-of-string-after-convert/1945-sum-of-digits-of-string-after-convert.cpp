class Solution {
public:
int sumOfDigits(string num) {
    int sum = 0;
    for (char digit : num) {
        sum += digit - '0';
    }
    return sum;
}

int getLucky(string s, int k) {
    string converted = "";

   
    for (char c : s) {
        int val = c - 'a' + 1;
        converted += to_string(val);
    }

   
    for (int i = 0; i < k; ++i) {
        int sum = sumOfDigits(converted);
        converted = to_string(sum);
    }

    return stoi(converted);
    }
};