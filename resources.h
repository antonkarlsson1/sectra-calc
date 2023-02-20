#ifndef resources_h
#define resources_h
#include <bits/stdc++.h>

/** Checks if the string "str" is a valid integer
 */
bool is_Integer(const std::string& str) {
    return all_of(str.begin(), str.end(), ::isdigit) && (str.length() > 0);
}

/** Checks if the string "str" consists of only alphanumeric characters
 */
bool is_Alphanum(const std::string& str) {
    return all_of(str.begin(), str.end(), ::isalnum) && (str.length() > 0);
}

/** Checks if the string "str" is a valid double
 */
bool is_Double(const std::string& str) {
    char* end = nullptr;
    double val = strtod(str.c_str(), &end);
    return end != str.c_str() && *end == '\0' && val != HUGE_VAL;
}
#endif