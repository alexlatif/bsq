/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:29:20 by alatif            #+#    #+#             */
/*   Updated: 2018/11/13 23:29:24 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "puts.h"
#include "binfo.h"

void	ft_exit(char *message, t_board *binfo)
{
	if (!binfo->error)
		ft_putstr(message);
	if (binfo)
		binfo->error = 1;
}
