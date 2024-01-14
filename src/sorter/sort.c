/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:56 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 15:13:34 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort(t_stacks **stacks)
{
	if (is_sorted((*stacks)->a))
		return ;
	if ((*stacks)->a->size <= 5)
		sort_tiny(stacks);
	else
		sort_large(stacks);
}
