#include "package.hpp"
std::set<ElementID> Package::assigned_IDs {0};
std::set<ElementID> Package::freed_IDs;

Package::Package() {
    ElementID newID;
    if (!freed_IDs.empty()){
        newID = *freed_IDs.begin();
        freed_IDs.erase(newID);
    }
    else {
        newID = *std::prev(assigned_IDs.end()) + 1;
    }
    assigned_IDs.insert(newID);
    id_ = newID;
}

Package::Package(ElementID id) {
    assigned_IDs.insert(id);
    id_ = id;
}

Package::Package(Package &&package){
    id_ = package.id_;
    package.id_ = BLANK_ID;

}
ElementID Package::get_id() const {
    return id_;
}

Package &Package::operator = (Package &&package){
    if (id_ != BLANK_ID){
        assigned_IDs.erase(id_);
        freed_IDs.insert(id_);
    }
    id_ = package.id_;
    package.id_ = BLANK_ID;
    return *this;
}

Package::~Package(){
    if (id_ != BLANK_ID) {
        freed_IDs.insert(id_);
        assigned_IDs.erase(id_);
    }
}