#include "PaymentSystem.h"
#include <string>
#include <unordered_map>
#include <functional>

void PaymentSystem::checkout(PaymentMode mode, double amount) {
    auto it = handlers.find(mode);
    if (it != handlers.end()) {
        it->second(amount);
    } else {
        processUnknown(amount);
    }
}
