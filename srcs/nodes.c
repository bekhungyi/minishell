/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:49:08 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/15 22:36:22 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_commandnode *init_command_node(t_promt *promt)
{
    t_commandnode *node = malloc(sizeof(t_commandnode));
    char arr[] = {"ls", ""};

    if (!node) {
        perror("Error allocating memory for CommandNode");
        exit(EXIT_FAILURE);
    }

    node->base.type = COMMAND_NODE;
    node->command = 0;
}

t_node *init_node(t_promt *promt)
{
    int i;
    t_node *node;

    i = 0;
    node = malloc(sizeof(t_node));
    if (!node) {
        perror("Error allocating memory for Node");
        exit(EXIT_FAILURE);
    }
    if (promt->has_pipe == 1)
        init_pipe_node(promt);
    
    
    return (node);
}



t_node *new_node(enum NodeType type)
{
    t_node *node;
    
    node = malloc(sizeof(t_node));
    if(!node)
        return NULL;
    
    // memset(node, 0, sizeof(struct node_s));
    node->type = type;
    
    return node;
}
