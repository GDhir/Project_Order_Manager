#ifndef utilsDefine
#define utilsDefine

#include <list>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <memory>

struct OrderDetails {

  int32_t orderID;
  std::string symbol;
  char orderType;
  char action;
  mutable int orderQty;
  double orderValue;

};

bool isInteger(const std::string& str);

bool isFloat(const std::string& str);

void removeLeadingSpace( std::string& str);

typedef std::list<std::string> results_t;

class LessCompare {

  public:
    bool operator()( const OrderDetails& left, const OrderDetails& right );
};

class GreaterCompare{

  public:
    bool operator()( const OrderDetails& left, const OrderDetails& right );

};

using IteratorBuy = std::multiset< OrderDetails, LessCompare >::iterator;
using IteratorSell = std::multiset< OrderDetails, GreaterCompare >::iterator;
using BuyMultiset = std::multiset< OrderDetails, LessCompare >;
using SellMultiset = std::multiset< OrderDetails, GreaterCompare >;
using BuyMap = std::unordered_map< int32_t, IteratorBuy>;
using SellMap = std::unordered_map< int32_t, IteratorSell>;

#endif