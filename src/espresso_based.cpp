#include "espresso_based.h"

void EspressoBased::brew()
{
    using namespace std::chrono_literals;

    auto b1 = ftxui::dbox({ ftxui::text("Brewing " + this->get_name()) | ftxui::color(ftxui::Color::Red) | ftxui::bold | ftxui::center | ftxui::border });
    auto screenb1 = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(b1));
    ftxui::Render(screenb1, b1);
    screenb1.Print();
    for (auto& i : this->get_ingredients()) {
        auto screen = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(b1));
        std::string reset_position;

        std::random_device seeder;
        std::default_random_engine red { seeder() };
        std::default_random_engine green { seeder() };
        std::default_random_engine blue { seeder() };
        std::uniform_int_distribution<int> distribution(100, 255);
        auto R { distribution(red) };
        auto G { distribution(green) };
        auto B { distribution(blue) };

        for (double percentage { 0.0 }; percentage <= 1.002; percentage += 0.002) {
            std::string completed = std::to_string(int(percentage * 100)) + "/100";

            std::stringstream T;
            T << std::right << std::setw(10);
            T << i->get_name();
            T << " :";

            auto filling = ftxui::hbox({
                ftxui::text(T.str()) | ftxui::color(ftxui::Color::RGB(R, G, B)),
                ftxui::gauge(percentage) | ftxui::color(ftxui::Color::RGB(R, G, B)),
                ftxui::text(" " + completed) | ftxui::color(ftxui::Color::RGB(R, G, B)),
            });
            Render(screen, filling);
            std::cout << reset_position;
            screen.Print();
            reset_position = screen.ResetPosition();
            std::this_thread::sleep_for(0.01s);
        }
    }
    std::string reset_position;
    auto b2 = ftxui::dbox({ ftxui::text("Your " + this->get_name() + " is ready. ENJOY!!") | ftxui::color(ftxui::Color::Green) | ftxui::bold | ftxui::center });
    auto screenb2 = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(b2));
    ftxui::Render(screenb2, b2);
    screenb2.Print();

    for (int index = 0; index < 50; ++index) {
        std::random_device seeder;
        std::default_random_engine red { seeder() };
        std::default_random_engine green { seeder() };
        std::default_random_engine blue { seeder() };

        std::uniform_int_distribution<int> distribution(100, 255);
        auto R { distribution(red) };
        auto G { distribution(green) };
        auto B { distribution(blue) };

        auto x = ftxui::spinner(21, index) | ftxui::bold | ftxui::color(ftxui::Color::RGB(R, G, B));
        auto document = ftxui::vbox(std::move(x)) | ftxui::center;
        auto screen = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(document));
        Render(screen, document);
        std::cout << reset_position;
        screen.Print();
        reset_position = screen.ResetPosition();
        std::this_thread::sleep_for(0.1s);
    }
}

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