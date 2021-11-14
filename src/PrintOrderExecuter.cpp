#include "PrintOrderExecuter.hpp"

  std::string PrintOrderExecuter::createOutput( const OrderDetails& details ) {

    std::string output;

    output = "P " + std::to_string( details.orderID ) + " " + details.symbol + " " + std::string(1, details.orderType) + " " +
              std::to_string( details.orderQty ) + " " + std::to_string( details.orderValue ) + "\n";

    return output;

  }

  results_t PrintOrderExecuter::executeActions( BuyMultiset& buySet, SellMultiset& sellSet, BuyMap& buyMap, SellMap& sellMap, OrderDetails& orderDetails ) {

    results_t outputs;

    for( auto& sellItem: sellSet ) {

      auto output = createOutput( sellItem );
      outputs.push_back( output );

    }

    for( auto itr = buySet.rbegin(); itr != buySet.rend(); itr++ ) {

      auto output = createOutput( *itr );
      outputs.push_back( output );

    }

    return outputs;

  }