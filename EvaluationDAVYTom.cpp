/*
--- Exercice 1 ---

1. La console affiche : 10, 1, 200

2. La console affiche : 2

3. b1 = false, b2 = false, b3 = false et b4 = true

4. La console affiche : Invalid operation
                        X: 8, Y: 0

--- Exercice 2 ---

1. La console affiche : 3, 2, 1

2. Le code ne fonctionne pas correctement car la variable isMultiple n'est pas mise à jour dans la boucle, la boucle While va tourner en boucle en incrémentant "a" isMultiple ne passera jamais a true car il n'est pas mis à jour
Correction :
while (!isMultiple) {
    a++;
    isMultiple = (b % a) == 0;
}

--- Exercice 3 ---

1. La console affiche : 4

4. La console affiche : 1, 2, 3, 11

3. La console affiche : 3

*/


// --- Exercice 4 ---
#include <iostream>

struct Saiyan
{
    std::string name;
    std::string prefix;
    std::string suffix;
    int power;
};

Saiyan PerformFusion(Saiyan saiyanA, Saiyan saiyanB, bool isFusionSucceed)
{
    Saiyan strongestSaiyan;
    Saiyan weakestSaiyan;
    Saiyan FusionnedSaiyan;

    if (saiyanA.power >= saiyanB.power)
    {
        strongestSaiyan = saiyanA;
        weakestSaiyan = saiyanB;
    }
    else
    {
        strongestSaiyan = saiyanB;
        weakestSaiyan = saiyanA;
    }

    if (isFusionSucceed)
    {
        FusionnedSaiyan.prefix = strongestSaiyan.prefix;
        FusionnedSaiyan.suffix = weakestSaiyan.suffix;

        FusionnedSaiyan.power = strongestSaiyan.power + weakestSaiyan.power;

        FusionnedSaiyan.name = FusionnedSaiyan.prefix + FusionnedSaiyan.suffix;
        if (FusionnedSaiyan.power > 9000)
        {
            std::cout << FusionnedSaiyan.name << " : IT'S OVER 9000 !!!!" << std::endl;
        }
        
    }
    else
    {
        FusionnedSaiyan.prefix = weakestSaiyan.prefix;
        FusionnedSaiyan.suffix = strongestSaiyan.suffix;

        FusionnedSaiyan.power = 1;

        FusionnedSaiyan.name = FusionnedSaiyan.prefix + FusionnedSaiyan.suffix;
    }

    return FusionnedSaiyan;
}

int main()
{
    Saiyan goku = { "goku", "go", "ku", 5000 };
    Saiyan vegeta = { "vegeta", "ve", "geta", 4001 };
    Saiyan goten = {"goten", "goten", "ten", 3001}; // J'ai mis goten en prefix uniquement pour que le nom corresponde a la réalité
    Saiyan trunks = {"trunks", "trun", "ks", 3000};

    Saiyan veku = PerformFusion(goku, vegeta, false);
    Saiyan gogeta = PerformFusion(goku, vegeta, true);

    std::cout << veku.name << " a une puissance de : " << veku.power << std::endl;
    std::cout << gogeta.name << " a une puissance de : " << gogeta.power << std::endl;

    Saiyan gotenks = PerformFusion(trunks, goten, true);
    std::cout << gotenks.name << " a une puissance de : " << gotenks.power << std::endl;
}