# La mémoire en C



## Organisation de la mémoire d'un programme

#### Définition:

Quand un programme est lancé, le système d'exploitation lui donne un espace mémoire découpé en zones, chacune avec son rôle et ses règles.

#### Fonctionnement:

```
┏——————————————————————————┳————————┳——————————————————————————————————┓
┃ Stack                    ┃        ┃ Heap                             ┃
┃                          ┃        ┃                                  ┃
┃ Variables locales,       ┃        ┃ est alloué avec malloc & co,     ┃
┃ grandit vers le bas      ┃        ┃  grandit vers le haut            ┃
┃                          ┃        ┃                                  ┃
┣——————————————————————————┫        ┣——————————————————————————————————┫
┃ Exemples d'initalisation ┃        ┃ Exemples d'initalisation         ┃
┣——————————————————————————┫        ┣——————————————————————————————————┫
┃                          ┃        ┃                                  ┃
┃ int i                    ┃ espace ┃ pointeur = malloc(taille)        ┃
┃ int number               ┃ libre  ┃ ptr2 = realloc(pointeur, taille) ┃
┃ char *str                ┃        ┃                                  ┃
┃                          ┃        ┃                                  ┃
┃                          ┃        ┃                                  ┃
┃                          ┃        ┃                                  ┃
┃                          ┃        ┃                                  ┃
┃                          ┃        ┃                                  ┃
┃                          ┃        ┃                                  ┃
┃                          ┃        ┃                                  ┃
┗——————————————————————————┻————————┻——————————————————————————————————┛
```



## Stack (la pile)

#### Définition:

C'est la zone mémoire où sont stockées les variables crées dans les fonctions, les arguments et l'adresse de retour de chaque fonction.
Elle est gérée automatiquement par le compilateur (gcc), rapide, mais de taille limitée (entre 1Mo-8Mo, souvent 8 sur Linux). Elle ne permet donc pas de stocker beacoup de donées, et il n'y est pas possible de changer la taille allouée des variable qui y sont stockées

####  Fonctionnement technique:

Chaque appel de fonction crée un "frame" (cadre en français) au sommet de la pile, il est détruit quand la fonction return.
Le stack se vide dans un sens particulier, la dernière fonction appelée et ses varibales sont les premières à être libérées.
Les variables n'existent plus après la fin de leur fonction, il ne faut donc jamais renvoyer l'adresse d'une variable locale,
car elle est libérée après return, et ne devrait plus être lue/modifiée.

#### Fonction exemple:

```
/**
 * main - Fonction d'exemple de crétions de variables
 * dans le frame (cadre de la fonction)
 *
 * Return: 0 quand le programme se termine
 */
int main(void)
{
	int a = 5;	/* Créé dans le frame de f */
	char s[4] = "abc";	/* Aussi dans le frame de f */
	return (0);
}	

/* Frame détruit, les variables et tableaux a et s cessent d'exister */
```



## Heap (le tas)

#### Définition:

