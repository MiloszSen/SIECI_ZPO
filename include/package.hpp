#ifndef SIECI_ZPO_PACKAGE_HPP
#define SIECI_ZPO_PACKAGE_HPP
#include <list>
#include <types.hpp>
#include <set>
class Package{
public:
    Package();
    Package(ElementID id);
    Package(Package&&);
    Package &operator = (Package&&);
    ElementID get_id() const;
    ~Package();
private:
    ElementID id_;
    static std::set<ElementID> assigned_IDs;
    static std::set<ElementID> freed_IDs;
    const ElementID BLANK_ID = -1;
};


#endif //SIECI_ZPO_PACKAGE_HPP
