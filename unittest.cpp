#include <iostream>
#include <cassert>

std::string ConcatRemove(const std::string& s, const std::string& t, int k) {
    int sLength = s.length();
    int tLength = t.length();

    // Calculate the length of the common prefix between s and t
    int commonPrefix = 0;
    while (commonPrefix < sLength && commonPrefix < tLength && s[commonPrefix] == t[commonPrefix]) {
        ++commonPrefix;
    }

    // Calculate the number of operations required
    int minOperations = (sLength - commonPrefix) + (tLength - commonPrefix);

    // Check if it's possible to achieve t within k operations
    if (k >= minOperations) {
        return "yes";
    } else {
        return "no";
    }
}

void testConcatRemove() {
    // Test case 1
    std::string s1 = "abc";
    std::string t1 = "ab";
    int k1 = 1;
    std::string result1 = ConcatRemove(s1, t1, k1);
    assert(result1 == "yes");

    // Test case 2
    std::string s2 = "ab";
    std::string t2 = "abcd";
    int k2 = 1;
    std::string result2 = ConcatRemove(s2, t2, k2);
    assert(result2 == "no");

    // Test case 3
    std::string s3 = "a";
    std::string t3 = "abcdefghi";
    int k3 = 3;
    std::string result3 = ConcatRemove(s3, t3, k3);
    assert(result3 == "no");
    
    // Test case 4
    std::string s4 = "a";
    std::string t4 = "abcdefghi";
    int k4 = 50;
    std::string result4 = ConcatRemove(s4, t4, k4);
    assert(result4 == "yes");

    // Test case 5: minimum input constraints
    std::string s5 = "a";
    std::string t5 = "b";
    int k5 = 1;
    std::string result5 = ConcatRemove(s5, t5, k5);
    assert(result5 == "no");

    // Test case 6: Maximum input constraints
    std::string s6 = std::string(100, 'a');
    std::string t6 = std::string(100, 'b');
    int k6 = 100;
    std::string result6 = ConcatRemove(s6, t6, k6);
    assert(result6 == "no");
}

int main() {
    testConcatRemove();

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}

