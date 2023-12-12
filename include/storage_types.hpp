#ifndef SIECI_ZPO_STORAGE_TYPES_HPP
#define SIECI_ZPO_STORAGE_TYPES_HPP
#include "package.hpp"
#include <list>

class IPackageStockpile{
public:
    IPackageStockpile() = default;
    using const_iterator = std::list<Package>::const_iterator;

    virtual void push(Package&& package) = 0;
    virtual const_iterator cbegin() const = 0;
    virtual const_iterator cend() const = 0;
    virtual const_iterator begin() const = 0;
    virtual const_iterator end() const = 0;
    virtual std::size_t size() const = 0;
    virtual bool empty() const = 0;

    virtual ~IPackageStockpile() = default;
};
enum class PackageQueueType{
    FIFO, LIFO
};
class IPackageQueue : public IPackageStockpile{
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
    ~IPackageQueue() override = default;
};
class PackageQueue : public IPackageQueue{
public:
    PackageQueue(PackageQueueType queue_type){
        queue_type_ = queue_type;
    };
    virtual void push(Package&& p){
        packages.emplace_back(std::move(p));
    };
    virtual const_iterator cbegin() const {return packages.cbegin();};
    virtual const_iterator cend() const {return packages.cend();};

    virtual const_iterator begin() const {return packages.begin();};
    virtual const_iterator end() const {return packages.end();};

    virtual std::size_t size() const {return packages.size();};
    virtual bool empty() const {return packages.empty();};

    virtual Package pop() ;
    virtual PackageQueueType get_queue_type() const {return queue_type_;};
private:
    PackageQueueType queue_type_;
    std::list<Package> packages;
};
#endif //SIECI_ZPO_STORAGE_TYPES_HPP
