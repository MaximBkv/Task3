#include<cstdlib>
#include<cstring>
#include <iostream>
#include <string>
using namespace std;
struct polynom
{
    int deg;
    int coef;
    polynom* next;
};
typedef polynom* Pointer;
Pointer Head = NULL;
int M = 0;
void input()
{
    Pointer NewEl = NULL;
    int i, k = 0;
    char pol[100], p[100];
    cout << "vvedite polynom: ";
    cin >> pol;
    int N = strlen(pol);
    for (i = 0; i <N; i++)
    {
        if ((i != N - 1) && (pol[i] != 'x') && (pol[i] != '^') && (pol[i] != '+') && (pol[i] != '-'))
        {
            p[k] = pol[i];
            k++;
        }
        else if (pol[i] == 'x')
        {
            p[k] = '\0';
            k = 0;
            NewEl = new polynom;
            NewEl->coef = atof(p);
            NewEl->next = Head;
            Head = NewEl;
            M++;
        }
        else if ((i == N - 1) || (pol[i] == '+') || (pol[i] == '-'))
        {
            if (i == N - 1)
            {
                p[k] = pol[i];
                k++;
            }
            p[k] = '\0';
            k = 1;
            if (NewEl)
                NewEl->deg = atof(p);
            p[0] = pol[i];
        }
    }
}
void Gornir(Pointer q)
{
    string s = to_string(q->coef);
    s += "x";
    if (q->next != NULL) {

        while (q->next->next != NULL) {
            for (int i = q->next->deg; i < q->deg-1; i++) {
               s = "(" + s + ")x";
            }
            s = s + " + " + to_string(q->next->coef);
            q = q->next;
        }
        for (int i = q->next->deg; i < q->deg - 1; i++) {
            s = "(" + s + ")x";
        }
        s = "(" + s + ")x";
        s = s + " + " + to_string(q->next->coef);
        for (int i = 0; i < q->next->deg; i++) {
            s = "(" + s + ")x";
        }
    }
    cout << s;
}

int main()
{
    input();
    cout << "\nPolynom: ";
    Gornir(Head);
}