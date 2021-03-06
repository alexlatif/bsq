/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:30:04 by alatif            #+#    #+#             */
/*   Updated: 2018/11/13 23:30:07 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "strings.h"

char	*ft_realloc(char *str, char c, int width)
{
	char	*temp;

	temp = malloc(sizeof(char) * (width + 1));
	temp = ft_strcpy(temp, str, width - 1);
	temp[width - 1] = c;
	temp[width] = '\0';
	return (temp);
}
