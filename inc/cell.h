#pragma once
#ifndef CELL_H
#define CELL_H
#include <stdbool.h>
#include <stdlib.h>

#include "env.h"

typedef enum cell_around
{
  top = 0,
  right_top,
  right,
  right_buttom,
  buttom,
  left_buttom,
  left,
  left_top,
} cell_around_t;

typedef struct cell
{
  struct cell** cell_around;

  char icon;
  bool contains_mine;
  bool activated;
} cell_s;

cell_s* 
alloc_cell(
    bool contains_mine,
    char icon
);

void
free_cell(
    cell_s *cell
);

void
tying_cell(
    cell_s *dest,
    cell_s *src,
    cell_around_t where
);

#endif /* CELL_H */
