#include <stdio.h>
#include <stdlib.h>
#include "sparseMatrix.h"

sparseMatrix* createSparseMatrix(int row, int col) {
    return createArrayList(row * col);
}

int addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value) {
    int size;
    size = sizeArrayList(sm);

    // 수정: 결과 반환 추가
    return insertArrayList(sm, size, (elementArrayList) { row, col, value });
}

int printSparseMatrix(sparseMatrix* sm) {
    printf("Sparse Matrix: \n");
    printArrayList(sm);

    return 1; // 수정: 반환값 추가
}

sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2) {
    sparseMatrix* smResult = createArrayList(100);

    // 수정: <= → < (배열 범위 초과 방지)
    for (int i = 0; i < sizeArrayList(sm1); i++) {
        elementArrayList nonZeroOfSM1 = getItemArrayList(sm1, i);
        int j;

        // 수정: <= → <
        for (j = 0; j < sizeArrayList(sm2); j++) {
            elementArrayList nonZeroOfSM2 = getItemArrayList(sm2, j);

            if (nonZeroOfSM1.col == nonZeroOfSM2.col &&
                nonZeroOfSM1.row == nonZeroOfSM2.row) {

                insertArrayList(smResult, sizeArrayList(smResult),
                    (elementArrayList) {
                    nonZeroOfSM1.row,
                        nonZeroOfSM1.col,
                        nonZeroOfSM1.value + nonZeroOfSM2.value
                });

                break;
            }
        }

        if (j == sizeArrayList(sm2)) {
            insertArrayList(smResult, sizeArrayList(smResult), nonZeroOfSM1);
        }
    }

    return smResult;
}