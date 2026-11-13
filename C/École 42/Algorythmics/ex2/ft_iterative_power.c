/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouffre <ajouffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:36:06 by ajouffre          #+#    #+#             */
/*   Updated: 2026/07/05 18:26:38 by ajouffre         ###   ########.fr       */
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

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	a;

	a = nb;
	i = 1;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		if (nb < 0)
			return (-1);
		else
			return (1);
	}
	while (i < power)
	{
		nb = a * nb;
		i ++;
	}
	return (nb);
}

int	main(void)
{
	ft_putnbr(ft_iterative_power(2, 2));
	return (0);
}
