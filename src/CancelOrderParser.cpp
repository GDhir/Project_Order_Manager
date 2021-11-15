#include "CancelOrderParser.hpp"

void CancelOrderParser::parseDetails(const std::vector<std::string> &actionVal, OrderDetails &details)
{

  if (actionVal.size() == 2)
  {

    parseOrderID(actionVal[1], details);
  }
  else
  {
    throw InvalidInputException("InvalidCancelAction");
  }
};