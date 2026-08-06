class Solution {
public:
    int smallestNumber(int n, int t) {
       
        for(int i=0;i<10;i++){
            int product=1;
            int k=0;
            int m=n;
            while(m>0){
                k=m%10;
                product=k*product;
                m=m/10;
            }
           if((product%t)!=0){
                n++;
           }
           else{
            return n;
           }
        }
        return 0;
    }
};