#include "Cook.hpp"

Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_):
        runner(runner_),
        kitchen(kitchen_) { }

void Cook::prepare_dish(
        std::stack<Order>& orders,
        std::queue<std::pair<std::size_t, Dish>>& finished_dishes){
  Order *o;
  std::string dishName;
  IngredientMap orderIngreds;
  std::vector<Ingredient> runnersBag;
  Dish dish;

  // for i = 0; while i < orders.size(); i++
  for(unsigned int i=0; i<orders.size(); ++i){
    // take top order ( table # and vector of dish names (strings))
    o = &(orders.top());
    // for each dishName in order for table #i
    for(unsigned int j=0; j < (*o).get_items().size(); ++j){
      // read dish name
      dishName = (*o).get_items()[j];
      // get ingredients of dish from recipebook
      orderIngreds = recipes.find(dishName)->second;
      // supplyrunner get ingredients
      runnersBag = runner.get_ingredients(orderIngreds);
      // cook goes into kitchen with retrieved ingredients and makes dish
      dish = kitchen.prepare_dish(std::move(orderIngreds));
      // cook takes finished dish and puts it in queue
      finished_dishes.push(std::pair<std::size_t,Dish>(o->get_id(),dish));
    }
    // remove top order from stack
    orders.pop();
  }
}

RecipeBook recipes = {
            {"Fries",{
              {"Potato",1},
              {"CanolaOil",1}
            }
          },{"Burger",{
              {"WheatBun", 2},
              {"BeefPatty", 1},
              {"Cheese", 1},
              {"Lettuce", 1},
              {"Tomato", 1}
            }
          },{"DoubleBurger",{
              {"WheatBun", 3},
              {"BeefPatty", 2},
              {"Cheese", 2},
              {"Lettuce", 3},
              {"Tomato", 1}
            }
          },{"IceCreamCone",{
              {"SugarCone", 1},
              {"VanillaCream", 1}
            }
          },{"SmallDrink",{
              {"SmallCup", 1}
            }
          },{"MediumDrink",{
              {"MediumCup", 1}
            }
          },{"LargeDrink",{
              {"LargeCup", 1}
            }
          },{"Salad",{
              {"Lettuce", 1},
              {"Tomato", 1},
              {"SaladDressing", 1},
              {"Fork", 1}
            }
          },{"#1",{
              {"MediumCup", 1},
              {"Potato", 1},
              {"CanolaOil", 1},
              {"WheatBun", 2},
              {"BeefPatty", 1},
              {"Cheese", 1},
              {"Lettuce", 1},
              {"Tomato", 1}
            }
          },{"#2",{
              {"MediumCup", 1},
              {"Potato", 1},
              {"CanolaOil", 1},
              {"WheatBun", 3},
              {"BeefPatty", 2},
              {"Cheese", 2},
              {"Lettuce", 3},
              {"Tomato", 1}
            }
          },{"#3",{
              {"MediumCup", 1},
              {"Potato", 1},
              {"CanolaOil", 1},
              {"WheatBun", 4},
              {"BeefPatty", 2},
              {"Cheese", 2},
              {"Lettuce", 2},
              {"Tomato", 2}
            }
          },
};
