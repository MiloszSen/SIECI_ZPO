#ifndef SIECI_ZPO_PACKAGE_HPP
#define SIECI_ZPO_PACKAGE_HPP
#include <list>
#include <types.hpp>
#include <set>
class Package{
public:
    Package();
    explicit Package(ElementID id) : id_(id) {assigned_IDs.insert(id_);}
    Package(Package &&package) noexcept : id_(package.id_){}
    Package &operator = (Package &&package) noexcept;
    ElementID get_id() const {return id_;};
    ~Package();
private:
    ElementID id_;
    std::set<ElementID> assigned_IDs;
    std::set<ElementID> freed_IDs;
};


#endif //SIECI_ZPO_PACKAGE_HPP
