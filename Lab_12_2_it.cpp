#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
    Elem *link;
    Info  info;
};

Elem *first = NULL,
     *last  = NULL;

void enqueue(Elem* &first, Elem* &last, Info value)
{
    Elem *tmp = new Elem; //1
    tmp->info = value;    //2
    tmp->link = NULL;     //3
    if (last != NULL)
        last->link = tmp; //4
    last = tmp;           //5
    if (first == NULL)
        first = tmp;      //6
}

int Count(Elem* L)
{
    int k=0;
    while (L != NULL && L->info % 2 != 0)
    {
        k++;
        L = L->link;
    }
    return k;
}

int main()
{
    Elem* L = new Elem;
    L->info = 1;
    L->link = new Elem;
    L->link->info = 3;
    L->link->link = new Elem;
    L->link->link->info = 5;

    int result_count = Count(L);
    cout << "Count " << result_count << endl;

    return 0;
}
