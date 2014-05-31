/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:11:05 by lverniss          #+#    #+#             */
/*   Updated: 2013/11/30 14:30:10 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libc.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = s;
	while (n--)
		tmp[n] = 0;
}
