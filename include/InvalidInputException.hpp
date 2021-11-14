#ifndef InvalidInput
#define InvalidInput

#include<exception>
#include<string>
#include<unordered_map>

class InvalidInputException: public std::exception {

  std::string errorID;
  int32_t orderID;
  std::unordered_map< std::string, std::string > errorMap;

  public:

    InvalidInputException() = delete;

    InvalidInputException( const std::string& errorVal, int32_t orderVal = 0 );

    virtual const char* what();

};

#endif