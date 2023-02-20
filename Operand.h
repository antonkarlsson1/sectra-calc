#ifndef Operand_h
#define Operand_h
#include <map>
#include <string>
#include <vector>
#include "Expression.h"

/**
 *  Implementation of operands constructed in the class Operator.
 *  Supports the function Evaluate() which returns the value of
 *  the given operand.
 *
 */
class Operand {
   public:
    Operand(){};
    virtual ~Operand(){};

    virtual double evaluate(const std::string& curr_reg) = 0;
    virtual std::string getname() = 0;
};

/**
 *  Derived class that inherits from Operand
 */
class Integer : public Operand {
   public:
    Integer(int value);

    double evaluate(const std::string& curr_reg);
    std::string getname() override;

   private:
    int value;
};

/**
 *  Derived class that inherits from Operand
 */
class Double : public Operand {
   public:
    Double(double value);

    double evaluate(const std::string& curr_reg);
    std::string getname() override;

   private:
    double value;
};

/**
 *  Derived class that inherits from Operand
 */
class Register : public Operand {
   public:
    Register(std::string name,
             std::map<std::string, std::vector<Expression*>>* oper_map,
             std::map<std::string, double>* reg_vals);

    double evaluate(const std::string& curr_reg);
    std::string getname() override;

   private:
    std::string name;
    std::map<std::string, std::vector<Expression*>>* oper_map;
    std::map<std::string, double>* reg_vals;
};
#endif
