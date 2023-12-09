#ifndef SIECI_ZPO_TYPES_HPP
#define SIECI_ZPO_TYPES_HPP
#include <list>
#include <functional>
using ElementID = long unsigned;
using ProbabilityGenerator = std::function<double()>;
using TimeOffset = long unsigned;
using Time = long unsigned;
#endif //SIECI_ZPO_TYPES_HPP
