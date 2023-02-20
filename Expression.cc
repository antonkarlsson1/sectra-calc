#include "Expression.h"
#include "Operator.h"

using namespace std;

Expression::Expression(string left,
                       string operand,
                       string right,
                       map<string, vector<Expression*>>* oper_map,
                       map<string, double>* reg_vals) {
    if (operand == "add") {
        oper = new Addition(left, right, oper_map, reg_vals);
    } else if (operand == "subtract") {
        oper = new Subtraction(left, right, oper_map, reg_vals);
    } else if (operand == "multiply") {
        oper = new Multiplication(left, right, oper_map, reg_vals);
    } else {
        throw "Invalid input";
    }
}

Expression::~Expression() {
    delete oper;
}

double Expression::evaluate(const string& curr_reg) {
    return oper->evaluate(curr_reg);
}
