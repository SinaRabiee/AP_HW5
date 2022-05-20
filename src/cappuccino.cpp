#include "cappuccino.h"

Cappuccino::Cappuccino()
    : side_items {}
{
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
    name = "Cappuccino";
}

Cappuccino::Cappuccino(const Cappuccino& cap)
    : EspressoBased(cap)
{
    auto side_list { const_cast<Cappuccino&>(cap).get_side_items() };

    for (auto& i : side_list) {
        if (i->get_name() == "Cinnamon")
            this->add_side_item(new Cinnamon(i->get_units()));
        else if (i->get_name() == "Chocolate")
            this->add_side_item(new Chocolate(i->get_units()));
        else if (i->get_name() == "Sugar")
            this->add_side_item(new Sugar(i->get_units()));
        else if (i->get_name() == "Cookie")
            this->add_side_item(new Cookie(i->get_units()));
        else if (i->get_name() == "Espresso")
            this->add_side_item(new Espresso(i->get_units()));
        else if (i->get_name() == "Milk")
            this->add_side_item(new Milk(i->get_units()));
        else if (i->get_name() == "MilkFoam")
            this->add_side_item(new MilkFoam(i->get_units()));
        else if (i->get_name() == "Water")
            this->add_side_item(new Water(i->get_units()));
    }
}

Cappuccino::~Cappuccino()
{
    for (const auto& i : side_items)
        delete i;
    side_items.clear();
}

void Cappuccino::operator=(const Cappuccino& cap)
{
    if (this == &cap)
        return;

    for (const auto& i : side_items)
        delete i;
    side_items.clear();
    auto side_list { const_cast<Cappuccino&>(cap).get_side_items() };
    for (auto& i : side_list) {
        if (i->get_name() == "Cinnamon")
            this->add_side_item(new Cinnamon(i->get_units()));
        else if (i->get_name() == "Chocolate")
            this->add_side_item(new Chocolate(i->get_units()));
        else if (i->get_name() == "Sugar")
            this->add_side_item(new Sugar(i->get_units()));
        else if (i->get_name() == "Cookie")
            this->add_side_item(new Cookie(i->get_units()));
        else if (i->get_name() == "Espresso")
            this->add_side_item(new Espresso(i->get_units()));
        else if (i->get_name() == "Milk")
            this->add_side_item(new Milk(i->get_units()));
        else if (i->get_name() == "MilkFoam")
            this->add_side_item(new MilkFoam(i->get_units()));
        else if (i->get_name() == "Water")
            this->add_side_item(new Water(i->get_units()));
    }
}

std::string Cappuccino::get_name()
{
    return this->name;
}

double Cappuccino::price()
{
    double total { 0.0 };
    for (const auto& i : side_items)
        total += i->price();
    for (const auto& i : ingredients)
        total += i->price();
    return total;
}

void Cappuccino::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

std::vector<Ingredient*>& Cappuccino::get_side_items()
{
    return side_items;
}