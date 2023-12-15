#include "nodes.hpp"
Ramp::Ramp(ElementID id, TimeOffset di) : id_(id), di_(di){}
Worker::Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q) : id_(id), pd_(pd), q_(std::move(q)) {}
void PackageSender::push_package(Package &&package) {
    buffer_.emplace(package.get_id());
}

Storehouse::Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d) : id_(id), d_(std::move(d)) {}

void ReceiverPreferences::add_receiver(IPackageReceiver *r) {
    double num_of_receivers_begin = double(preferences_.size());
    if (num_of_receivers_begin == 0) {
        preferences_[r] = 1.0;
    } else {
        for (auto &rec: preferences_) {
            rec.second = 1 / (num_of_receivers_begin + 1);
        }
        preferences_[r] = 1 / (num_of_receivers_begin + 1);
    }
}


void ReceiverPreferences::remove_receiver(IPackageReceiver *r) {
    double num_of_receivers_begin = double(preferences_.size());
    if (num_of_receivers_begin > 1) {
        for (auto &rec: preferences_) {
            if (rec.first != r) {
                rec.second = 1 / (num_of_receivers_begin - 1);
            }
        }
    }
    preferences_.erase(r);
}


IPackageReceiver *ReceiverPreferences::choose_receiver() {
    auto prob = pg_();
    if (prob >= 0 && prob <= 1) {
        double distribution = 0.0;
        for (auto &rec : preferences_) {
            distribution = distribution + rec.second;
            if (prob <= distribution) {
                return rec.first;
            }
        }
    }
    return nullptr;
}



void PackageSender::send_package() {
    IPackageReceiver *receiver;
    if (buffer_) {
        receiver = receiver_preferences_.choose_receiver();
        receiver->receive_package(std::move(*buffer_));
        buffer_.reset();
    }
}



void Ramp::deliver_goods(Time t) {
    if (!buffer_) {
        push_package(Package());
        buffer_.emplace(id_);
        t_ = t;
    } else {
        if (t - di_ == t_) {
            push_package(Package());
        }
    }
}


void Worker::do_work(Time t) {
    if (!buffer_ && !q_->empty()) {
        buffer_.emplace(q_->pop());
        t_ = t;
    } else {
        if (t - t_ + 1 == pd_) {
            push_package(Package(buffer_.value().get_id()));
            buffer_.reset();
            if (!q_->empty()) {
                buffer_.emplace(q_->pop());
            }
        }
    }
}