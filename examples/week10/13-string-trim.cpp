#include <algorithm> 
#include <cctype>
#include <functional> 
#include <iostream> 
#include <locale>

using std::cout;
using std::string;

/**
 * Trim whitespace from the start (left side) of a string.
 * @param s the string to trim
 * @return a copy of the source string with all the whitespace from 
 * position 0 to the first non-whitespace character removed.
 */
static inline string ltrim(const string& s) {
    auto temp = s;
    temp.erase(temp.begin(), 
               std::find_if(temp.begin(), temp.end(), [](char c){
                   return !std::isspace(c, std::locale()); 
               })
    );
    return temp;
}

/**
 * Trim whitespace from the end (right side) of a string.
 * @param s the string to trim
 * @return a copy of the source string with all the whitespace 
 * starting from the end position int the string to the 
 * first non-whitespace character removed.
 */
static inline string rtrim(const string& s) {
    auto temp = s;
    temp.erase(std::find_if(temp.rbegin(), temp.rend(),
                [](char c){return !std::isspace(c, std::locale()); }).base(), temp.end());
    return temp;
}

/**
 * Trim whitespace from both ends of a string.
 * @param s the string to trim
 * @return a copy of the source string with all the 
 * surrounding whitespace removed 
 */
static inline string trim(const string& s) {
    return ltrim(rtrim(s));
}

int main() {
    // initialize and randomize
    string test = "       the rain in spain falls mainly on the plain.       ";
    constexpr char quote = '\'';
    const char* newl = "'\n";
    cout << "original:  " << quote << test << newl;
    cout << "left:      " << quote << ltrim(test) << newl;
    cout << "right:     " << quote << rtrim(test) << newl;
    cout << "both:      " << quote <<  trim(test) << newl;

}



