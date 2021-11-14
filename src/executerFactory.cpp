#include "executerFactory.hpp"

std::unique_ptr<OrderExecuterBase> executerFactory( char type ) {

  if( type == 'X' ){
    return std::make_unique<CancelOrderExecuter>();
  }
  else if( type == 'O' ){
    return std::make_unique<PlaceOrderExecuter>();
  }
  else if( type == 'P' ){
    return std::make_unique<PrintOrderExecuter>();
  }
  else {
    throw "Invalid Input";
  }

}