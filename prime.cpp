#include <iostream>
bool is_prime(int n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    for (int p = 2; p*p <= n; p++)
    {
        if (n % p == 0) return false;
    }
    return true;
}

int main(void)
{
    int input;
    // Tant que stdin contient des entiers qu'on lit dans input
    // std::endl sert de saut à la ligne et à flush
    // (vider immédiatement) stdout
    while (std::cin >> input && input > 0)
        std::cout << input <<
            (is_prime(input) ? " est premier" : " n'est pas premier") <<
            std::endl;
    return 0;
}