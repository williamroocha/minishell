/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:17:43 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/09 14:21:52 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	if (!s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}
