/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:41:13 by rguigneb          #+#    #+#             */
/*   Updated: 2024/10/22 15:10:09 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_in_hex(unsigned long hex)
{
	static char	base[] = "0123456789abcdef";

	if (hex <= 0)
		return ;
	print_in_hex(hex / 16);
	ft_putchar(base[hex % 16]);
}

void	print_address(void *address)
{
	unsigned long	addrs;

	addrs = (unsigned long)address;
	ft_putchar('0');
	ft_putchar('x');
	print_in_hex(addrs);
}

int	main(void)
{
	int	a;

	a = 5;
	printf("%ld\n", (unsigned long)&a);
	printf("%p\n", &a);
	print_address(&a);
}
