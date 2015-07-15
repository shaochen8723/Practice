#include "io.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
  string monPay = "Please enter the monthly payment: ";
  string intRate = "Please enter the interest rate: ";
  string yearLoan = "Please enter the duration of the loan, in years: ";
  bool done = false;
  
  // get parameters
  double p = GetParam(monPay, 1, 100000);
  double r = GetParam(intRate, 0, 1);
  double y, intpart, interest, balance=0.0, principal;
  do {
    y = GetParam(yearLoan, 1, 100);
    if (modf(y, &intpart) == 0.0) {
      done = true;
    }
  } while (!done);
  int m = y*12;
  
  PrintHeader();
  do {
    
    balance = (balance+p)/(1+r/12);
    interest = balance*r/12;
    principal = p - interest;
    PrintMonthlyData(m, principal, interest, balance);
    m--;
  } while (m > 0);
  
  return 0;
}
