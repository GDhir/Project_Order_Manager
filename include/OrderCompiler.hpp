#ifndef CompileOrder
#define CompileOrder

#include "OrderCompiler.hpp"
#include "Utils.hpp"
#include "OrderScanner.hpp"
#include "OrderParser.hpp"
#include <string>
#include <vector>
#include <memory>

class OrderCompiler {

  OrderScanner scanner;
  std::unique_ptr<OrderParser> parser;
  OrderDetails details;
  std::vector<std::string> orderTokens;

  public:

    OrderCompiler() = default;

    void compileOrder( std::string& orderStr );

    OrderDetails getOrderDetails();

};

#endif