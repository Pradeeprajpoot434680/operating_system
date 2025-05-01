#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
void *positive(void *arg) {
    int *arr = (int *)arg;  // typecast to int pointer
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    int d = b * b - 4 * a * c;
    
    if (d < 0) {
        printf("roots are imaginary\n");
        return NULL;
    }

     float ans = (-b + sqrt(d)) / (float)(2 * a);  
    float *result = malloc(sizeof(float));  // allocate memory for the result because fn return type is void *
    *result = ans;// put the value of ans into result pointer
    return result;
}

void *negative(void *arg) {
    int *arr = (int *)arg;  
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    int d = b * b - 4 * a * c;

    if (d < 0) {
        printf("roots are imaginary\n");
        return NULL;
    }

    float ans = (-b - sqrt(d)) / (float)(2 * a);  
    float *result = malloc(sizeof(float));  
    *result = ans;
    return result;
}

int main() {
    int a, b, c;
    printf("Enter the value of a, b, and c: ");
    scanf("%d %d %d", &a, &b, &c);

    pthread_t t1, t2;
    int arr[] = {a, b, c};  

   
    pthread_create(&t1, NULL, positive, (void *)arr);//(void *) type casting
    pthread_create(&t2, NULL, negative, (void *)arr);

    float *firstRoot, *secondRoot;
    pthread_join(t1, (void **)&firstRoot);  
    pthread_join(t2, (void **)&secondRoot);

    if (firstRoot != NULL && secondRoot != NULL) {
        printf("First root: %f\n", *firstRoot);
        printf("Second root: %f\n", *secondRoot);
    } else {
        printf("One or both roots are imaginary.\n");
    }

    // free dynamically allocated memory
    free(firstRoot);
    free(secondRoot);

    return 0;
}

