#include "PrintOrderParser.hpp"

  void PrintOrderParser::parseDetails( const std::vector<std::string>& actionVal, OrderDetails& details ) {

    if( actionVal.size() != 1 ) {

      throw InvalidInputException( "InvalidPrintAction" );

    }

  }