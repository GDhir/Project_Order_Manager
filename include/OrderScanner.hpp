#ifndef ScanOrder
#define ScanOrder

#include "OrderScanner.hpp"
#include <string>
#include <vector>
#include "InvalidInputException.hpp"
#include "Utils.hpp"

class OrderScanner {

  public:

  OrderScanner() = default;

  void scanAndTokenizeOrder( std::string& orderStr, std::vector<std::string>& orderTokens ); 

};

#endif