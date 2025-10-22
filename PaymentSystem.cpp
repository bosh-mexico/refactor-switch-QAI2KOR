#include "PaymentSystem.h"
#include <string>
#include <unordered_map>
#include <functional>

PaymentSystem::PaymentSystem() {
    handlers = {
        { PaymentMode::PayPal, [this](double amount) { processPayPal(amount); } },
        { PaymentMode::GooglePay, [this](double amount) { processGooglePay(amount); } },
        { PaymentMode::CreditCard, [this](double amount) { processCreditCard(amount); } }
    };
}
