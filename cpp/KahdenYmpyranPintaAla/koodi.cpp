#include "koodi.h"
#include <iostream>
#include <random>
#include <cmath>

Koodi::Koodi()
{
    std::mt19937 generator{42};
    std::uniform_real_distribution<double> distribution_x(-28.2, 11.8);
    std::uniform_real_distribution<double> distribution_y(-20.0, 20.0);

    const int num_yrityksia = 1000000;
    int num_sininen_piste = 0;

    for (int i = 0; i < num_yrityksia; ++i)
    {
        double x = distribution_x(generator);
        double y = distribution_y(generator);
        double matka_keskelta = std::sqrt(x*x + y*y);

        if (matka_keskelta <= 20.0 && matka_keskelta >= 16.2 && x >= -8.0)
        {
            num_sininen_piste++;
        }
    }

    double nelion_leveys = 40.0;
    double nelion_korkeus = 32.4;
    double nelion_ala = nelion_leveys * nelion_korkeus;
    double sinisen_ympyran_alue = nelion_ala * static_cast<double>(num_sininen_piste) / static_cast<double>(num_yrityksia);

    std::cout << "sinisen alueen koko on " << sinisen_ympyran_alue << " neliometria" << std::endl;
}

