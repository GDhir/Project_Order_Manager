#ifndef parserFactoryDefine
#define parserFactoryDefine

#include <memory>
#include "OrderParser.hpp"
#include "PlaceOrderParser.hpp"
#include "CancelOrderParser.hpp"
#include "PrintOrderParser.hpp"

/*The parser factory is responsible for providing different type of
parsers to the user. 

There are three choices currently implemented to construct parsers which 
place/print/cancel the order.
*/

std::unique_ptr<OrderParser> parserFactory(char type);

#endif