#include "PlaceOrderExecuter.hpp"

std::string PlaceOrderExecuter::createOutput(const OrderDetails &details)
{

  return ("F " + std::to_string(details.orderID) + " " + details.symbol + " " +
          std::to_string(details.orderQty) + " " + std::to_string(details.orderValue) + "\n");
}

results_t PlaceOrderExecuter::executeSell(BuyMultiset &buySet, BuyMap &buyMap, OrderDetails &orderDetails)
{

  results_t outputs;
  IteratorBuy itr = buySet.end();
  --itr;
  while (buySet.size() > 0 && itr->orderValue >= orderDetails.orderValue)
  {

    if (orderDetails.orderQty >= itr->orderQty)
    {

      auto temp = orderDetails;
      temp.orderQty = itr->orderQty;
      temp.orderValue = itr->orderValue;
      outputs.push_back(createOutput(temp));
      outputs.push_back(createOutput(*itr));

      orderDetails.orderQty -= itr->orderQty;

      buyMap.erase(itr->orderID);
      buySet.erase(itr);

      if (buySet.size() > 0)
      {
        itr = --buySet.end();
      }

      if (orderDetails.orderQty == 0)
        break;
    }
    else
    {

      auto temp = orderDetails;
      temp.orderValue = itr->orderValue;
      outputs.push_back(createOutput(temp));

      temp = *itr;
      temp.orderQty = orderDetails.orderQty;
      outputs.push_back(createOutput(temp));

      itr->orderQty -= orderDetails.orderQty;
      orderDetails.orderQty = 0;

      break;
    }
  }

  return outputs;
}

results_t PlaceOrderExecuter::executeBuy(SellMultiset &sellSet, SellMap &sellMap, OrderDetails &orderDetails)
{

  results_t outputs;

  IteratorSell itr = sellSet.end();
  --itr;
  while (sellSet.size() > 0 && itr->orderValue <= orderDetails.orderValue)
  {

    if (orderDetails.orderQty >= itr->orderQty)
    {

      auto temp = orderDetails;
      temp.orderQty = itr->orderQty;
      temp.orderValue = itr->orderValue;
      outputs.push_back(createOutput(temp));
      outputs.push_back(createOutput(*itr));

      orderDetails.orderQty -= itr->orderQty;

      sellMap.erase(itr->orderID);
      sellSet.erase(itr);

      if (sellSet.size() > 0)
      {
        itr = --sellSet.end();
      }

      if (orderDetails.orderQty == 0)
      {
        break;
      }
    }
    else
    {

      auto temp = orderDetails;
      temp.orderValue = itr->orderValue;
      outputs.push_back(createOutput(temp));

      temp = *itr;
      temp.orderQty = orderDetails.orderQty;
      outputs.push_back(createOutput(temp));

      itr->orderQty -= orderDetails.orderQty;
      orderDetails.orderQty = 0;

      break;
    }
  }

  return outputs;
}

results_t PlaceOrderExecuter::executeActions(BuyMultiset &buySet, SellMultiset &sellSet, BuyMap &buyMap, SellMap &sellMap, OrderDetails &orderDetails)
{

  results_t outputs;

  if (buyMap.find(orderDetails.orderID) != buyMap.end() || sellMap.find(orderDetails.orderID) != sellMap.end())
  {

    throw InvalidInputException("NonUniqueOrderID", orderDetails.orderID);
  }
  else if (orderDetails.orderType == 'B')
  {

    if (sellSet.size() > 0)
    {
      outputs = executeBuy(sellSet, sellMap, orderDetails);
    }

    if (orderDetails.orderQty != 0)
    {

      buySet.insert(orderDetails);
      auto itr = buySet.find(orderDetails);
      buyMap[orderDetails.orderID] = itr;
    }
  }
  else if (orderDetails.orderType == 'S')
  {

    if (buySet.size() > 0)
    {
      outputs = executeSell(buySet, buyMap, orderDetails);
    }

    if (orderDetails.orderQty != 0)
    {

      sellSet.insert(orderDetails);
      auto itr = sellSet.find(orderDetails);
      sellMap[orderDetails.orderID] = itr;
    }
  }
  else
  {

    throw "Invalid Input Order Details";
  }

  return outputs;
}