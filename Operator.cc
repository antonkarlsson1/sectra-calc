#include "Operator.h"
#include "resources.h"

using namespace std;

Operator::Operator(string left,
                   string right,
                   map<string, vector<Expression*>>* oper_map,
                   map<string, double>* reg_vals)
    : reg_vals{reg_vals} {
    try {
        // Check if left operand contains only alphanumeric characters
        if (is_Alphanum(left)) {
            // Check if the right operand only contains digits
            if (is_Integer(right)) {
                right_operand = new Integer(stoi(right));
            } else if (is_Double(right)) {
                right_operand = new Double(stod(right));
            }
            // Check if the right contains only alphanumeric characters
            else if (is_Alphanum(right)) {
                right_operand = new Register(right, oper_map, reg_vals);
            } else {
                throw "That's not a valid name for a register";
            }
            left_operand = new Register(left, oper_map, reg_vals);
        } else {
            throw "Registers need to consist of only alphanumeric characters";
        }
    } catch (out_of_range& e) {
        cout << "That's to big of a number" << endl;
    }
}

Addition::Addition(string left,
                   string right,
                   map<string, vector<Expression*>>* oper_map,
                   map<string, double>* reg_vals)
    : Operator(left, right, oper_map, reg_vals) {}

Subtraction::Subtraction(string left,
                         string right,
                         map<string, vector<Expression*>>* oper_map,
                         map<string, double>* reg_vals)
    : Operator(left, right, oper_map, reg_vals) {}

Multiplication::Multiplication(string left,
                               string right,
                               map<string, vector<Expression*>>* oper_map,
                               map<string, double>* reg_vals)
    : Operator(left, right, oper_map, reg_vals) {}

Operator::~Operator() {
    delete left_operand;
    delete right_operand;
}

/**
 *  Updates the register on the righthand side given
 *  the current operator and righthand side operand.
 */
double Addition::evaluate(const string& curr_reg) {
    string left_op = left_operand->getname();
    string right_op = right_operand->getname();

    // Check if the left and right operands are the same
    if (left_op == right_op) {
        reg_vals->at(left_op) += reg_vals->at(right_op);
    } else {
        reg_vals->at(left_op) += right_operand->evaluate(curr_reg);
    }

    return reg_vals->at(left_op);
}

/**
 *  Updates the register on the righthand side given
 *  the current operator and righthand side operand.
 */
double Subtraction::evaluate(const string& curr_reg) {
    string left_op = left_operand->getname();
    string right_op = right_operand->getname();

    // Check if the left and right operands are the same
    if (left_op == right_op) {
        reg_vals->at(left_op) -= reg_vals->at(right_op);
    } else {
        reg_vals->at(left_op) -= right_operand->evaluate(curr_reg);
    }

    return reg_vals->at(left_op);
}

/**
 *  Updates the register on the righthand side given
 *  the current operator and righthand side operand.
 */
double Multiplication::evaluate(const string& curr_reg) {
    string left_op = left_operand->getname();
    string right_op = right_operand->getname();

    // Check if the left and right operands are the same
    if (left_op == right_op) {
        reg_vals->at(left_op) *= reg_vals->at(right_op);
    } else {
        reg_vals->at(left_op) *= right_operand->evaluate(curr_reg);
    }

    return reg_vals->at(left_op);
}
