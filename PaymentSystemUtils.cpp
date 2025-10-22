#include "PaymentSystem.h"
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>

PaymentSystem::PaymentMode PaymentSystem::parsePaymentMode(const std::string& input) {
    std::string mode = input;
    std::transform(mode.begin(), mode.end(), mode.begin(), ::tolower);

    if (mode == "paypal") return PaymentMode::PayPal;
    if (mode == "googlepay") return PaymentMode::GooglePay;
    if (mode == "creditcard") return PaymentMode::CreditCard;

    return PaymentMode::Unknown;
}
