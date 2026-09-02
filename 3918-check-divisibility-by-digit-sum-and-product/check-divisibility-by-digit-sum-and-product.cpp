class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        long long int product = 1;
        int a = n;

        while(n > 0){
            sum = sum + (n % 10);
            product = product * (n % 10);
            n = n / 10;
        }

        return (a % (sum + product) == 0);

    }
};