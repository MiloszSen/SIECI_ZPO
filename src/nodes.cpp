#include "nodes.hpp"
Ramp::Ramp(ElementID id, TimeOffset di) :  id_(id), di_(di){}
Worker::Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q) : id_(id), pd_(pd), q_(std::move(q)) {}
void PackageSender::push_package(Package &&package) {
    buffer_.emplace(package.get_id());
}

Storehouse::Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d) : id_(id), d_(std::move(d)) {}