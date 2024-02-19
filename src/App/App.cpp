// komorebi.cpp : Defines the entry point for the application.
//

#include "Komorebi.h"
#include <iostream>

using namespace std;
using namespace komorebi;

void test(float3 &v)
{
    v[0] += 1;
}

int main()
{
    float3 o{0, 0, 0};
    float3 d{1, 0, 1};

    for (auto v : o.m_values)
    {
        cout << v << endl;
        cout << linearPDF(.4, 0., 1.) << endl;
    }
    test(o);
    for (auto v : o.m_values)
        cout << v << endl;
    return 0;
}
