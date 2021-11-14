#include "InvalidInputException.hpp"

    InvalidInputException::InvalidInputException( const std::string& errorVal, int32_t orderVal ): errorID(errorVal), orderID(orderVal) {

      errorMap[ "InvalidAction" ] = "The Action is incorrectly specified. Choose one of 'O', 'X' or 'P' ";
      errorMap[ "InvalidOrderID" ] = "The orderID is invalid. It should be a positive 32-bit integer value which must be unique for all orders";
      errorMap[ "InvalidOrderString" ] = "Order String Size should be a finite number";
      errorMap[ "InvalidCancelAction" ] = "Cancel Order Input requires an Order ID. Anything more/less than that is considered invalid input";
      errorMap[ "InvalidOrderAction" ] = "Placing an order requires OID, SYMBOL, SIDE, QTY, PX. Anything more/less than that is considered invalid input";
      errorMap[ "InvalidPrintAction" ] = "Print action should not specify any input other than the character P";
      errorMap[ "InvalidOrderType" ] = "Order Type must be a character value which is either B or S";
      errorMap[ "InvalidOrderQty" ] = "Order Qty must be an integer";
      errorMap[ "InvalidOrderPx" ] = "Order Price must be an integer";
      errorMap[ "InvalidIDForCancel" ] = "Order ID does not exist for cancellation. Specify the correct order ID corresponding to an already placed order";
      errorMap[ "NonUniqueOrderID" ] = "E " + std::to_string( orderID ) + " Duplicate Order ID";

    }

    const char* InvalidInputException::what() {

      return errorMap[errorID].c_str();

    }
