#include "Shape.h"

class ShapesContainer {
  Shape** shapes;
  unsigned shapes_count;

  void do_copy(ShapesContainer const& other);
  void do_delete();
public:
  ShapesContainer(Shape* shapes[], unsigned shapes_count);
  ShapesContainer(ShapesContainer const& other);
  ShapesContainer& operator=(ShapesContainer const& other);
  ~ShapesContainer();

  unsigned get_shapes_count() const;
  Shape* get_shape_at(unsigned index) const;
  void print_largest() const;
};
