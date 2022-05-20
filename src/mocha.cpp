#include "mocha.h"

Mocha::Mocha()
    : side_items {}
{
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
    ingredients.push_back(new Chocolate(1));
    name = "Mocha";
}

Mocha::Mocha(const Mocha& Moc)
    : EspressoBased(Moc)
{
    auto side_list { const_cast<Mocha&>(Moc).get_side_items() };

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

Mocha::~Mocha()
{
    for (const auto& i : side_items)
        delete i;
    side_items.clear();
}

void Mocha::operator=(const Mocha& Moc)
{
    if (this == &Moc)
        return;

    for (const auto& i : side_items)
        delete i;
    side_items.clear();
    auto side_list { const_cast<Mocha&>(Moc).get_side_items() };
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

std::string Mocha::get_name()
{
    return this->name;
}

double Mocha::price()
{
    double total { 0.0 };
    for (const auto& i : side_items)
        total += i->price();
    for (const auto& i : ingredients)
        total += i->price();
    return total;
}

void Mocha::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

std::vector<Ingredient*>& Mocha::get_side_items()
{
    return side_items;
}