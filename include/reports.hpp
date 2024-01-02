
#ifndef SIECI_ZPO_REPORTS_HPP
#define SIECI_ZPO_REPORTS_HPP
#include "factory.hpp"

void generate_structure_report(const Factory& f, std::ostream& os);
void generate_simulation_turn_report(const Factory& f, std::ostream& os, Time t);
#endif //SIECI_ZPO_REPORTS_HPP
