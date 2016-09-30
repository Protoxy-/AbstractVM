//
// IOperand.hh for IOperand in /home/dayrie_l/rendu/cpp_abstractvm
// 
// Made by Lucas Dayries
// Login   <dayrie_l@epitech.net>
// 
// Started on  Thu Feb 12 11:21:05 2015 Lucas Dayries
// Last update Fri Feb 20 14:33:32 2015 Lucas Dayries
//

#ifndef IOPERAND_HH_
# define IOPERAND_HH_

#include <iostream>

enum eOperandType
  {
    Int8,
    Int16,
    Int32,
    Float,
    Double
  };

class IOperand
{
public:

  virtual std::string const &toString() const = 0; // Renvoie une string representant l'instance

  virtual int getPrecision() const = 0; // Renvoie la precision du type de l'instance
  virtual eOperandType getType() const = 0; // Renvoie le type de t'instance. Voir plus bas

  virtual IOperand *operator+(const IOperand &rhs) const = 0; // Somme
  virtual IOperand *operator-(const IOperand &rhs) const = 0; // Difference
  virtual IOperand *operator*(const IOperand &rhs) const = 0; // Produit
  virtual IOperand *operator/(const IOperand &rhs) const = 0; // Quotient
  virtual IOperand *operator%(const IOperand &rhs) const = 0; // Modulo

  virtual ~IOperand() {}
};

#endif /* !IOPERAND_HH_ */
