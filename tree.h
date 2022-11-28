#ifndef TREE_H
#define TREE_H

//=====================================================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <errno.h>

#include "errors.h"

//=====================================================================================================================================

const size_t MaxSize  = 50;
const size_t DeadSize = 0xDED32;

//=====================================================================================================================================

struct node_t
{
    NodeType type;
    Operation operation;

    double num;

    char* item;

    node_t* parent;
    node_t* left;
    node_t* right;
};

struct tree_t
{
    node_t* root;

    size_t size;
};

//=====================================================================================================================================

enum InsMode
{
    LEFT  = 0xF1EF7,
    RIGHT = 0xFFFF7,
};

//=====================================================================================================================================

enum NodeType
{
    TYPE_NULL = 0, 

    OP  = 1,
    VAR = 2,
    NUM = 3,
};

enum Operation
{
    OP_NULL = 0,
    
    ADD = 1,
    SUB = 2,
    MUL = 3,
    DIV = 4,
};

//=====================================================================================================================================

int     TreeCtor            (tree_t* tree);
int     TreeDtor            (tree_t* tree);
bool    isTreeEmpty         (tree_t* tree);
bool    isTreeDestructed    (tree_t* tree);
node_t* CreateNode          (NodeType type, Operation operation, double num, char* item, node_t* left, node_t* right);
node_t* InsertNode          (tree_t* tree, node_t* node, char* item, InsMode insMode);
bool    NodeRemove          (node_t* node);
void    NodeDump            (tree_t* tree, node_t* node, size_t* nodeCount, FILE* file);
void    TreeDump            (tree_t* tree);
node_t* NodeCopy            (node_t* node);

//=====================================================================================================================================

#endif
