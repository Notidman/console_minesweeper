#pragma once
#ifndef PAINTER_H
#define PAINTER_H
#include "field.h"

void 
draw_field_with_mines(
  field_s *field);

void
draw_field(
    field_s *field);

void
clrscr(void);

#endif /* PAINTER_H */
