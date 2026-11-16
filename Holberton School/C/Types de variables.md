# Les types de variables

## Char:

Définition:

Stocke une valeur, souvent utilisée pour un charactère de la table ascii
Prends 1 octet (8 bits) de place dans la mémoire
Peut représenter des nombres de  -128 à 127

Fonctionnement:

Le premier bit (le plus à gauche) est égal à -128 et pas 128, pour représenter les nombres négatifs
Exemples en mémoire (bits), en ordre croissant:

```
Valeur:   -128  64 32  16   8   4   2   1
			1   0   0   0   0   0   0   0		= -128 en décimal
			1   0   0   0   0   0   0   1		= -127 en décimal
			1   1   1   1   1   1   1   1		= -1 en décimal
			0   0   0   0   0   0   0   0		= 0 en décimal
			0   0   0   0   0   0   0   1		= 1 en décimal
			0   1   1   1   1   1   1   1		= 127 en décimal
```

## Unsigned char:

Définition:

Stocke une valeur, souvent utilisée pour un charactère de la table ascii étendue, ne put pas stocker de valeur négatives
Prends 1 octet (8 bits) de place dans la mémoire
Peut représenter des nombres de  0 à 255

Fonctionnement:

Le premier bit (le plus à gauche) est égal à -128 et pas 128, pour représenter les nombres négatifs
Exemples en mémoire (bits), en ordre croissant:

```
Valeur:    128  64 32  16   8   4   2   1
			0   0   0   0   0   0   0   0		= 0
			0   0   0   0   0   0   0   1		= 1
			0   0   0   1   0   0   0   0		= 16
			0   1   1   1   1   1   1   1		= 127
			1   0   0   0   0   0   0   0		= 128
			1   1   1   1   1   1   1   1		= 255
```

## Int

Définition:

Stocke un nombre entier
Prends 4 octet (32 bits) de place dans la mémoire
Peut représenter des nombres de -2147483648 à 2147483647

Fonctionnement:

Le premier bit (le plus à gauche) est égal à -2147483648 et pas 2147483647 cela sert à représenter les nombres négatifs
Exemples en mémoire (bits), en ordre croissant:

```
Valeur:-2147483648 1073741823 536870911 [...] 4 2 1
			 1          0          0          0 0 0 = -2147483648
			 1          1          0          0 0 1 = -2147483647
			 1          1          0          0 1 1 = -2147483645
			 1          1          1   [25x1] 1 1 1 = -1
			 1          1          1          0 1 1 = 0
			 0          0          0          0 0 1 = 1
			 0          0          0          0 1 0 = 2
			 0          0          1          0 0 0 = 536870911
			 0          0          1          0 1 1 = 536870913
			 0          1          1   [25x1] 1 1 1 = 2147483647
```

### Unsigned int

Définition:

Stocke un nombre entier
Prends 4 octet (32 bits) de place dans la mémoire
Peut représenter des nombres de -2147483648 à 2147483647

Fonctionnement:

Le premier bit (le plus à gauche) est égal à -2147483648 et pas 2147483647 cela sert à représenter les nombres négatifs
Exemples en mémoire (bits), en ordre croissant:

```
Valeur:-2147483648 1073741823 536870911 [...] 4 2 1
			 0          0          0          0 0 0 = 0
			 0          0          0          0 0 1 = 1
			 0          0          0          0 1 0 = 2
			 0          0          0          0 1 1 = 3
			 0          0          1          0 1 1 = 536870913
			 0          1          1   [25x1] 1 1 1 = 2147483647
			 1          1          1   [25x1] 1 1 1 = 4294967295
```


