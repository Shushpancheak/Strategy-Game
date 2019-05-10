#pragma once

/**
 * \brief Used in GraphicComponent to tell which part of Composite tree
 * should be drawn.
 */
enum DrawVariant {
  kAll,
  kOnlyThis,
  kOnlyChildren,
  kNothing
};