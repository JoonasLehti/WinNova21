#include "koodi.h"
#include <iostream>
#include <random>
#include <cmath>
using namespace std;

Koodi::Koodi()
{

    std::mt19937 generator{42};
    std::uniform_real_distribution<double> distribution(-5.0, 5.0);

    const int num_yrityksia = 1000000;
    int num_piste_ympyrassa = 0;

    for (int i = 0; i < num_yrityksia; ++i)
        {
            double x = distribution(generator);
            double y = distribution(generator);
            if (std::sqrt(x*x + y*y) <= 5.0)
            {
                num_piste_ympyrassa++;
            }
        }

    double area_nelion_ala = 100.0;
    double area_ympyran_ala= area_nelion_ala * static_cast<double>(num_piste_ympyrassa) / static_cast<double>(num_yrityksia);
    std::cout << "ympyran ala on " << area_ympyran_ala<< " neliometria." << std::endl;
}
