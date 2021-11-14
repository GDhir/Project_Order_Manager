#include "Utils.hpp"

bool isInteger(const std::string& str)
{
  for (char const &c : str) {
      if (std::isdigit(c) == 0) return false;
  }
  return true;
}

bool isFloat(const std::string& str) {

  bool dotPresent{false};

  if( !isdigit( str[0] ) )
    return false;

  for( int i = 1; i < str.size(); i++ ) {

    if( str[i] == '.' && !dotPresent ) {
      dotPresent = true;
    }
    else if( !isdigit( str[i] ) )
      return false;

  }

  return true;

}

void removeLeadingSpace( std::string& str) {

  int i{0};
  while( str[i] == ' ' ) {

    i++;

  }

  str = str.substr(i);

}

bool LessCompare::operator()( const OrderDetails& left, const OrderDetails& right ) {

    if( left.orderValue == right.orderValue ) {

    return left.orderID > right.orderID;

    }
    else {

    return left.orderValue < right.orderValue;

    }

}


bool GreaterCompare::operator()( const OrderDetails& left, const OrderDetails& right ) {

if( left.orderValue == right.orderValue ) {

    return left.orderID > right.orderID;

}
else {

    return left.orderValue > right.orderValue;

}

}