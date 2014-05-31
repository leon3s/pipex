/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:05:15 by lverniss          #+#    #+#             */
/*   Updated: 2013/12/02 04:56:00 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFT_H
# define	LIBFT_H

# include	<unistd.h>
# include	<stdlib.h>

void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
char	**ft_strsplit(const char *str, char c);
void	ft_myfree(void *ptr);
void	ft_error(char *msg);

#endif
