#ifndef SIECI_ZPO_STORAGE_TYPES_HPP
#define SIECI_ZPO_STORAGE_TYPES_HPP
#include "package.hpp"
#include <list>

class IPackageStockpile{
public:
    using const_iterator = std::list<Package>::const_iterator;

    virtual ~IPackageStockpile() = default;

    virtual void push(const Package& package) = 0;
    virtual const_iterator cbegin() const = 0;
    virtual const_iterator cend() const = 0;
    virtual const_iterator begin() const = 0;
    virtual const_iterator end() const = 0;
    virtual std::size_t size() const = 0;
    virtual bool empty() const = 0;
};
enum class PackageQueueType{
    FIFO, LIFO
};
class IPackageQueue{
    virtual Package pop() const = 0;
    virtual PackageQueueType get_queue_type() const = 0;
};
class PackageQueue{
    PackageQueue(PackageQueueType){};
};
#endif //SIECI_ZPO_STORAGE_TYPES_HPP
