#ifndef executerFactoryDefine
#define executerFactoryDefine

#include <memory>
#include "OrderExecuterBase.hpp"
#include "PlaceOrderExecuter.hpp"
#include "CancelOrderExecuter.hpp"
#include "PrintOrderExecuter.hpp"

std::unique_ptr<OrderExecuterBase> executerFactory( char type );

#endif