#ifndef Operator_h
#define Operator_h
#include <map>
#include <string>
#include <vector>
#include "Operand.h"

class Expression;

/**
 *  Implementation of operators constructed in the class Expression.
 *  Supports the function Evaluate() which updates the value of
 *  the left operand given the current operator and the operand
 *  on righthand side.
 */
class Operator {
   public:
    Operator(std::string left,
             std::string right,
             std::map<std::string, std::vector<Expression*>>* oper_map,
             std::map<std::string, double>* reg_vals);
    virtual ~Operator();

    virtual double evaluate(const std::string& curr_reg) = 0;

   protected:
    Register* left_operand{};
    Operand* right_operand{};
    std::map<std::string, double>* reg_vals{};
};

/**
 *  Derived class that inherits from Operator
 */
class Addition : public Operator {
   public:
    Addition(std::string left,
             std::string right,
             std::map<std::string, std::vector<Expression*>>* oper_map,
             std::map<std::string, double>* reg_vals);

    double evaluate(const std::string& curr_reg);

   protected:
};

/**
 *  Derived class that inherits from Operator
 */
class Subtraction : public Operator {
   public:
    Subtraction(std::string left,
                std::string right,
                std::map<std::string, std::vector<Expression*>>* oper_map,
                std::map<std::string, double>* reg_vals);

    double evaluate(const std::string& curr_reg);

   protected:
};

/**
 *  Derived class that inherits from Operator
 */
class Multiplication : public Operator {
   public:
    Multiplication(std::string left,
                   std::string right,
                   std::map<std::string, std::vector<Expression*>>* oper_map,
                   std::map<std::string, double>* reg_vals);

    double evaluate(const std::string& curr_reg);

   protected:
};
#endif
