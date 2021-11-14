#ifndef parserFactoryDefine
#define parserFactoryDefine

#include <memory>
#include "OrderParser.hpp"
#include "PlaceOrderParser.hpp"
#include "CancelOrderParser.hpp"
#include "PrintOrderParser.hpp"

std::unique_ptr<OrderParser> parserFactory( char type );

#endif