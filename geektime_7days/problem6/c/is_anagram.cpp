#include <iostream>
#include <map>

class Solution {
public:
    Solution() {}
    ~Solution() {}
    bool isAnagram(std::string s, std::string t) {
        int slen = s.length();
        int tlen = t.length();
        if ( slen != tlen ){
            return false;
        }

        std::map<char, int> smap;
        std::map<char, int> tmap;

        for ( auto sit = s.begin(); sit != s.end(); ++sit ){
            auto it = smap.find(*sit);
            if ( it != smap.end() ) {
                it->second++;
            } else {
                smap.insert({*sit, 1});
            }
        }

        for ( auto tit = t.begin(); tit != t.end(); ++tit ){
            auto it = tmap.find(*tit);
            if ( it != tmap.end() ) {
                it->second++;
            } else {
                tmap.insert({*tit, 1});
            }
        }

        for ( auto sit = smap.begin(); sit != smap.end(); ++sit ) {
            auto it = tmap.find( sit->first );
            if( it == tmap.end() ) {
                return false;
            }

            if ( it->second != sit->second ) {
                return false;
            }
        }

        return true;
    }
};

int main(){
    
    std::string s = "anagram";
    std::string t = "nagrama";

    Solution solution;
    std::cout << solution.isAnagram(s, t)<< std::endl;
    return 0;    
}
