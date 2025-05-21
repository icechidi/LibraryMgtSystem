#include "LibraryException.h"

LibraryException::LibraryException(const string& msg) : runtime_error(msg) {}
