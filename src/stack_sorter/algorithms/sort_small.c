/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:52:29 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/25 18:55:40 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ex. stack_a = {2, 1}
void	sort_two_numbers(t_stack *stack_a)
{
	int	first_number;
	int	second_number;

	first_number = stack_a->top_node->stored_number;
	second_number = stack_a->top_node->next_node->stored_number;
	if (first_number > second_number)
		swap_in_a(stack_a);
}

/* ex.
	case 1. stack_a = {2, 1, 3}
	case 2. stack_a = {3, 1, 2}
	case 3. stack_a = {2, 3, 1}
	case 4. stack_a = {1, 3, 2}
	case 5. stack_a = {3, 2, 1}
*/
void	sort_three_numbers(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->top_node->stored_number;
	second = stack_a->top_node->next_node->stored_number;
	third = stack_a->top_node->next_node->next_node->stored_number;
	if (first > second && second < third && first < third)
		swap_in_a(stack_a);
	else if (first > second && second < third && first > third)
		rotate_in_a(stack_a);
	else if (first < second && second > third && first > third)
		reverse_in_a(stack_a);
	else if (first < second && second > third && first < third)
	{
		swap_in_a(stack_a);
		rotate_in_a(stack_a);
	}
	else if (first > second && second > third)
	{
		swap_in_a(stack_a);
		reverse_in_a(stack_a);
	}
}

/**
 * @brief sorting four or five integers.
 * @note find_min_position()<-sort_utils.c
 */
void	sort_four_five(t_stack *stack_a, t_stack *stack_b)
{
	int	target_position;

	while (stack_a->total_nodes > 3)
	{
		target_position = find_position_of_minimum(stack_a);
		while (target_position != 1)
		{
			move_node_to_top(stack_a, target_position);
			target_position = find_position_of_minimum(stack_a);
		}
		push_head_from_a_to_b(stack_a, stack_b);
	}
	sort_three_numbers(stack_a);
	while (stack_b->total_nodes > 0)
		push_node_from_b_to_a(stack_a, stack_b);
}
