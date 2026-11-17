# Typedef

## Définition:

Permet de créer des alias pour des types de variables.
Après avoir définit un typedef, le nouveau nom donnée référencera tout ce qui est écrit avant (entre typedef & le nouveau nom)

Dans un .h ou dans une fonction:
```c
/**
 * <nom_sans_espaces> - Explication du typedef & son utilisation
 */
typedef <truc(s) avec ou sans espaces> <nom_sans_espaces>;
```

Maintenant dans le code:

<nom_sans_espaces> corespond à <truc avec/sans espaces>

Exemples de typedefs utiles:

```c
/**
 * String - Définition d'une String comme un pointeur de char
 */
typedef char * String;
 
/**
 * size_t - Définition de la variable size_t
 * comme un nombre entier sans signe
 */
typedef unsigned int size_t;
 
/**
 * var_de_ouf - Définition de ma super variable var_de_ouf
 * en tant que long long int (G)
 */
typedef long long int var_de_ouf;
```

Var_de_ouf est doranévant une variable long long int dans le code

