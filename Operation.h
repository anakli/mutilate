// -*- c++-mode -*-
#ifndef OPERATION_H
#define OPERATION_H

#include <string>

using namespace std;

class Operation {
public:
  enum type_enum {
    GET, GETW,
    SET, SETW
  };

  type_enum type;
  double start_time, end_time;

  double time() const { return (end_time - start_time) * 1000000; }

  bool operator < (const Operation& op) const {
    return (start_time < op.start_time);
  }

  const char* toString() {
    switch(type) {
    case GET:   return "GET";
    case GETW:  return "GETW";
    case SET:   return "SET";
    case SETW:  return "SETW";
    default:    return "?";
    }
  }
};

#endif // OPERATION_H
