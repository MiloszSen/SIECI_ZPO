#include "storage_types.hpp"

Package PackageQueue::pop(){
    if (queue_type_ == PackageQueueType::FIFO){
        Package p = std::move(packages.front());
        packages.pop_front();
        return p;
    }
    else {
        Package p = std::move(packages.back());
        packages.pop_back();
        return p;
    }
}