#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_VAL 10

// Structure to pass data to each thread
typedef struct {
    int** A;
    int** B;
    int** C;
    int M;
    int N;
    int P;
    int start_row;
    int end_row;
} ThreadData;

// Function to generate a random matrix
void generate_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % MAX_VAL;
        }
    }
}

// Function to print a matrix
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform the matrix multiplication for each thread
void* matrix_multiply_worker(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int M = data->M;
    int N = data->N;
    int P = data->P;
    int** A = data->A;
    int** B = data->B;
    int** C = data->C;
    
    // Perform multiplication for the given range of rows
    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    pthread_exit(NULL);
}

// Function to multiply matrices using multiple threads
void multiply_matrices(int** A, int** B, int** C, int M, int N, int P, int num_threads) {
    pthread_t* threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
    ThreadData* thread_data = (ThreadData*)malloc(num_threads * sizeof(ThreadData));
    
    int rows_per_thread = M / num_threads;
    
    // Create threads and assign work
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].A = A;
        thread_data[i].B = B;
        thread_data[i].C = C;
        thread_data[i].M = M;
        thread_data[i].N = N;
        thread_data[i].P = P;
        thread_data[i].start_row = i * rows_per_thread;
        thread_data[i].end_row = (i == num_threads - 1) ? M : (i + 1) * rows_per_thread;
        
        pthread_create(&threads[i], NULL, matrix_multiply_worker, (void*)&thread_data[i]);
    }
    
    // Join all threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    free(threads);
    free(thread_data);
}

// Function to save the result matrix to a file
void save_result_to_file(int** C, int M, int P, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            fprintf(file, "%d ", C[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Main function to test the matrix multiplication with threads
int main() {
    srand(time(NULL));
    
    // Matrix dimensions
    int M = 5;  // Rows of matrix A (for display purposes, use smaller sizes)
    int N = 3;  // Columns of matrix A and rows of matrix B
    int P = 4;  // Columns of matrix B
    
    // Number of threads
    int num_threads = 2;
    
    // Allocate memory for matrices A, B, and C
    int** A = (int**)malloc(M * sizeof(int*));
    int** B = (int**)malloc(N * sizeof(int*));
    int** C = (int**)malloc(M * sizeof(int*));
    
    for (int i = 0; i < M; i++) {
        A[i] = (int*)malloc(N * sizeof(int));
        C[i] = (int*)malloc(P * sizeof(int));
    }
    for (int i = 0; i < N; i++) {
        B[i] = (int*)malloc(P * sizeof(int));
    }
    
    // Generate random matrices A and B
    generate_matrix(A, M, N);
    generate_matrix(B, N, P);
    
    // Display matrices A and B before multiplication
    printf("Matrix A (size %dx%d):\n", M, N);
    print_matrix(A, M, N);
    
    printf("\nMatrix B (size %dx%d):\n", N, P);
    print_matrix(B, N, P);
    
    // Start the timer
    clock_t start_time = clock();
    
    // Multiply matrices using multiple threads
    multiply_matrices(A, B, C, M, N, P, num_threads);
    
    // Stop the timer
    clock_t end_time = clock();
    
    // Calculate the time taken
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nMatrix multiplication completed in %.4f seconds.\n", time_taken);
    
    // Display the result matrix C after multiplication
    printf("\nMatrix C (result of A x B, size %dx%d):\n", M, P);
    print_matrix(C, M, P);
    
    // Save the result matrix to a file
    save_result_to_file(C, M, P, "multiplication.out");
    
    // Clean up memory
    for (int i = 0; i < M; i++) {
        free(A[i]);
        free(C[i]);
    }
    for (int i = 0; i < N; i++) {
        free(B[i]);
    }
    free(A);
    free(B);
    free(C);
    
    return 0;
}

