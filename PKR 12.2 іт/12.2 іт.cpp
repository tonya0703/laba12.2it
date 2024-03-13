// pkr_12_2_it

#include <iostream>
using namespace std;


struct Elem
{
    double info;
    Elem* link;
};

Elem* first = NULL;  // Початок списку

// Функція для додавання нового елемента в кінець списку
void AddElem(double info)
{
    Elem* newElem = new Elem;
    newElem->info = info;
    newElem->link = NULL;

    // Якщо список порожній, то новий елемент стає головою
    if (first == NULL) {
        first = newElem;
    }
    // Інакше, пройти до кінця списку і додати новий елемент в кінець
    else {
        Elem* tmp = first;
        while (tmp->link != NULL) {
            tmp = tmp->link;
        }
        tmp->link = newElem;
    }
}


void PrintList()
{
    Elem* tmp = first;
    while (tmp != NULL) {
        cout << tmp->info << "; ";
        tmp = tmp->link;
    }
    cout << endl;
}

void AddAfterElem(int V1, int V2)
{
    Elem* tmp = first;
    while (tmp != NULL)
    {
        if (tmp->info == V1)
        {
            Elem* newElem = new Elem;
            newElem->info = V2;
            newElem->link = tmp->link;
            tmp->link = newElem;
            tmp = tmp->link;
        }
        tmp = tmp->link;
    }
}

int main()
{
    int n;
    double info;
    cout << "Enter n of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter info for element: ";
        cin >> info;
        AddElem(info);
    }
    cout << "List of elements: ";
    PrintList();

    int V1, V2;
    cout << "Enter V1: ";
    cin >> V1;
    cout << "Enter V2: ";
    cin >> V2;
    AddAfterElem(V1, V2);

    cout << "List of elements: ";
    PrintList();

    return 0;
}
