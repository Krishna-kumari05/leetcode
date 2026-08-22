class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int m=n;
        while(m>0){
            int lastdigit=m%10;
            sum+=lastdigit;
            product*=lastdigit;
            m=m/10;
        }

        sum+=product;
        if(n%sum==0){
            return true;
        }
        return false;
    }
};