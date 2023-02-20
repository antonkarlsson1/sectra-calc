#ifndef Expression_h
#define Expression_h
#include <map>
#include <string>
#include <vector>

class Operator;

/**
 *  Implementation of an input expression on the form
 *  <register> <operation> <value>
 *  Supports the function Evaluate() which calculates
 *  the expression represented by the class.
 */
class Expression {
   public:
    Expression(std::string left,
               std::string operand,
               std::string right,
               std::map<std::string, std::vector<Expression*>>* oper_map,
               std::map<std::string, double>* reg_vals);
    Expression(){};
    ~Expression();

    double evaluate(const std::string& curr_reg);

   private:
    Operator* oper{};
};
#endif
