#include "Header.h"

#include "Zoo.h"
#include "List.h"
#include "Animal.h"
#include "Node.h"

ostream& operator<<(std::ostream& out, const Animal& object)
{
    return out << object._name << " " << object._clss << " " << object._weight << endl;
}
istream& operator>>(std::istream& in, Animal& object)
{
    in >> object._name >> object._clss >> object._weight;
    if (!in)
    {
        object = Animal();
    }
    return in;
}

bool action_weight(Animal object, double weight)
{
    if (object.GetWeight() == weight)
    {
        return 1;
    }
    return 0;
}

bool action_pop1(Animal object, double weight)
{
    if (object.GetWeight() >= weight)
    {
        return 1;
    }
    return 0;
}

bool action_country(Animal object, string clss)
{
    if (object.GetClass() == clss)
    {
        return 1;
    }
    return 0;
}

bool action_name(Animal object, string name)
{
    if (object.GetName() == name)
    {
        return 1;
    }
    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int option = 0;
    int weight = 0;
    int check = 0;
    string name;
    string country;
    Animal c;

    Zoo zoo;

    do {
        cout << "1.Створити об'єкт класу" << endl;
        cout << "2.Показати загальну кількість" << endl;
        cout << "3.Додати до бази даних" << endl;
        cout << "4.Видалити (назва, класс, вага)" << endl;
        cout << "5.Вивести дані" << endl;
        cout << "6.Скопіювати дані та вивести їх" << endl;
        cout << "7.Вивести кількість  із заданою вагою" << endl;
        cout << "8.Вивести  із заданою назвою" << endl;
        cout << "9.Вивести НП із заданим класом" << endl;
        cout << "10.Завершити роботу програми" << endl;
        do {
            cin >> option;
            if (option <= 0 || option >= 11) {
                cout << "Значення невірне, введіть ще раз: ";
            }
        } while (option <= 0 || option >= 11);
        cout << endl;
        switch (option)
        {
        case 1:
            cout << "Введіть дані(назва, класс, вага) через пробіл: ";
            cin >> c;
            zoo + c;
            cout << "Створено!" << endl << endl;
            break;
        case 2:
            cout << "Загальна кількість тварин:" << zoo.GetAnimalsCount() << endl << endl;
            break;
        case 3:
            cout << "Введіть тварину, яку додати(назва, клас, вага) через пробіл: ";
            cin >> c;
            zoo + c;
            cout << "Додано!" << endl;
            break;
        case 4:
            cout << "Введіть тварину, яку видалити(назва, клас, вага) через пробіл: ";
            cin >> c;
            zoo - c;
            cout << "Видалено!" << endl;
            break;
        case 5:
            cout << "тварина: " << endl;
            cout << endl << "К-сть: " << zoo.GetAnimalsCount() << endl;
            zoo.Print();

            cout << endl;
            break;
        case 7:
        {
            cout << "Введіть вагу: " << endl;
            cin >> weight;
            List tmp = zoo.Iterator_pop(action_weight, weight);

            for (int i = 0; i < tmp.GetSize(); i++)
            {
                cout << tmp[i] << endl;
            }

            break;
        }
        case 8:
        {
            cout << "Введіть країну: " << endl;
            cin >> country;
            List tmp = zoo.Iterator_str(action_country, country);

            for (int i = 0; i < tmp.GetSize(); i++)
            {
                cout << tmp[i] << endl;
            }
            break;
        }
        case 9:
        {
            cout << "Введіть назву: " << endl;
            cin >> name;
            List tmp = zoo.Iterator_str(action_name, name);
            for (int i = 0; i < tmp.GetSize(); i++)
            {
                cout << tmp[i] << endl;
            }
            break;
        }
        }
        if (option == 6)
        {
            Zoo zoo_tmp(zoo);
            cout << "animals: " << endl;
            zoo_tmp.Print();
            cout << endl;
        }
    } while (option != 10);

    return 0;
}
