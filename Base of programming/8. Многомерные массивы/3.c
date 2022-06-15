#include <stdio.h>

#define SIZE_LIMIT 200


double solve_system_of_linear_equations(double system_matrix[SIZE_LIMIT][SIZE_LIMIT], const double free_terms[SIZE_LIMIT],
                                        int size_of_matrix) {


    int fixed_row = 0, fixed_column_consists_of_zeros, not_zero_elem_idx_in_fixed_column, diag_element;
    double first_elem_of_fixed_column, not_zero_elem_of_fixed_column, transvection_alpha, row_multiplier,
            system_solution[SIZE_LIMIT] = {0}, reverse_system_matrix[SIZE_LIMIT][SIZE_LIMIT] = {0};

    for (int diag_elem = 0; diag_elem < size_of_matrix; ++diag_elem) {
        reverse_system_matrix[diag_elem][diag_elem] = 1;
    }

    for (int fixed_column = 0; fixed_column < size_of_matrix; ++fixed_column) {

        fixed_column_consists_of_zeros = 1;
        for (int row = fixed_row; row < size_of_matrix; ++row) {
            if (system_matrix[row][fixed_column] != 0) {
                fixed_column_consists_of_zeros = 0;
                break;
            }
        }
        if (fixed_column_consists_of_zeros == 1) {
            continue;
        }

        first_elem_of_fixed_column = system_matrix[fixed_row][fixed_column];
        not_zero_elem_idx_in_fixed_column = fixed_column;
        if (first_elem_of_fixed_column == 0) {
            for (int row = fixed_row + 1; row < size_of_matrix; ++row) {
                not_zero_elem_of_fixed_column = system_matrix[row][fixed_column];
                if (not_zero_elem_of_fixed_column != 0) {
                    not_zero_elem_idx_in_fixed_column = row;
                }
            }
            for (int column = 0; column < size_of_matrix; ++column) {
                system_matrix[fixed_row][column] += system_matrix[not_zero_elem_idx_in_fixed_column][column];
                reverse_system_matrix[fixed_row][column] += reverse_system_matrix[not_zero_elem_idx_in_fixed_column][column];
            }
        }


        for (int row = fixed_row + 1; row < size_of_matrix; ++row) {
            transvection_alpha = (-system_matrix[row][fixed_column]) / system_matrix[fixed_row][fixed_column];
            for (int column = 0; column < size_of_matrix; ++column) {
                system_matrix[row][column] += system_matrix[fixed_row][column] * transvection_alpha;
                reverse_system_matrix[row][column] +=
                        reverse_system_matrix[fixed_row][column] * transvection_alpha;
            }
        }

        ++fixed_row;
    }

    for (int fixed_column = size_of_matrix - 1; fixed_column > 0; --fixed_column) {
        fixed_row = fixed_column;
        for (int row = fixed_row - 1; row >= 0; --row) {
            transvection_alpha = (-system_matrix[row][fixed_column]) / system_matrix[fixed_row][fixed_column];
            for (int column = 0; column < size_of_matrix; ++column) {
                system_matrix[row][column] += system_matrix[fixed_row][column] * transvection_alpha;
                reverse_system_matrix[row][column] +=
                        reverse_system_matrix[fixed_row][column] * transvection_alpha;
            }
        }
    }


    for (int row = 0; row < size_of_matrix; ++row) {
        diag_element = row;
        row_multiplier = 1 / system_matrix[diag_element][diag_element];
        for (int column = 0; column < size_of_matrix; ++column) {
            system_matrix[row][column] *= row_multiplier;
            reverse_system_matrix[row][column] *= row_multiplier;
        }
    }

    for (int row = 0; row < size_of_matrix; ++row) {
        for (int column = 0; column < size_of_matrix; ++column) {
            system_solution[row] += reverse_system_matrix[row][column] * free_terms[column];
        }
        printf("%lf\n", system_solution[row]);
    }
    return 0;
}


int main() {
    double matrix_A[SIZE_LIMIT][SIZE_LIMIT] = {0}, matrix_b[SIZE_LIMIT] = {0};
    int n;

    scanf("%d", &n);

    for (int row = 0; row < n; ++row) {
        for (int column = 0; column < n + 1; ++column) {
            if (column != n){
                scanf("%lf", &matrix_A[row][column]);
            }
            else{
                scanf("%lf", &matrix_b[row]);
            }
        }
    }

    solve_system_of_linear_equations(matrix_A, matrix_b, n);

    return 0;
}
