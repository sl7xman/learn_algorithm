#include <iostream>

bool isAnagram(std::string s, std::string t) {
    auto sit2 = t.begin();
    std::string stmp = s + *sit2;
    stmp = stmp.substr(1,stmp.size()-1);

    std::cout<<stmp<< std::endl;
    if ( stmp == t) {
        return true;
    }else{
        return false;
    }
}

int main(){
    
    std::string s = "anagram";
    std::string t = "nagrama";
    std::cout << isAnagram(s, t) << std::endl;
    return 0;    
}
