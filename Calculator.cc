#include <bits/stdc++.h>
#include "Expression.h"

using namespace std;

/**
 *  Function to convert strings to lowercase
 */
std::string toLower(std::string s) {
    int length = s.length();
    for (int i = 0; i < length; i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

int main(int argc, char** argv) {
    bool read_file = false;

    // Check if we've a textfile as an argument
    if (argc == 2) {
        if (!freopen(argv[1], "r", stdin)) {
            cout << "Failed to open file" << endl;
            return -1;
        }
        read_file = true;
    } else if (argc > 2) {
        cout << "Too many input arguments" << endl;
        return -1;
    }

    // Map that stores vectors where the vector on key "x"
    // stores all the expressions that change the value of register "x"
    map<string, vector<Expression*>>* operations_map =
        new map<string, vector<Expression*>>{};

    // Map that keeps track of all the current values of registers
    map<string, double>* reg_vals = new map<string, double>{};

    string input;
    if (read_file) {
        cout << "Reading from file..." << endl;
    } else {
        cout << "Valid inputs include: \n"
             << "<register> <operation> <value> \n"
             << "print <register> \n"
             << "quit \n"
             << "Register must consist of only alphanumeric characters. \n"
             << "Implemented operations include: add, subtract and "
                "multiply. \n"
             << "Value must be an integer, float or another register. \n"
             << endl;
        cout << "Enter expressions: " << endl;
    }

    // Read one line at a time from command line or alternatively from text
    // file
    while (getline(cin, input)) {
        // Case insensitive
        input = toLower(input);

        if (input == "quit") {
            cout << "Exiting" << endl;
            break;
        }
        istringstream ss(input);
        string reg, operand, value;

        try {
            ss >> reg;
            if (reg == "print") {
                ss >> value;
                // Check if the register "value" consists of only alphanumeric
                // characters
                if (!(all_of(value.begin(), value.end(), ::isalnum) &&
                      (value.length() > 0))) {
                    throw "That's not a valid name for a register";
                }
                /** Check if there exists expressions that alter the value of
                 * register "value", if there is, calculate them otherwise
                 * output the value previously saved. */
                if (operations_map->count(value) > 0) {
                    for (Expression* e : operations_map->at(value)) {
                        e->evaluate(value);
                        delete e;
                    }
                    operations_map->erase(value);
                    cout << reg_vals->at(value) << endl;
                } else if (reg_vals->count(value) > 0) {
                    cout << reg_vals->at(value) << endl;
                } else {
                    cout << 0 << endl;
                }
                continue;
            }

            ss >> operand >> value;
            Expression* exp =
                new Expression{reg, operand, value, operations_map, reg_vals};

            /** Check if the register "register" already exists as a key in
             * in "operations_map", if it does push the current expression to
             * that vector. Otherwise make a new vector with the current
             * expression and add that to the map. */
            if (operations_map->find(reg) == operations_map->end()) {
                vector<Expression*> expressions{exp};
                operations_map->insert(make_pair(reg, expressions));
                reg_vals->insert(make_pair(reg, 0));
            } else {
                (operations_map->at(reg)).push_back(exp);
            }
        } catch (const char* message) {
            cout << message << endl;
        }
    }
    if (read_file) {
        fclose(stdin);
        cout << "Exiting" << endl;
    }

    // Delete all the pointers
    for (const auto& vec : *operations_map) {
        for (auto& exp : vec.second) {
            delete exp;
        }
    }
    reg_vals->clear();
    delete reg_vals;
    delete operations_map;

    return 0;
}
