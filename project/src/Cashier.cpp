#include "Cashier.hpp"

Cashier::Cashier(double money_) : money(money_) { }

double Cashier::get_money() const {
  return money;
}

void Cashier::serve_customer(
        std::queue<Customer>& line,
        std::stack<Order>& orders){
  // take customer off queue and assign them a unique ID
  // if order is valid
    // format order according to cashier.hpp
  // calculate cost of order
  // charge customer appropriate amount
    // if customer doesn't have enough money, expel them instead
  // take formatted order and convert to Order class (id, vector of items)
  // push order to orders stack
}
