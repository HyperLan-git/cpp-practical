#include <vector>

#include <iostream>

// Vu que je suis un sauvage go variable globale
// en gros c'est la variable qui contiendra tous les premiers
std::vector<int> primes = {2, 3};

using int_iter = std::vector<int>::iterator;

void fill_table(int max_value)
{
    // là je récupére la dernière valeur du vector
    auto reverseiter = primes.rbegin();
    // un iterator tu peux ++ -- ou alors * ou [] (comme un pointeur en fait)

    int last = *(primes.rbegin()); 
    if (max_value < last) return;

    // Si je dois remplir plus la table des premiers je rajoute
    for (int i = last + 1; i <= max_value; i++)
        primes.push_back(i);

    // Puis je filtre
    // ce for donne chaque élément séquenciellement
    for (int_iter iter = primes.begin(); iter != primes.end(); iter++)
    {
        int nb = *iter;
        for (int_iter iter2 = iter + 1; iter2 != primes.end(); iter2++)
        {
            if (*iter2 % nb == 0)
            {
                iter2 = primes.erase(iter2);
                iter2--;
            }
        }
    }
}

/**
 * L'intérêt de cet algorithme est d'avoir une complexité en n
 * si nous avons déjà rempli le tableau des nombres premiers
 */
bool is_prime(int n)
{
    // Si notre liste de nombres premiers n'est pas assez grande
    // Remplir jusqu'à n
    if (n > *(primes.rbegin()))
        fill_table(n);

    // Pour chaque élément dans primes si 
    for (int_iter iter = primes.begin(); iter != primes.end(); iter++)
    {
        if (*iter == n)
            return true;

        if (*iter > n)
            return false;
    }
    return false;
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