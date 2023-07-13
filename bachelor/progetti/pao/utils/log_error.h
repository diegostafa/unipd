#ifndef LOG_ERROR_H
#define LOG_ERROR_H

#include <string>

class log_error
{
private:
  const std::string& _err;
public:
  log_error(const std::string& err);
  std::string get_error() const;
};

#endif // LOG_ERROR_H
