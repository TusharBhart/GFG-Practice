class Solution{
public:
    int inSequence(int a, int b, int c){
        if(a == b) return 1;
        if(!c) return a == b;
        if(abs(b - (a + c)) > abs(b - a)) return 0;
        double d = (double) (b - a) / c;
        int i = (b - a) / c;
        return d - i == 0;
    }
    /*
    a + (n * c) = b
    n * c = b - a
    n = (b - a) / c
    */
};