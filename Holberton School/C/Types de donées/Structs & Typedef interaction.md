# Structs & Typedef

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

