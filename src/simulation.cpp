
#include "simulation.hpp"

void simulate(Factory& factory, Time t, std::function<void (Factory&, Time)> do_report){
    if (!factory.is_consistent()){
        throw std::logic_error("Funkcja jest niespójna");
    }
    for (Time i = 0; i < t; i++) {
        factory.do_delivery(i);
        factory.do_package_passing();
        factory.do_work(i);
        do_report(factory, i);
    }
}