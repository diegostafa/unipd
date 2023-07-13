#include "log_error.h"

log_error::log_error(const std::string& err) : _err(err){}

std::string log_error::get_error() const{ return _err; }
