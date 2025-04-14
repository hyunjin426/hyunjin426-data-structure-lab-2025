#include "sparsepoly.hpp"

int main() {
    SparsePoly A, B, C;

    A.read();
    A.display("Poly A: ");

    B.read();
    B.display("Poly B: ");

    C.add(A, B);
    C.display("Poly C: ");

    return 0;
}
