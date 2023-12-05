#ifndef SIECI_ZPO_PACKAGE_HPP
#define SIECI_ZPO_PACKAGE_HPP
#include <list>
class Package{

};
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
#endif //SIECI_ZPO_PACKAGE_HPP
