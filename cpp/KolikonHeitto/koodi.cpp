#include "koodi.h"
#include <random>
#include <iostream>

koodi::koodi()
{
    std::mt19937 generator{ 42 };
    std::uniform_int_distribution<int> distribution(0, 1);

    const int num_yrityksia = 1000000;
        int num_perkkaiset_klaavat = 0;
        int num_perkkaiset_kruunat = 0;
        int num_kymmenen_perkkaiset_klaavat = 0;
        int num_kymmenen_perkkaiset_kruunat = 0;

        for (int i = 0; i < num_yrityksia; ++i)
        {
            int result = distribution(generator);
            if (result == 0)
            {
                num_perkkaiset_klaavat++;
                num_perkkaiset_kruunat = 0;
                if (num_perkkaiset_klaavat == 10)
                {
                    num_kymmenen_perkkaiset_klaavat++;
                    num_perkkaiset_klaavat = 0;
                }
            }
            else
            {
                num_perkkaiset_kruunat++;
                num_perkkaiset_klaavat = 0;
                if (num_perkkaiset_kruunat == 10)
                {
                    num_kymmenen_perkkaiset_kruunat++;
                    num_perkkaiset_kruunat = 0;
                }
            }
        }

        double probability = static_cast<double>(num_kymmenen_perkkaiset_klaavat) / (num_kymmenen_perkkaiset_klaavat + num_kymmenen_perkkaiset_kruunat);
        std::cout << "mahdollisuus saada 10 klaavaa perakkain: " << probability << std::endl;
}