C'est la zone de mémoire allouée manuellement par le dev avec malloc, calloc, realloc et libérée avec free grâce à al librairie <stdlib.h>.
Ce type de mémoire est beaucoup plus grande que la stack (la limite est la RAM disponible de l'ordinateur) mais un peu plus lente d'accès.


### Fonctionnement technique:

La fonciton malloc(n) réserve n octets libres (non initalisés par un autre malloc/programme) et renvoie l'adresse du premier,
ou NULL en cas d'échec (pas de place, erreur de la librairie de malloc, bug, etc...).
La mémoire reste réservée jusqu'au free, même après la fin de la fonction qui l'a créée.
Oublier de faire un free créé fuite mémoire (memory leak), et au contraire, la libérer deux fois cause un double free

#### Fonction exemple:

```
/**
 * main - Writes in the heap
 *
 * Return: 0 on success, 1 on malloc failure
 */
int main(void)
{
	int *p;

	p = malloc(sizeof(int) * 3);
	if (p == NULL)
		return (1);
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	free(p);
	p = NULL;	/* Évite un use-after-free */
	return (0);
}



## Écrire dans la Stack vs le Heap

Les deux zones utilisent les mêmes opérateurs (`=`, `[]`, `.`, `->`, `*`), la différence est dans la création, la durée de vie et la libération

Les exemples utilisent la structure de `Structs & Typedef interaction.md`

| Stack (statique/automatique) | Heap (dynamique) |
| --- | --- |
| **Valeur**<br>`int a = 5;`<br>`a = 6;` | **Valeur**<br>`int *p;`<br>`p = malloc(sizeof(int));`<br>`*p = 6;` |
| **Tableau**<br>`int tab[3];`<br>`tab[0] = 1;` | **Tableau**<br>`int *tab;`<br>`tab = malloc(sizeof(int) * 3);`<br>`tab[0] = 1;` |
| **Chaîne modifiable**<br>`char s[] = "abc";`<br>`s[0] = 'A';` | **Chaîne modifiable**<br>`char *s;`<br>`s = malloc(4);`<br>`strcpy(s, "abc");`<br>`s[0] = 'A';` |
| **Structure**<br>`nom_de_structure_incroyable v;`<br>`v.year = 2020;`<br>`strcpy(v.brand, "Fiat");` | **Structure**<br>`nom_de_structure_incroyable *v;`<br>`v = malloc(sizeof(*v));`<br>`v->year = 2020;`<br>`strcpy(v->brand, "Fiat");` |
| **Taille**<br>Connue à la compilation (pas de `int tab[n]` en GNU89 portable) | **Taille**<br>Choisie à l'exécution, modifiable avec `realloc` |
| **Libération**<br>Automatique à la fin du bloc/de la fonction | **Libération**<br>Manuelle:<br>`free(v);`<br>`v = NULL;` |
| **Durée de vie**<br>Jusqu'au `return` de la fonction | **Durée de vie**<br>Jusqu'au `free` (ou la fin du programme) |
| **Taille max**<br>Petite (~8 Mo) | **Taille max**<br>Grande (limitée par la RAM) |
| **Erreur typique**<br>Stack overflow | **Erreur typique**<br>Fuite mémoire, double free, use-after-free |

Pour une valeur de retour qui doit survivre à la fonction, la mémoire doit être sur le Heap (ou fournie par l'appelant)

```
/**
 * bon - Returns a string that survives the function
 *
 * Return: Pointer to a heap string, NULL on failure
 */
char *bon(void)
{
	char *s;

	s = malloc(5);
	if (s == NULL)
		return (NULL);
	strcpy(s, "ok");
	return (s);	/* L'appelant devra faire free */
}

char *mauvais(void)
{
	char s[] = "oups";

	return (s);	/* Stack détruite au return: comportement indéfini */
}
```

## Stack overflow

Définition:

Erreur qui arrive quand la stack dépasse sa taille maximale, le programme est alors tué par l'OS (souvent affiché comme un segfault)

Fonctionnement:

Deux causes principales: une récursion sans fin (ou trop profonde) ou un très gros tableau local

```
/**
 * recurse - Never ends, each call adds a frame to the stack
 * @n: Counter
 *
 * Return: Never returns normally
 */
int recurse(int n)
{
	char tab[1024];

	tab[0] = n;
	return (recurse(n + 1) + tab[0]);
}

int main(void)
{
	int gros[10000000];	/* ~40 Mo sur une stack de 8 Mo */

	gros[0] = 1;
	return (recurse(0));
}
```

Solution: ajouter une condition d'arrêt, ou allouer les gros tableaux sur le Heap avec `malloc`

## Segfault

Définition:

Segmentation fault: l'OS tue le programme car il a essayé d'accéder à une zone mémoire interdite (inexistante ou en lecture seule)

Fonctionnement:

Causes les plus courantes, avec un exemple chacune:

```
char *s = "Hello";
int *p = NULL;
int tab[3];
int *h;

s[0] = 'h';	/* Écriture dans .rodata (lecture seule) */
*p = 1;	/* Déréférencement de NULL */
tab[100000] = 1;	/* Hors limites, trop loin de la stack */

h = malloc(sizeof(int));
free(h);
*h = 1;	/* Use-after-free */
```

Pour modifier une chaîne, il faut une copie modifiable: `char s[] = "Hello";` (Stack) ou `malloc` + `strcpy` (Heap)
`NULL` est toujours à vérifier après un `malloc`, et un pointeur libéré doit être remis à `NULL`
Les outils `valgrind` et `gcc -g` aident à trouver la ligne fautive

## Résumé: quelle mémoire choisir

Stack par défaut: simple, rapide et libérée toute seule
Heap si la taille est inconnue à la compilation, trop grosse pour la stack, ou si la donnée doit survivre à la fonction
Statique pour une donnée qui vit pendant tout le programme
Chaque `malloc` doit avoir un `free`
