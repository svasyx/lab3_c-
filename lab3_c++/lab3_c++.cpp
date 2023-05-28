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
        cout << "1.�������� ��'��� �����" << endl;
        cout << "2.�������� �������� �������" << endl;
        cout << "3.������ �� ���� �����" << endl;
        cout << "4.�������� (�����, �����, ����)" << endl;
        cout << "5.������� ���" << endl;
        cout << "6.��������� ��� �� ������� ��" << endl;
        cout << "7.������� �������  �� ������� �����" << endl;
        cout << "8.�������  �� ������� ������" << endl;
        cout << "9.������� �� �� ������� ������" << endl;
        cout << "10.��������� ������ ��������" << endl;
        do {
            cin >> option;
            if (option <= 0 || option >= 11) {
                cout << "�������� ������, ������ �� ���: ";
            }
        } while (option <= 0 || option >= 11);
        cout << endl;
        switch (option)
        {
        case 1:
            cout << "������ ���(�����, �����, ����) ����� �����: ";
            cin >> c;
            zoo + c;
            cout << "��������!" << endl << endl;
            break;
        case 2:
            cout << "�������� ������� ������:" << zoo.GetAnimalsCount() << endl << endl;
            break;
        case 3:
            cout << "������ �������, ��� ������(�����, ����, ����) ����� �����: ";
            cin >> c;
            zoo + c;
            cout << "������!" << endl;
            break;
        case 4:
            cout << "������ �������, ��� ��������(�����, ����, ����) ����� �����: ";
            cin >> c;
            zoo - c;
            cout << "��������!" << endl;
            break;
        case 5:
            cout << "�������: " << endl;
            cout << endl << "�-���: " << zoo.GetAnimalsCount() << endl;
            zoo.Print();

            cout << endl;
            break;
        case 7:
        {
            cout << "������ ����: " << endl;
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
            cout << "������ �����: " << endl;
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
            cout << "������ �����: " << endl;
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
