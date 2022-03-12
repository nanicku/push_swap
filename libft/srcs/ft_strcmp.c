/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:57:13 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 14:57:14 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
		if (!*s1++ || !*s2++)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}