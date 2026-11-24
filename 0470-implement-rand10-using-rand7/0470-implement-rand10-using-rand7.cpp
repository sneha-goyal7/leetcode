// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
         while (true) {
            int num = (rand7() - 1) * 7 + rand7(); // uniform in 1..49
            if (num <= 40) return (num - 1) % 10 + 1;

            // reuse the rejected values 41..49 (uniform in 1..9)
            int a = num - 40;
            num = (a - 1) * 7 + rand7(); // uniform in 1..63
            if (num <= 60) return (num - 1) % 10 + 1;

            // reuse rejected values 61..63 (uniform in 1..3)
            a = num - 60;
            num = (a - 1) * 7 + rand7(); // uniform in 1..21
            if (num <= 20) return (num - 1) % 10 + 1;
        }
    }
};