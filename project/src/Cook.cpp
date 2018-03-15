#include "Cook.hpp"

Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_):
        runner(runner_),
        kitchen(kitchen_) { }

void Cook::prepare_dish(
        std::stack<Order>& orders,
        std::queue<std::pair<std::size_t,
        Dish>>& finished_dishes){
  // pop order
  Order o = orders.pop();
  // read order
  std::vector<std::string> orderIngreds = o.get_items();
  // from recipes, get order ingredients

  std::vector<Ingredient> runnersBag;
  // supplyrunner get ingredients
  runnersBag = runner.get_ingredients(
  // (try/catch here?)

  // some vector<ingredients> to IngredientMap conversion here

  // kitchen order
  Dish dish = kitchen.prepare_dish(runnersBag)
  // queue order

}
