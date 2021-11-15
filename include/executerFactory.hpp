#ifndef executerFactoryDefine
#define executerFactoryDefine

#include <memory>
#include "OrderExecuterBase.hpp"
#include "PlaceOrderExecuter.hpp"
#include "CancelOrderExecuter.hpp"
#include "PrintOrderExecuter.hpp"

/*The executer factory is responsible for providing different type of
executers to the user. 

There are three choices currently implemented to construct executers which 
place/print/cancel the order.
*/

std::unique_ptr<OrderExecuterBase> executerFactory(char type);

#endif