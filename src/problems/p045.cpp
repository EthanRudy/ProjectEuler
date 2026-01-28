#include "../problems.hpp"
#include "../utils.hpp"


unsigned long long solve_p045() {
    int i = 143 + 1;
    while (true) {
        unsigned long long hex = nth_hex_number(i);
        if (is_pent_number(hex) && is_tri_number(hex))
        {
            return hex;
        }

        ++i;
    }
}