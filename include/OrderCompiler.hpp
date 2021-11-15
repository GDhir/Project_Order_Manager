#ifndef CompileOrder
#define CompileOrder

#include "OrderCompiler.hpp"
#include "Utils.hpp"
#include "OrderScanner.hpp"
#include "OrderParser.hpp"
#include <string>
#include <vector>
#include <memory>

/* Order Compiler compiles the order string in two stages
  The compiler first moves the string through the scanner. 
  
  The scanner scans the whole string and tokenizes the string to form a vector
  of individual tokens. These tokens are then moved through the parser.

  The parser then parses each individual strings to find if there is any issue.

  The parser also parses individual strings to form a struct called OrderDetails
  which contains the information related to the order ( both Buy side and Sell Side).

  The stages are summarized as below:

  Scanner (Tokenizes) -> Parser (Syntax Check) -> OrderDetails (Final Struct)
*/

class OrderCompiler
{

  OrderScanner scanner;
  std::unique_ptr<OrderParser> parser;
  OrderDetails details;
  std::vector<std::string> orderTokens;

public:
  OrderCompiler() = default;

  void compileOrder(std::string &orderStr);

  OrderDetails getOrderDetails();
};

#endif