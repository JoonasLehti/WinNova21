#include "koodi.h"
#include <iostream>
#include <random>
#include <cmath>

Koodi::Koodi()
{
    std::mt19937 generator{42};
    std::uniform_real_distribution<double> distribution_x(-20.0, 20.0);
    std::uniform_real_distribution<double> distribution_y(-20.0, 20.0);

    const int num_yrityksia = 1000000;
    int num_sininen_piste = 0;

    for (int i = 0; i < num_yrityksia; ++i)
    {
        double x = distribution_x(generator);
        double y = distribution_y(generator);
        double matka_keskelta1 = std::sqrt(x*x + y*y);
        double matka_keskelta2 = std::sqrt((x-8)*(x-8) + y*y);

        if (matka_keskelta1 <= 20.0 && matka_keskelta2 > 16.2)
        {
            num_sininen_piste++;
        }
    }

    double nelion_leveys = 40.0;
    double nelion_korkeus = 40.0;
    double nelion_ala = nelion_leveys * nelion_korkeus;
    double sinisen_ympyran_alue = nelion_ala * static_cast<double>(num_sininen_piste) / static_cast<double>(num_yrityksia);

    std::cout << "Sinisen alue on " << sinisen_ympyran_alue << " neliometria" << std::endl;
}
