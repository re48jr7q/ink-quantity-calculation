#ifndef INK_QUANTITY_H
#define INK_QUANTITY_H

//This helper function ensures that the user's input 
//data does not go over the maximum size of the type used.
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//This class asks the user to enter the number of printing sheets.
class NumberOfPrints
{
private:
    long m_prints{};

public:
    NumberOfPrints(long prints = 0) :m_prints(prints) {}

    NumberOfPrints(const NumberOfPrints& number) :m_prints{ number.m_prints } {}

    long getPrints()const
    {
        while (true)    //input control
        {
            std::cout << "Aantal A3+ druks: ";
            long prints{};
            std::cin >> prints;
            if ((!std::cin) || (prints < 0))
            {
                std::cin.clear();
                ignoreLine();
                std::cout << "Probeer opnieuw.\n";
            }
            else
            {
                ignoreLine();
                return prints;
            }
        }
    }
    friend std::ostream& operator<<(std::ostream& out, const NumberOfPrints p);

    friend std::istream& operator>>(std::istream& in, NumberOfPrints p);

    friend bool operator<(const NumberOfPrints& n, int i);
};

//This class asks the user to enter the ink occupancy on the printing sheet.
class InkOccupation
{
private:
    int m_ink{};

public:
    InkOccupation(int ink = 0) :m_ink{ ink } {}

    InkOccupation(const InkOccupation& ink) :m_ink{ ink.m_ink } {}

    int getInkOccupation()const
    {
        while (true)    //input control
        {
            std::cout << "Voer inktbezetting in (van 1 tot 100): ";
            int ink{};
            std::cin >> ink;
            if (!std::cin)
            {
                std::cin.clear();
                ignoreLine();
                std::cout << "Probeer opnieuw.\n";
            }
            else if ((ink < 1) || (ink > 100))
            {
                std::cin.clear();
                ignoreLine();
                std::cout << "Probeer opnieuw.\n";
            }
            else
            {
                ignoreLine();
                return ink;
            }
        }
    }
};

//This class asks the user what percent drying should be added to the ink.
class AddDrying
{
private:
    int m_addDrying{};

public:
    AddDrying(int addDrying = 0) :m_addDrying{ addDrying } {}

    AddDrying(const AddDrying& d) :m_addDrying{ d.m_addDrying } {}

    int getAddDrying()const
    {
        while (true)    //input control
        {
            std::cout << "Aantal procenten droging toevoegen (van 0 tot 10): ";
            int addDrying{};
            std::cin >> addDrying;
            if (!std::cin)
            {
                std::cin.clear();
                ignoreLine();
                std::cout << "Probeer het opnieuw.\n";
            }
            else if (addDrying < 0 || addDrying > 10)
            {
                std::cin.clear();
                ignoreLine();
                std::cout << "Probeer het opnieuw.\n";
            }
            else
            {
                ignoreLine();
                return addDrying;
            }
        }
    }
};

//This function calculate the result.
void printResult()
{
    NumberOfPrints p;
    const double num{ static_cast<double>(p.getPrints()) };
    InkOccupation i;
    const double ink{ static_cast<double>(i.getInkOccupation()) };
    AddDrying a;
    const double add{ static_cast<double>(a.getAddDrying()) };

    if (num < 1001.0)
    {
        const double inkConstant{ 0.4 };
        const double total{ ((inkConstant * ink) * num) / 100.0 };
        const double drying{ (add / 100.0) * total };

        std::cout << '\n';
        std::cout << "U heeft " << total << " gram inkt nodig.\n";
        std::cout << "En er moet " << drying << " gram droging worden toevoegd.\n";
    }
    else if (num > 1000.0 && num < 5001.0)
    {
        const double inkConstant{ 0.3 };
        const double total{ ((inkConstant * ink) * num) / 100.0 };
        const double drying{ (add / 100.0) * total };

        std::cout << '\n';
        std::cout << "U heeft " << total << " gram inkt nodig.\n";
        std::cout << "En er moet " << drying << " gram droging worden toevoegd.\n";
    }
    else
    {
        const double inkConstant{ 0.2 };
        const double total{ ((inkConstant * ink) * num) / 100.0 };
        const double drying{ (add / 100.0) * total };

        std::cout << '\n';
        std::cout << "U heeft " << total << " gram inkt nodig.\n";
        std::cout << "En er moet " << drying << " gram droging worden toevoegd.\n";
    }
}

#endif
