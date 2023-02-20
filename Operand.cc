#include "Operand.h"

using namespace std;

Integer::Integer(int value) : value{value} {}

Double::Double(double value) : value{value} {}

Register::Register(string name,
                   map<string, vector<Expression*>>* oper_map,
                   map<string, double>* reg_vals)
    : name{name}, oper_map{oper_map}, reg_vals{reg_vals} {}

double Integer::evaluate(const string& curr_reg) {
    return value;
}

double Double::evaluate(const string& curr_reg) {
    return value;
}

/**
 *  Evaluates the active expressions saved in the
 *  map "operations_map" (oper_map) for the given register.
 *  Then returns the updated value of the current register.
 */
double Register::evaluate(const string& curr_reg) {
    /** Check if we have a sequence of expressions as:
     * A add B
     * B add A
     * print A
     */
    if (curr_reg == name) {
        throw "This is not a valid sequence of expressions";
    }

    if (oper_map->count(name) > 0) {
        for (Expression* e : oper_map->at(name)) {
            e->evaluate(curr_reg);
            delete e;
        }
        oper_map->erase(name);
        return reg_vals->at(name);
    } else if (reg_vals->count(name) > 0) {
        return reg_vals->at(name);
    } else {
        return 0;
    }
}

string Register::getname() {
    return name;
}

string Double::getname() {
    return "double";
}

string Integer::getname() {
    return "integer";
}
