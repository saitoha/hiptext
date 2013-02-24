#include "graphic.h"
#include <cmath>
#include <algorithm>

Graphic Graphic::BilinearScale(int new_width, int new_height) {
  Graphic res(new_width, new_height);
  double rx = (double)width_ / (double)res.width_;
  double ry = (double)height_ / (double)res.height_;
  for (int y = 0; y < res.height_; ++y) {
    for (int x = 0; x < res.width_; ++x) {
      double sx = x * rx;
      double sy = y * ry;
      int xl = std::min((int)std::floor(sx), width_ - 1);
      int xr = std::min((int)std::floor(sx + 1), width_ - 1);
      int yt = std::min((int)std::floor(sy), height_ - 1);
      int yb = std::min((int)std::floor(sy + 1), height_ - 1);
      const Pixel& tl = Get(xl, yt);
      const Pixel& tr = Get(xr, yt);
      const Pixel& bl = Get(xl, yb);
      const Pixel& br = Get(xr, yb);
      res.Get(x, y) = Pixel((tl.r + tr.r + bl.r + br.r) / 4,
                            (tl.g + tr.g + bl.g + br.g) / 4,
                            (tl.b + tr.b + bl.b + br.b) / 4,
                            (tl.a + tr.a + bl.a + br.a) / 4);
    }
  }
  return res;
}

// For Emacs:
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:2
// c-basic-offset:2
// c-file-style: nil
// End:
// For VIM:
// vim:set expandtab softtabstop=2 shiftwidth=2 tabstop=2:
