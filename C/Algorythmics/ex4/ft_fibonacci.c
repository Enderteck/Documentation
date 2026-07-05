/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouffre <ajouffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:36:06 by ajouffre          #+#    #+#             */
/*   Updated: 2026/07/05 19:17:31 by ajouffre         ###   ########.fr       */
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

int	ft_fibonacci(int index)
{
	static int	i = 1;
	static int	first = 0;
	static int	second = 1;
	int	result;

	if (index <= 0)
	{
		if (index < 0)
			return (-1);
		else
			return (0);
	}	
	result = first + second;
	first = second;
	second = result;
	i++;
	if (i < index)
	{
		return (ft_fibonacci(index));
	}
	return (result);
}

int	main(void)
{
	ft_putnbr(ft_fibonacci(8));
	return (0);
}
