#include "SupplyRunner.hpp"

SupplyRunner::SupplyRunner(Storeroom& storeroom_) : storeroom(storeroom_) {}

std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients) {
  std::vector<Ingredient> runnersBag;
  // for every element in Ingredients
  for(IngredientMap::const_iterator i = ingredients.begin(); i != ingredients.end(); ++i){
    IngredientMap::iterator s = storeroom.find(i->first);
    if (s == storeroom.end()){throw "Ingredient not found";}
    if (s->second < i->second){throw "Not enough of this ingredient";}
    s->second -= i->second;
    for(unsigned j = 0; j < i->second; ++j) {runnersBag.push_back(s->first);}
    //} // may not need nexted loop because .find() traverses map
  }
  return runnersBag;
}
