#include "Cashier.hpp"
#include "Cook.hpp"

// #include <vector>
#include "restaurant-utility.hpp"


Cashier::Cashier(double money_) : money(money_), uid_count(0) { }

double Cashier::get_money() const {
  return money;
}

void Cashier::serve_customer(
        std::queue<Customer>& line,
        std::stack<Order>& orders){

  Customer *currCustomer;
  std::size_t currCustID;
  std::string numStr, singleItem;
  int quant;
  std::vector<std::string> tokOrder, currCustOrder;


  // take customer off queue and assign them a unique ID
  currCustomer = &(line.front());
  currCustID = uid_count;
  uid_count++;

  // take customer order and tokenize
  tokOrder = split(currCustomer->take_order(),' ');
  // for every 2 tokens, get quantity of a single item in order
  for(unsigned int i = 0; i < tokOrder.size(); i+=2){
    quant = std::stoi(tokOrder[i]);
    singleItem = tokOrder[i+1];

    // if single item in order is not valid, expel customer
    auto dishCheck = recipes.find(singleItem);
    if (dishCheck==recipes.end()){
      currCustomer->expel();
      line.pop();
      return;
    } else {
      // else, format order to add to orders stack
      for (auto j=0; j<quant; ++j){
        currCustOrder.push_back(singleItem);
      }
    }
  }

  // calculate cost of order
  double total = calculate_order_cost(currCustOrder);
  // if customer doesn't have enough money, expel them
  if (currCustomer->get_money()<total){
    currCustomer->expel();
    line.pop();
    return;
  } else {
    // else charge customer appropriate amount
    money += currCustomer->charge_money(total);
  }

  //push completed order to orders stack
  orders.push(Order(currCustID,currCustOrder));
  // cleanup
  line.pop();
}
