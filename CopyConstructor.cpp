/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cassert>
class Fraction
{
  int m_numerator{};
  int m_denominator{};

public:

  //Default constructor
  explicit Fraction (int numerator = 0, int denominator = 1):
  m_numerator{numerator},
  m_denominator{denominator}
  {
    std::cout << "Default constructor " << std::endl;
    assert (denominator != 0 && "Denominator cannot be zero");
  }

  //Copy constructor
  Fraction (const Fraction & fraction):
  m_numerator{fraction.m_numerator}, 
  m_denominator{fraction.m_denominator}
  {
    //here not needed to check the denominator for 0, since the fraction must already be a valid Fraction object
    std::cout << "Copy constructor " << std::endl;

  }


  friend std::ostream & operator<< (std::ostream & out, const Fraction & f1)
  {
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
  }


  void setNumerator (int value)
  {
    m_numerator = value;
  }

  int getNumerator () const
  {
    return m_numerator;
  }

  int getDenominator () const
  {
    return m_denominator;
  }

};

/*Fraction makeNegative(const Fraction& f)
      {
          return Fraction{-f.getNumerator(),-f.getDenominator()};
      }*/

Fraction makeNegative (Fraction f)
{
  f.setNumerator (-f.getNumerator ());	// This case 2 copy constructors called one for the object parameter, other for the return value 
  return f;
}

void printFraction (const Fraction & f)
{
  std::cout << f;
}

int
main ()
{
  Fraction fiveThirds{5, 3};// Direct initialize a Fraction, calls Fraction(int, int) constructor
  Fraction fCopy1{fiveThirds};			// Direct initialize -- with Fraction copy constructor// Copy Constructor is called
  Fraction fCopy2{Fraction{5, 4}};	//The process of omitting certain copy (or move) steps for performance purposes is called elision
  
  std::cout << makeNegative (fiveThirds) << std::endl;	// Try out the commented makeNegative and see how the compiler elides the copy constructor

  //Although function printFraction() is expecting a Fraction, we’ve given it the integer literal 6 instead. 
  //Because Fraction has a constructor willing to take a single integer, the compiler will implicitly convert the literal 6 into a Fraction object.
  //It does this by initializing printFraction() parameter f using the Fraction(int, int) constructor.
  // such implicit conversion can result in unexpected behaviour therefore we can make the constructors explicit therefore they are not used for implicit conversions
  //One way to address this issue is to make constructors (and conversion functions) explicit via the explicit keyword, 
  //which is placed in front of the function’s name. Constructors and conversion functions made explicit will not be used for implicit conversions or copy initialization:
  printFraction (6); // if I put explicit keyword in  front of the Constructor and try this command, results in error
  
  // there is an option to delete the functions, see learncpp.com chapter 13.14
}
