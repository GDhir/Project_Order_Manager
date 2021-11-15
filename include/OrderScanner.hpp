#ifndef ScanOrder
#define ScanOrder

#include "OrderScanner.hpp"
#include <string>
#include <vector>
#include "InvalidInputException.hpp"
#include "Utils.hpp"

/*The OrderScanner class scans the order string and converts the string to 
  individual tokens. The scanner throws exception when string size is zero. 
  
  The scanner is not responsible for making other signficant exceptions which are 
  implemented by the Parser*/

class OrderScanner
{

public:
  OrderScanner() = default;

  void scanAndTokenizeOrder(std::string &orderStr, std::vector<std::string> &orderTokens);
};

#endif