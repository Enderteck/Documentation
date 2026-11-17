# Structs

## Définition:

Une struture est un modèle qui permet de regrouper plusieurs types de varibles dans une seule grande variable. On doit la définir (dans notre norme, toujours dans les .h).

Voici coment on les définit (commentaire Betty inclus en haut):
```
/**
 * nom - Écrire ici ce que va stocker la structure
 * @str: Écrire à quoi sert cette suite de charactères
 * @anée: Écrire ici à quoi sert cette variable
 *
 * Description: Celle ligne est faculatative mais
 * permet d'expliquer plus en détails
 */
struct nom
{
	char str[30];
	int année;
};
```

Pour l'utiliser, il faut ensuite en créer une structure avec un modèle définit et un nouveau nom .


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

## Exeption

Si la variable est un tableau ou une suite de charactères, on ne peut pas les redéfinir, car les tableaux ne peuvent pas être copiés avec l'opérateur = une fois déclarés.
On utilise alors strcpy (pour les suites de charactères) & memcpy (pour toutes les tailles de variables).