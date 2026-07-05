/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleca <kleca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 15:43:35 by ajouffre          #+#    #+#             */
/*   Updated: 2026/07/05 15:57:51 by kleca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

// fonction  qui va afficher la premiere et derniere ligne horizontale du carre
// la variable s donnee a cette fonction lui indique si c'est la premiere (0) ou derniere (1) ligne, qu'elle doit ecrire
void	ft_hline(int x, int s)
{
	int	i;

	i = 2;
	if (s == 0) // si c'est la premiere ligne, on commence par afficher un '/'
		ft_putchar('/');
	else // sinon, c'est la derniere ligne et on affiche un '\'
		ft_putchar('\\'); // il y a ici 2 '\' car en c, un seul '\' est utilise pour annuler la fonction du caractere precedent. s'il n'y avait qu'un slash, le code annulerait l'apostrophe suivant et le code ne fonctionnerait pas
	while (i < x) // cette boucle remplit le reste de la ligne (sauf le dernier caractere) par des *
	{
		ft_putchar('*');
		i++;
	}
	if (i == x) // une fois arrive a la derniere ligne, on affiche:
	{
		if (s == 0)
			ft_putchar('\\'); // soit '\' si c'est la premiere ligne
		else
			ft_putchar('/'); // soit '/' si c'est la derniere ligne
	}
	ft_putchar('\n'); // il faut faire un retour a la ligne a la fin de la ligne affichee
}

void	ft_vline(int x) // cette fonctione ecrit une ligne horizontale pour fomer les lignes verticales du carre: |     | ou dans ce cas *    *
{
	int	i;

	i = 2;
	ft_putchar('*'); // qund on utilise cette fonction c'est qu'on a besoin de cotes verticaux du carre, donc on dessine focement le premier caractere 
	while (i < x) // on met des espaces jusqu'a atteindre la derniere colone
	{
		ft_putchar(' ');
		i++;
	}
	if (i == x) // si on est a la derniere colonne, on dessine le deuxieme '*'
		ft_putchar('*');
	ft_putchar('\n'); // on ecrit le caractere de retour a la ligne pour gue la ligne suivant soit ecrite en dessous
}

// fonction pour construire le carre
void	rush(int x, int y)
{
	int	i;

	i = 2;
	if (x > 0 && y > 0) // on verifie d'abord que x et y ne soient pas a zero ou moins, si c'est le cas, aucune autre action n'est declenchee
	{
		ft_hline(x, 0); // on lance obligatoirement ft_hline une fois, pour faire la premiere ligne du carre qui existe forcement		
		while (i <= y) // ce while permet d'afficher le milieu et la fin du carre si on donne une hauteur de plus de 1
		{
			if (i < y) // tant qu'on n'a pas atteint la derniere ligne du carre, le if se declenche pour afficher les lignes avec ft_vline, qui remplit avec des lignes verticales
				ft_vline(x);
			else // une fois qu'on est a la derniere, le else se declenche et on utilise ft_hline pour afficher la dermiere ligne
				ft_hline(x, 1);
			i++; // on incremente pour rajouter les lignes jusqu'a atteindre la derniere
		}
	}
}
