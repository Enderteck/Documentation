/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouffre <ajouffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 18:55:59 by ajouffre          #+#    #+#             */
/*   Updated: 2026/07/05 18:30:29 by ajouffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long long	number;

	number = nb;
	if (number < 0)
	{
		ft_putchar('-');
		number = -number;
	}
	if (number > 9)
	{
		ft_putnbr(number / 10);
		number %= 10;
	}
	ft_putchar(number + 48);
}

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	a;

	i = 1;
	a = 1;
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		return (1);
	}
	while (i <= nb)
	{
		a = a * i;
		i++;
    }
	return (a);
}

int	main(void)
{
	ft_putnbr(ft_iterative_factorial(5));
	return (0);
}
