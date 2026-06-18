#ifndef MUXCHCOUNT
#define MUXCHCOUNT 4
#endif
#ifndef DRIVEPINS
#define DRIVEPINS 8
#endif

#ifdef matrixPos
#include <btpv_matrix.h>
const MatrixPosition transformMap[MATRIX_ROWS][MATRIX_COLS] = {{{1, 1}, {2, 1}, {4, 3}, {4, 1}}, {{0, 2}, {4, 2}, {1, 0}, {6, 0}}, {{1, 2}, {5, 2}, {2, 0}, {5, 1}}, {{2, 2}, {6, 2}, {3, 0}, {7, 0}}, {{3, 2}, {7, 2}, {4, 0}, {6, 1}}, {{0, 0}, {7, 1}, {5, 0}, {0, 1}}};
#endif
