#ifndef SIECI_ZPO_NODES_HPP
#define SIECI_ZPO_NODES_HPP
#include "package.hpp"
#include "types.hpp"
#include <map>
#include <optional>
#include "storage_types.hpp"
class IPackageReceiver{
public:
    virtual void receive_package(Package&&) const = 0;
    virtual ElementID get_id() const = 0;
    virtual IPackageStockpile::const_iterator cbegin() const = 0;
    virtual IPackageStockpile::const_iterator cend() const = 0;
    virtual IPackageStockpile::const_iterator begin() const = 0;
    virtual IPackageStockpile::const_iterator end() const = 0;
};
class ReceiverPreferences{
public:
    using preferences_t = std::map<IPackageReceiver*, double>;
    using const_iterator = preferences_t::const_iterator;

    ReceiverPreferences(ProbabilityGenerator pg);
    void add_receiver(IPackageReceiver* r);
    void remove_receiver(IPackageReceiver* r);
    IPackageReceiver* choose_receiver();
    preferences_t& get_preferences() {return preferences_;};
    const_iterator cbegin() const {return preferences_.cbegin();};
    const_iterator cend() const {return preferences_.cend();};
    const_iterator begin() const {return preferences_.begin();};
    const_iterator end() const {return preferences_.end();};

private:
    ProbabilityGenerator pg_;
    preferences_t preferences_;
};
class PackageSender{
public:
    ReceiverPreferences receiver_preferences_;
    PackageSender() = default;
    PackageSender(PackageSender&&) = default;
    void send_package();
    std::optional<Package>& get_sending_buffer() {return buffer_;};
protected:
    void push_package(Package&&);
private:
    std::optional<Package> buffer_ = std::nullopt;

};
class Ramp : public PackageSender{
public:
    Ramp(ElementID id, TimeOffset di);
    void deliver_goods(Time t);
    TimeOffset get_delivery_interval() const {return di_;};
    ElementID get_id() const {return id_;};
private:
    ElementID id_;
    TimeOffset di_;
};


#endif //SIECI_ZPO_NODES_HPP
