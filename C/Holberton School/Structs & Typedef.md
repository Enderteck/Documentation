# Structs & Typedef

## Structs

```
/**
 * struct dog - Stores info related to a dog
 * @name: Dog name
 * @age: Dog's age
 * @owner: Owner's name
 *
 * Description: Stores information about a dog, very useful in everyday life
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
```

## Typedef

Permet de créer des alias pour des types de variables & des variables custom

Création:

Dans un .h ou dans une fonction ou non d’un .c, faire:

```
typedef <truc avec/sans espaces> <petit_nom_sans_espaces>;
```

Maintenant dans le code:
petit_nom_sans_espaces = truc avec/sans espaces

Exemples de typedefs utiles:

```
/**
 * u_int - Typedef String
 */
typedef char * String;
 
/**
 * size_t - Typedef for unsigned int
 */
typedef unsigned int size_t;
 
/**
 * var_de_ouf - Typedef for long long int
 */
typedef long long int var_de_ouf;
```

Var_de_ouf est doranévant une variable long long int dans le code

## Structs & Typedef

```
typedef struct
{
	char brand[30];
	int year;
} nom_de_structure_incroyable;
```

Crée une structure avec le format définit avec typedef

```
nom_de_structure_incroyable nom_struct
 
nom_de_structure_incroyable *structaddress;
 
structaddress = &nom_struct
```
 
Accéder & modifier ce qui est stocké dans notre struct

```
nom_struct.var
(*Structaddr).var
 
Structaddr->var
(&nom_struct)->var
```

