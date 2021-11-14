#include "OrderCompiler.hpp"
#include "parserFactory.hpp"

void OrderCompiler::compileOrder( std::string& orderStr ) {

  orderTokens = {};

  scanner.scanAndTokenizeOrder( orderStr, orderTokens );

  parser->parseAction( orderTokens[0], details );

  parser = parserFactory( details.action );

  parser->parseDetails( orderTokens, details );

}

OrderDetails OrderCompiler::getOrderDetails() {

  return details;

}