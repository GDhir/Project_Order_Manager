#include "OrderScanner.hpp"

  void OrderScanner::scanAndTokenizeOrder( std::string& orderStr, std::vector<std::string>& orderTokens ) {

    if( orderStr.size() == 0 ) {
      
      throw InvalidInputException( "InvalidOrderString" );

    }
    else {

      removeLeadingSpace( orderStr );
      auto spacePos = orderStr.find( " " );

      int i{0};

      while( spacePos != std::string::npos ) {

        auto token = orderStr.substr( 0, spacePos );
        orderTokens.push_back( token );

        i = spacePos + 1;
        orderStr = orderStr.substr( i );
        removeLeadingSpace( orderStr );

        spacePos = orderStr.find( " " );

      }

      orderTokens.push_back( orderStr );

    }

  }