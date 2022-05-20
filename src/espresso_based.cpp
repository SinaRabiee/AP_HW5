#include "espresso_based.h"

std::vector<Ingredient*>& EspressoBased::get_ingredients()
{
    return ingredients;
}

EspressoBased::~EspressoBased()
{
    for (const auto& i : ingredients)
        delete i;
    ingredients.clear();
}

EspressoBased::EspressoBased(const EspressoBased& esp)
    : EspressoBased()
{
    auto eng_list { const_cast<EspressoBased&>(esp).get_ingredients() };

    for (auto& i : eng_list) {
        if (i->get_name() == "Cinnamon")
            ingredients.push_back(new Cinnamon(i->get_units()));
        else if (i->get_name() == "Chocolate")
            ingredients.push_back(new Chocolate(i->get_units()));
        else if (i->get_name() == "Sugar")
            ingredients.push_back(new Sugar(i->get_units()));
        else if (i->get_name() == "Cookie")
            ingredients.push_back(new Cookie(i->get_units()));
        else if (i->get_name() == "Espresso")
            ingredients.push_back(new Espresso(i->get_units()));
        else if (i->get_name() == "Milk")
            ingredients.push_back(new Milk(i->get_units()));
        else if (i->get_name() == "MilkFoam")
            ingredients.push_back(new MilkFoam(i->get_units()));
        else if (i->get_name() == "Water")
            ingredients.push_back(new Water(i->get_units()));
    }
    name = esp.name;
}

void EspressoBased::operator=(const EspressoBased& esp)
{
    for (auto& i : ingredients)
        delete i;
    ingredients.clear();

    auto eng_list { const_cast<EspressoBased&>(esp).get_ingredients() };
    for (auto& i : eng_list) {
        if (i->get_name() == "Cinnamon")
            ingredients.push_back(new Cinnamon(i->get_units()));
        else if (i->get_name() == "Chocolate")
            ingredients.push_back(new Chocolate(i->get_units()));
        else if (i->get_name() == "Sugar")
            ingredients.push_back(new Sugar(i->get_units()));
        else if (i->get_name() == "Cookie")
            ingredients.push_back(new Cookie(i->get_units()));
        else if (i->get_name() == "Espresso")
            ingredients.push_back(new Espresso(i->get_units()));
        else if (i->get_name() == "Milk")
            ingredients.push_back(new Milk(i->get_units()));
        else if (i->get_name() == "MilkFoam")
            ingredients.push_back(new MilkFoam(i->get_units()));
        else if (i->get_name() == "Water")
            ingredients.push_back(new Water(i->get_units()));
    }
    name = esp.name;
}