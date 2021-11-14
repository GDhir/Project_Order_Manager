#include "CancelOrderExecuter.hpp"

    results_t CancelOrderExecuter::executeActions( BuyMultiset& buySet, SellMultiset& sellSet, BuyMap& buyMap, SellMap& sellMap, OrderDetails& orderDetails ) {

      if( buyMap.find( orderDetails.orderID ) == buyMap.end() && sellMap.find( orderDetails.orderID ) == sellMap.end() ) {

        throw InvalidInputException( "InvalidIDForCancel", orderDetails.orderID );

      }
      else if( buyMap.find( orderDetails.orderID ) != buyMap.end() ) {

        auto itr = buyMap[ orderDetails.orderID ];
        buySet.erase( itr );
        buyMap.erase( orderDetails.orderID );

      }
      else {

        auto itr = sellMap[ orderDetails.orderID ];
        sellSet.erase( itr );
        sellMap.erase( orderDetails.orderID );

      }

      results_t output;
      output.push_back( "X " + std::to_string( orderDetails.orderID ) + "\n" );
      return output;
    
  };