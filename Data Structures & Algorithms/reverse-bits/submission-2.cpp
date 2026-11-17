class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::string s = std::format("{:b}", n); 
        int len = s.length();

        uint32_t res = 0; //= n << (32-len);
        for(int i = 0; i < 32; i++) {
            //if(i >= len) break;
            if((n >> i) & 1) {
                res |= (1 << (31 - i));
            }
        }

        cout << "n=" << std::format("{:b}", res) << "\n"; 
        return res;


    }
};
