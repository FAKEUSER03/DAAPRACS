// Q1 DAC Linear_Binary

#include <stdio.h>
// Function to perform linear search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1; // Key not found
}

// Function to perform binary search using divide and conquer approach
int binarySearch(int arr[], int low, int high, int key)
{
    if (low <= high) // while(low<=high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binarySearch(arr, low, mid - 1, key);
        }
        else
        {
            return binarySearch(arr, mid + 1, high, key);
        }
    }
    return -1; // Key not found
}

int main()
{
    int n, key, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    printf("Enter your choice:\n");
    printf("1. Linear search\n");
    printf("2. Binary search\n");
    scanf("%d", &choice);
    int index;
    switch (choice)
    {
    case 1:
        index = linearSearch(arr, n, key);
        if (index == -1)
        {
            printf("Key not found\n");
        }
        else
        {
            printf("Key found at index %d\n", index);
        }
        break;
    case 2:
        index = binarySearch(arr, 0, n - 1, key);
        if (index == -1)
        {
            printf("Key not found\n");
        }
        else
        {
            printf("Key found at index %d\n", index);
        }
        break;
    default:
        printf("Invalid choice\n");
    }
    return 0;
}

// Q2 DAC max_min

#include <stdio.h>

int min(int a[], int low, int high)
{
    int min_x;
    int size = high - low + 1;
    if (size == 1)
    {
        return (a[low]);
    }
    else if (size == 2)
    {
        min_x = (a[low] > a[high]) ? a[high] : a[low];
        return (min_x);
    }
    else
    {
        int mid = (high + low) / 2;
        int min1 = min(a, 0, mid - 1);
        int min2 = min(a, mid, size);
        int min_f = (min1 > min2) ? min2 : min1;
        return min_f;
    }
}

int max(int a[], int low, int high)
{
    int max_x;
    int size = high - low + 1;
    if (size == 1)
    {
        return (a[low]);
    }
    else if (size == 2)
    {
        max_x = (a[low] < a[high]) ? a[high] : a[low];
        return (max_x);
    }
    else
    {
        int mid = (high + low) / 2;
        int max1 = max(a, 0, mid - 1);
        int max2 = max(a, mid, size);
        int max_f = (max1 < max2) ? max2 : max1;
        return max_f;
    }
}

void main()
{
    int n, i, a[100];
    printf("Enter the size of array\n");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int minimum = min(a, 0, n - 1);
    printf("the minimum is %d", minimum);
    printf("\n");
    int maximum = max(a, 0, n - 1);
    printf("the maximum is %d", maximum);
}

// Q3 DAC MergeSort

#include <stdio.h>

// Function to merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on arr[l..r]
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

// Q4 DAC QuickSort

#include <stdio.h>

// Function to swap two elements in an array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the partition index
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;                    // Increment index of smaller element
            swap(&arr[i], &arr[j]); // Swap arr[i] and arr[j]
        }
    }

    swap(&arr[i + 1], &arr[high]); // Swap arr[i+1] and arr[high], i+1 is the partition index
    return i + 1;
}

// Function to perform quicksort on arr[low..high]
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

// Q5 DAC mul_longint

#include <stdio.h>

#include <math.h>
void main()
{
    int n1, n2, count = 0, digit;
    printf("ENter 2 numbers ");
    scanf("%d %d", &n1, &n2);
    int max = (n1 > n2) ? n1 : n2;
    while (max != 0)
    {
        max = max / 10;
        count++;
    }
    printf("number of digits are %d", count);

    int a, b, c, d;
    a = n1 / (int)(pow(10, (count + 1) / 2));
    printf("a is %d\n", a);
    b = n1 % (int)(pow(10, (count + 1) / 2));
    printf("b is %d\n", b);
    c = n2 / (int)pow(10, (count + 1) / 2);
    printf("c is %d\n", c);
    d = n2 % (int)(pow(10, (count + 1) / 2));
    printf("d is %d\n", d);
    int ans = (a * c * pow(10, count)) + ((a * d) + (b * c)) * pow(10, (count + 1) / 2) + b * d;
    printf("ans is %d", ans);
}

// Q6 Greedy knapsack

#include <stdio.h>
struct knapsack
{
    int itemno;
    float profit;
    float weight;
    float ppw;
    float part;
};
void sort(int n, struct knapsack item[])
{
    int i;
    struct knapsack temp;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (item[j].ppw < item[j + 1].ppw)
            {
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int n, i;
    float capacity;
    printf("Enter the number of items:");
    scanf("%d", &n);
    struct knapsack item[n];
    for (i = 0; i < n; i++)
    {
        item[i].itemno = i + 1;
        printf("Enter the profit of item %d: ", i + 1);
        scanf("%f", &item[i].profit);
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%f", &item[i].weight);
        item[i].ppw = item[i].profit / item[i].weight;
    }
    sort(n, item);
    printf("Enter max Capacity:");
    scanf("%f", &capacity);
    float totalprofit = 0;
    for (i = 0; i < n; i++)
    {
        if (capacity == 0)
        {
            item[i].part = 0;
        }
        else if (item[i].weight <= capacity)
        {
            item[i].part = 1;
            capacity = capacity - item[i].weight;
            totalprofit += item[i].profit;
        }
        else
        {
            item[i].part = (capacity / item[i].weight);
            capacity = 0;
            totalprofit += (item[i].profit * item[i].part);
        }
    }
    printf("Item no\t Profit \t Weight\t\t Profit/weight\t Paartition\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", item[i].itemno, item[i].profit, item[i].weight, item[i].ppw, item[i].part);
    }
    printf("Total profit earned :- %.2f \n", totalprofit);
}

// Q7 Greedy Job

#include <stdio.h>

#define MAX 100

typedef struct Job {
  char id[5];
  int deadline;
  int profit;
} Job;

void jobSequencingWithDeadline(Job jobs[], int n);

int minValue(int x, int y) {
  if(x < y) return x;
  return y;
}

int main(void) {
  //variables
  int i, j,n;
  Job jobs[100];

  //jobs with deadline and profit
printf("Enter the number of jobs: ");
  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    printf("Enter job %d details:\n", i+1);
    printf("ID: ");
    scanf("%s", jobs[i].id);
    printf("Deadline: ");
    scanf("%d", &jobs[i].deadline);
    printf("Profit: ");
    scanf("%d", &jobs[i].profit);
  }

  //temp
  Job temp;

  

  //sort the jobs profit wise in descending order
  for(i = 0; i < n; i++) {
    for(j = 0; j < n - i-1; j++) {
      if(jobs[j+1].profit > jobs[j].profit) {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }

  printf("%s\t%s\t%s\n", "Job", "Deadline", "Profit");
  for(i = 0; i < n; i++) {
    printf("%s\t\t%i\t\t%i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }

  jobSequencingWithDeadline(jobs, n);

  return 0;
}

void jobSequencingWithDeadline(Job jobs[], int n) {
  //variables
  int i, j, k, maxprofit;

  //free time slots
  int timeslot[MAX];

  //filled time slots
  int filledTimeSlot = 0;

  //find max deadline value
  int dmax = 0;
  for(i = 0; i < n; i++) {
    if(jobs[i].deadline > dmax) {
      dmax = jobs[i].deadline;
    }
  }

  //free time slots initially set to -1 [-1 denotes EMPTY]
  for(i = 1; i <= dmax; i++) {
    timeslot[i] = -1;
  }

  printf("dmax: %d\n", dmax);

  for(i = 1; i <= n; i++) {
    k = minValue(dmax, jobs[i - 1].deadline);
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }

    //if all time slots are filled then stop
    if(filledTimeSlot == dmax) {
      break;
    }
  }

  //required jobs
  printf("\nRequired Jobs: ");
  for(i = 1; i <= dmax; i++) {
    printf("%s", jobs[timeslot[i]].id);

    if(i < dmax) {
      printf(" --> ");
    }
  }

  //required profit
  maxprofit = 0;
  for(i = 1; i <= dmax; i++) {
    maxprofit += jobs[timeslot[i]].profit;
  }
  printf("\nMax Profit: %d\n", maxprofit);
}

// Q8 Greedy Tapes

#include <stdio.h>

int i, j, n, t = 1;
int p[30], l[30], temp, m, tape[10];

// float mrt[10];

void getval()
{
    printf("Enter number of programs: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter length of program %d: ", i + 1);
        scanf("%d", &l[i]);
        p[i] = i;
    }
    printf("\n");
}

void sort()
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (l[j] > l[j + 1])
            {
                temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;

                m = p[j];
                p[j] = p[j + 1];
                p[j + 1] = m;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("program %d\tlength %d\n", (p[i] + 1), l[i]);
    }
}

void tapefn()
{
    int count = 0;
    int r = 0;
    for (i = 0; i < n; i++)
    {
        tape[r] = l[i];
        r++;
    }
    r = 0;
    printf("\nTape : \n");
    while (tape[r] != 0)
    {
        printf("%d\t", tape[r]);
        r++;
    }
    printf("\n");
}

void calmrt()
{

    float sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            sum += tape[j];
        }
    }
    printf("Minimum storage length is: %.1f\n", sum);
    printf("Minimum retreival time (MRT) is :%.1f\n", (sum / n));
}

int main()
{
    getval();
    sort();
    tapefn();
    calmrt();

    return 0;
}

// Q9 Greedy Prims

#include <stdio.h>

int prev[10];
int leastedge[10];
int included[10];
int mincost = 0;
int n;
int least();

void main()
{

    printf("Enter the number of vertices");
    scanf("%d", &n);
    int adjmat[n][n];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adjmat[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        leastedge[i] = 100, included[i] = 0;
    }
    leastedge[0] = 0;
    prev[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int u = least();
        included[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (adjmat[u][v] && included[v] == 0 && adjmat[u][v] < leastedge[v])
            {
                prev[v] = u, leastedge[v] = adjmat[u][v];
                // mincost = mincost + adjmat[u][v];
            }
        }
    }
    printf("Edges included in the MST will be:\n");
    for (int i = 1; i < n; i++)
        printf("%c%c\t", prev[i] + 65, i + 65);

    // printf("\nMinimum cost = %d",mincost);
}
int least()
{
    int min = 100, minvertex;
    for (int j = 1; j < n; j++)
    {
        if (included[j] == 0 && leastedge[j] < min)
            min = leastedge[j], minvertex = j;
    }
    return minvertex;
}

// Q10 Greedy Kruskals

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
int find(int);
int uni(int, int);
void main()
{

    printf("\n\tImplementation of Kruskal's algorithm\n");
    printf("\nEnter the no. of vertices:");
    scanf("%d", &n);
    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n\tMinimum cost = %d\n", mincost);
    getch();
}
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

// Q11 Greedy Dijkstra

#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES];
int visited[MAX_VERTICES];
int previous[MAX_VERTICES];

int get_min_vertex(int num_vertices)
{
    int min_distance = INT_MAX, min_vertex;
    for (int i = 0; i < num_vertices; i++)
    {
        if (!visited[i] && distance[i] < min_distance)
        {
            min_distance = distance[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

void dijkstra(int start_vertex, int num_vertices)
{
    for (int i = 0; i < num_vertices; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
        previous[i] = -1;
    }
    distance[start_vertex] = 0;

    for (int i = 0; i < num_vertices; i++)
    {
        int current_vertex = get_min_vertex(num_vertices);
        visited[current_vertex] = 1;
        for (int j = 0; j < num_vertices; j++)
        {
            if (graph[current_vertex][j] && !visited[j] && distance[current_vertex] != INT_MAX &&
                distance[current_vertex] + graph[current_vertex][j] < distance[j])
            {
                distance[j] = distance[current_vertex] + graph[current_vertex][j];
                previous[j] = current_vertex;
            }
        }
    }
}

// void printShortestPath(int start_vertex, int destination_vertex)
// {
//     if (distance[destination_vertex] == INT_MAX)
//     {
//         printf("No path exists from vertex %d to vertex %d\n", start_vertex, destination_vertex);
//         return;
//     }

//     int path[MAX_VERTICES];
//     int path_length = 0;
//     int current_vertex = destination_vertex;

//     while (current_vertex != -1)
//     {
//         path[path_length++] = current_vertex;
//         current_vertex = previous[current_vertex];
//     }

//     printf("Shortest path from vertex %d to vertex %d: ", start_vertex, destination_vertex);
//     for (int i = path_length - 1; i >= 0; i--)
//     {
//         printf("%d", path[i]);
//         if (i != 0)
//             printf(" -> ");
//     }
//     printf("\n");
// }

int main()
{
    int num_vertices, num_edges, start_vertex, destination_vertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    int adjmat[num_vertices][num_vertices];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++)
        for (int j = 0; j < num_vertices; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);

    printf("Enter the destination vertex\n");
    scanf("%d", &destination_vertex);
    dijkstra(start_vertex, num_vertices);

    printf("Shortest distances from the starting vertex:\n");
    for (int i = 0; i < num_vertices; i++)
    {
        printf("%d -> %d: %d\n", start_vertex, i, distance[i]);
    }

    // printShortestPath(start_vertex, destination_vertex);

    return 0;
}


// Q12 Greedy subset

#include <stdio.h>
#include <stdlib.h>

#define MAX_SETS 100
#define MAX_ITEMS 100

int sets[MAX_SETS][MAX_ITEMS];
int num_sets;
int num_items;

int chosen[MAX_SETS];
int num_chosen;

int uncovered[MAX_ITEMS];
int num_uncovered;

void read_input() {
    int i, j;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the number of subsets: ");
    scanf("%d", &num_sets);
    for (i = 0; i < num_sets; i++) {
        printf("Enter the number of items in subset %d: ", i + 1);
        int size;
        scanf("%d", &size);
        for (j = 0; j < size; j++) {
            scanf("%d", &sets[i][j]);
        }
    }
}

int compare(const void* a, const void* b) {
    int* arr_a = (int*) a;
    int* arr_b = (int*) b;
    return arr_b[1] - arr_a[1];
}

void choose_sets() {
    int i, j;
    while (num_uncovered > 0) {
        int best_set = -1;
        int best_set_count = 0;
        for (i = 0; i < num_sets; i++) {
            if (chosen[i]) continue;
            int count = 0;
            for (j = 0; j < num_items; j++) {
                if (uncovered[j] && sets[i][j]) {
                    count++;
                }
            }
            if (count > best_set_count) {
                best_set = i;
                best_set_count = count;
            }
        }
        if (best_set == -1) {
            printf("Error: No set chosen\n");
            return;
        }
        chosen[best_set] = 1;
        num_chosen++;
        for (j = 0; j < num_items; j++) {
            if (uncovered[j] && sets[best_set][j]) {
                uncovered[j] = 0;
                num_uncovered--;
            }
        }
    }
}

void print_solution() {
    int i;
    printf("The minimum number of subsets required is %d\n", num_chosen);
    printf("The chosen subsets are:\n");
    for (i = 0; i < num_sets; i++) {
        if (chosen[i]) {
            printf("Subset %d\n", i + 1);
        }
    }
}

int main() {
    read_input();
    int i;
    for (i = 0; i < num_items; i++) {
        uncovered[i] = 1;
    }
    num_uncovered = num_items;
    qsort(sets, num_sets, sizeof(int) * MAX_ITEMS, compare);
    choose_sets();
    print_solution();
    return 0;
}

// Q13 Greedy Container_Loading

#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTAINERS 100

int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a); // Sort in non-increasing order
}

int container_loading_cover(int containers[], int n, int capacity)
{
    qsort(containers, n, sizeof(int), compare);
    int loaded_weight = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (containers[i] + loaded_weight <= capacity)
        {
            loaded_weight += containers[i];
            count++;
        }
    }

    return count;
}

int main()
{
    int n, capacity, containers[MAX_CONTAINERS];

    printf("Enter the number of containers: ");
    scanf("%d", &n);

    printf("Enter the capacity of the ship: ");
    scanf("%d", &capacity);

    printf("Enter the weights of the containers:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &containers[i]);
    }

    int num_loaded_containers = container_loading_cover(containers, n, capacity);

    printf("The minimum number of containers needed to cover the ship is: %d", num_loaded_containers);

    return 0;
}

// Q14 Greedy Coin_change

#include <stdio.h>
#include <conio.h>
void main()
{
    int amnt, n, i, j, temp;
    printf("Enter the amount required\n");
    scanf("%d", &amnt);
    printf("Enter the number of denominations\n");
    scanf("%d", &n);
    int den[n], count[n];
    for (i = 0; i < n; i++)
    {
        count[i] = 0;
    }
    printf("Enter the denominations\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &den[i]);
    }
    // sorting
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (den[j] < den[j + 1])
            {
                temp = den[j];
                den[j] = den[j + 1];
                den[j + 1] = temp;
            }
        }
    }
    while (amnt != 0)
    {
        for (i = 0; i < n; i++)
        {
            if (amnt >= den[i])
            {
                count[i]++;
                amnt = amnt - den[i];
                break;
            }
        }
    }
    printf("Denomination\tCoin used\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\n", den[i], count[i]);
    }
}

// Q15 Dynamic coin_change

#include <stdio.h>
void main()
{
    int i, n, j, den[100], cost, cg[100][100], min, balance;
    printf("Enter the number of denominations\n");
    scanf("%d", &n);
    printf("Enter denominations\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &den[i]);
    }
    printf("Enter the cost  required\n");
    scanf("%d", &cost);
    cg[0][0] = -2;
    for (i = 0; i < n; i++)
    {
        cg[i + 1][0] = den[i];
    }
    for (i = 0; i <= cost; i++)
    {
        cg[0][i + 1] = i;
        cg[1][i + 1] = cg[0][i + 1];
    }

    for (i = 2; i <= n; i++)
    {
        for (j = 1; j <= cost + 1; j++)
        {
            if ((j - 1) < den[i - 1])
            {
                cg[i][j] = cg[i - 1][j];
            }
            else
            {
                min = (cg[i - 1][j] > (cg[i][j - den[i - 1]] + 1)) ? (cg[i][j - den[i - 1]] + 1) : cg[i - 1][j];
                cg[i][j] = min;
            }
        }
    }
    printf("Coin change matrix\n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= cost + 1; j++)
        {
            // cg[1][0]=1;
            printf("%d\t", cg[i][j]);
        }
        printf("\n");
    }
    printf("Demoniations used\n");
    i = n;
    j = cost + 1;
    balance = cost;
    int dused[10];
    int k = 0;
    while (balance != 0)
    {
        if (cg[i][j] == cg[i - 1][j])
        {
            i--;
        }
        else
        {
            dused[k] = den[i - 1];
            balance = balance - den[i - 1];
            k++;
            i = n;
            j = balance + 1;
        }
    }
    for (i = 0; i < k; i++)
    {
        printf("%d\t", dused[i]);
    }
}

// Q16 Dynamic TSP

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4

int adjmat[N][N];
int visited[N];
int count = 0;

int tsp(int s, int path[])
{
    visited[s] = 1;
    path[count] = s;
    count++;
    if (count == N)
    {
        visited[s] = 0;
        count--;
        return adjmat[s][0];
    }
    int ans = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0)
        {
            int subproblem = tsp(i, path);
            int cost = adjmat[s][i] + subproblem;
            if (cost < ans)
            {
                ans = cost;
            }
        }
    }
    visited[s] = 0;
    count--;
    return ans;
}

int main()
{
    int path[N + 1] = {-1};
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &adjmat[i][j]);
        }
    }
    int ans = tsp(0, path);
    printf("Minimum cost: %d\n", ans);
    printf("Path taken: ");
    for (int i = N; i >= 0; i--)
    {
        printf("%d ", (path[i] + 1));
    }
    return 0;
}

// Q17 Dynamic Knapsack

#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Print the solution vector
    int res = K[n][W];
    int included[n];
    for (i = 0; i < n; i++)
        included[i] = 0;

    w = W;
    for (i = n; i > 0 && res > 0; i--)
    {
        if (res == K[i - 1][w])
            continue;
        else
        {
            included[i - 1] = 1;
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }

    printf("Solution Vector: ");
    for (i = 0; i < n; i++)
        printf("%d ", included[i]);
    printf("\n");

    return K[n][W];
}

int main()
{
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter the profit and weights of each item:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &val[i], &wt[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("\nValue = %d\n", knapsack(W, wt, val, n));

    return 0;
}


// Q18 Dynamic LCS

#include <stdio.h>
#include <string.h>
void main()
{
    char str1[20], str2[20], arrow[20][20], x[20];
    int m, n, i, j, LCS_table[20][20], k;
    printf("Enter string 1 : ");
    gets(str1);
    printf("Enter string 2 : ");
    gets(str2);
    m = strlen(str1);
    n = strlen(str2);

    // FOR LCS TABLE
    LCS_table[0][0] = 0;
    LCS_table[1][0] = -2;
    LCS_table[0][1] = -2;

    for (i = 2; i <= m + 1; i++)
    {
        LCS_table[i][0] = -1;
    }

    for (i = 2; i <= n + 1; i++)
    {
        LCS_table[0][i] = -1;
    }

    for (i = 1; i <= m + 1; i++)
    {
        LCS_table[i][1] = 0;
    }

    for (i = 1; i <= n + 1; i++)
    {
        LCS_table[1][i] = 0;
    }

    // FOR ARROW MATRIX
    arrow[0][0] = '0';
    arrow[1][0] = 'x';
    arrow[0][1] = 'y';

    for (i = 2, k = 0; i <= m + 1; i++, k++)
    {
        arrow[i][0] = str1[k];
    }

    for (i = 2, k = 0; i <= n + 1; i++, k++)
    {
        arrow[0][i] = str2[k];
    }

    for (i = 1; i <= m + 1; i++)
    {
        arrow[i][1] = '0';
    }

    for (i = 1; i <= n + 1; i++)
    {
        arrow[1][i] = '0';
    }

    for (i = 2; i <= m + 1; i++)
    {
        for (j = 2; j <= n + 1; j++)
        {
            if (str1[i - 2] == str2[j - 2])
            {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
                arrow[i][j] = (char)'d';
            }
            else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1])
            {
                LCS_table[i][j] = LCS_table[i - 1][j];
                arrow[i][j] = (char)'u';
            }
            else
            {
                LCS_table[i][j] = LCS_table[i][j - 1];
                arrow[i][j] = (char)'l';
            }
        }
    }

    printf("Printing adjacency matrix\n");
    for (i = 0; i <= m + 1; i++)
    {
        for (j = 0; j <= n + 1; j++)
        {
            printf("%d\t", LCS_table[i][j]);
        }
        printf("\n");
    }

    printf("Printing arrow matrix\n");
    for (i = 0; i <= m + 1; i++)
    {
        for (j = 0; j <= n + 1; j++)
        {
            printf("%c\t", arrow[i][j]);
        }
        printf("\n");
    }

    i = m + 1, j = n + 1, k = 0;

    while (arrow[i][j] == 'l' || arrow[i][j] == 'd' || arrow[i][j] == 'u')
    {

        if (arrow[i][j] == 'u')
        {
            arrow[i][j] = arrow[i - 1][j];
            i--;
        }
        else if (arrow[i][j] == 'l')
        {
            arrow[i][j] = arrow[i][j - 1];
            j--;
        }
        else if (arrow[i][j] == 'd')
        {
            // printf("%c ",arrow[i][0]);
            x[k] = arrow[i][0];
            arrow[i][j] = arrow[i - 1][j - 1];
            i--;
            j--;
            k++;
        }
    }
    printf("Longest common subsequence is \n");
    for (int i = k - 1; i >= 0; i--)
    {
        printf("%c ", x[i]);
    }
}

// Q19 Backtraking N-Queen

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int board[20], count;

void print(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n", ++count);

    for (i = 1; i <= n; ++i)
        printf("\t%d", i);

    for (i = 1; i <= n; ++i)
    {
        printf("\n\n%d", i);

        for (j = 1; j <= n; ++j)
        {
            if (board[i] == j)
                printf("\tQ");
            else
                printf("\t-");
        }
    }
}

int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        if (board[i] == column)
            return 0;
        else if (abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1;
}

void queen(int row, int n)
{
    int column;

    for (column = 1; column <= n; ++column)
    {
        if (place(row, column))
        {
            board[row] = column;

            if (row == n)
                print(n);
            else
                queen(row + 1, n);
        }
    }
}

int main()
{
    int n, i, j;

    printf("- N Queens Problem Using Backtracking -\n\n");
    printf("Enter number of Queens:");
    scanf("%d", &n);

    queen(1, n);

    return 0;
}

// Q20 Backtracking Sum_of_subset

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int inc[50], w[50], sum, n;
int promising(int i, int wt, int total)
{
    return (((wt + total) >= sum) && ((wt == sum) || (wt + w[i + 1] <= sum)));
}

void sumset(int i, int wt, int total)
{
    int j;
    if (promising(i, wt, total))
    {
        if (wt == sum)
        {
            printf("\n{\t");
            for (j = 0; j <= i; j++)
                if (inc[j])
                    printf("%d\t", w[j]);
            printf("}\n");
        }
        else
        {
            inc[i + 1] = TRUE;
            sumset(i + 1, wt + w[i + 1], total - w[i + 1]);
            inc[i + 1] = FALSE;
            sumset(i + 1, wt, total - w[i + 1]);
        }
    }
}
int main()
{
    int i, j, n, temp, total = 0;
    printf("\n Enter how many numbers:\n");
    scanf("%d", &n);
    printf("\n Enter %d numbers to th set:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        total += w[i];
    }
    printf("\n Input the sum value to create sub set:\n");
    scanf("%d", &sum);
    for (i = 0; i <= n; i++)
        for (j = 0; j < n - 1; j++)
            if (w[j] > w[j + 1])
            {
                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
    printf("\n The given %d numbers in ascending order:\n", n);
    for (i = 0; i < n; i++)
        printf("%d \t", w[i]);
    if ((total < sum))
        printf("\n Subset construction is not possible");
    else
    {
        for (i = 0; i < n; i++)
            inc[i] = 0;
        printf("\n The solution using backtracking is:\n");
        sumset(-1, 0, total);
    }
}

// Q21 Backtracking Graph_colouring

#include <stdio.h>
#include <conio.h>

int m, n, c = 0, count = 0, g[50][50], x[50];

void nextValue(int k);
void GraphColoring(int k);

void main()
{

    int i, j;
    int temp;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter Adjacency Matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    printf("\nPossible Solutions are\n");
    for (m = 1; m <= n; m++)
    {
        if (c == 1)
        {
            break;
        }
        GraphColoring(1);
    }
    printf("\nThe chromatic number is %d", m - 1);
    // in for loop, m gets incremented first and then the condition is checked
    // so it is m minus 1
    printf("\nThe total number of solutions is %d", count);
    getch();
}

void GraphColoring(int k)
{
    int i;
    while (1)
    {
        nextValue(k);
        if (x[k] == 0)
        {
            return;
        }
        if (k == n)
        {
            c = 1;
            for (i = 1; i <= n; i++)
            {
                printf("%d ", x[i]);
            }
            count++;
            printf("\n");
        }
        else
            GraphColoring(k + 1);
    }
}

void nextValue(int k)
{
    int j;
    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
        {
            return;
        }
        for (j = 1; j <= n; j++)
        {
            if (g[k][j] == 1 && x[k] == x[j])
                break;
        }
        if (j == (n + 1))
        {
            return;
        }
    }
}

// Q22 Backtracking Knapsack

#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

int w[MAX_ITEMS], p[MAX_ITEMS]; // weights and profits of items
int n, max_weight;              // number of items and maximum weight of knapsack
int max_profit;                 // maximum profit found so far
int cur_weight, cur_profit;     // current weight and profit while searching

void knapsack(int i)
{
    if (i == n)
    {
        // reached the end of the item list
        if (cur_profit > max_profit)
        {
            max_profit = cur_profit; // update maximum profit
        }
        return;
    }

    // choose to include current item
    if (cur_weight + w[i] <= max_weight)
    {
        cur_weight += w[i];
        cur_profit += p[i];
        knapsack(i + 1);
        cur_weight -= w[i];
        cur_profit -= p[i];
    }

    // choose to exclude current item
    knapsack(i + 1);
}

int main()
{
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &max_weight);

    max_profit = 0;
    cur_weight = 0;
    cur_profit = 0;

    knapsack(0);

    printf("Maximum profit: %d\n", max_profit);

    return 0;
}

// Q23 BranchBound Job

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 20

int n;
int p[MAX_N];
int d[MAX_N];
int w[MAX_N];
int s[MAX_N];
int f[MAX_N];
int upperbound = INT_MAX;
int best_time;
int best_included[MAX_N];

int calcost(int job, int included[MAX_N])
{
    included[job] = 1;
    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        if (included[i] == 0)
        {
            cost += w[i];
        }
    }
    return cost;
}

int calupperbound(int included[MAX_N])
{

    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        if (included[i] == 0)
        {
            cost += w[i];
        }
    }

    return cost;
}

void solve(int job, int depth, int included[MAX_N], int cost)
{
    for (int i = job + 1; i < n; i++)
    {
        if (included[i] == 0)
        {
            if (job == 0)
            {
                s[i] = 0;
            }
            else
            {
                s[i] = f[job - 1];
            }

            f[i] = s[i] + p[i];
            if (f[i] <= d[i])
            {
                int cost1 = calcost(i, included);
                if (cost1 < upperbound)
                {
                    included[i] = 1;
                    upperbound = calupperbound(included);
                    best_time = upperbound;
                    for (int i = 0; i < n; i++)
                    {
                        best_included[i] = included[i];
                    }
                    solve(i, depth + 1, included, cost1);
                    included[i] = 0;
                }
            }
            included[i] = 0;
        }
    }
}

int main()
{
    printf("Enter the number of jobs (max %d): ", MAX_N);
    scanf("%d", &n);

    printf("Enter the processing times for each job:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter the deadlines for each job:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }

    printf("Enter the Penalties for each job:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    best_time = INT_MAX;
    int included[MAX_N] = {0};
    solve(0, 0, included, 0);

    printf("Final Upper Bound: %d\n", best_time);
    printf("Jobs included: ");
    for (int i = 0; i < n; i++)
    {
        if (best_included[i] == 1)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    printf("Path taken: ");
    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (best_included[i] == 1)
        {
            printf("%d ", i + 1);
            current_time += p[i];
        }
    }
    printf("\n");

    return 0;
}

// Q24 BranchBound knapsack

#include <stdio.h>
#include <stdbool.h>

#define N 4

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int bound(int w, int v, int i, int weights[], int values[], int n, int lb, int ub)
{
    int j, k;
    for (j = i, k = w; j < n && k < ub; j++)
    {
        k += weights[j];
        v += values[j];
    }
    if (k > ub)
    {
        v -= values[j - 1];
        k -= weights[j - 1];
        v += (ub - k) * (values[j - 1] / weights[j - 1]);
    }
    for (j = i, k = w; j < n && k < lb; j++)
    {
        k += weights[j];
        v += values[j];
    }
    if (k > lb)
    {
        v -= values[j - 1];
        k -= weights[j - 1];
        v += (lb - k) * (values[j - 1] / weights[j - 1]);
    }
    return v;
}

void knapsack_bb(int w, int v, int i, int weights[], int values[], int n, int lb, int ub, int *best_value, int solution[])
{
    if (i == n)
    {
        if (v > *best_value)
        {
            *best_value = v;
            for (int j = 0; j < n; j++)
            {
                solution[j] = (w & (1 << j)) ? 1 : 0;
            }
        }
        return;
    }
    if (bound(w, v, i, weights, values, n, lb, ub) > *best_value)
    {
        knapsack_bb(w, v, i + 1, weights, values, n, lb, ub, best_value, solution);
        w |= 1 << i;
        v += values[i];
        if (w <= ub)
        {
            knapsack_bb(w, v, i + 1, weights, values, n, lb, ub, best_value, solution);
        }
        v -= values[i];
        w &= ~(1 << i);
    }
}

int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int weights[N];
    int values[N];
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &weights[i], &values[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    int lb = 0;
    int ub = capacity;
    int best_value = 0;
    int solution[N] = {0};

    knapsack_bb(0, 0, 0, weights, values, n, lb, ub, &best_value, solution);

    printf("Maximum value: %d\n", best_value);
    printf("Solution: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", solution[i]);
    }
    printf("\n");

    return 0;
}

// Q25 BranchBound TSP

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define N 4

int final_path[N + 1];
bool visited[N];
int final_res = INT_MAX;

void copyToFinal(int curr_path[])
{
    for (int i = 0; i < N; i++)
        final_path[i] = curr_path[i];
    final_path[N] = curr_path[0];
}

int firstMin(int adj[N][N], int i)
{
    int min = INT_MAX;
    for (int k = 0; k < N; k++)
        if (adj[i][k] < min && i != k)
            min = adj[i][k];
    return min;
}

int secondMin(int adj[N][N], int i)
{
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < N; j++)
    {
        if (i == j)
            continue;

        if (adj[i][j] <= first)
        {
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second && adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}

void resetVisited()
{
    for (int i = 0; i < N; i++)
        visited[i] = false;
}

void TSPRec(int adj[N][N], int curr_bound, int curr_weight, int level, int curr_path[])
{
    if (level == N)
    {
        if (adj[curr_path[level - 1]][curr_path[0]] != 0)
        {
            int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];
            if (curr_res < final_res)
            {
                copyToFinal(curr_path);
                final_res = curr_res;
            }
        }
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (adj[curr_path[level - 1]][i] != 0 && visited[i] == false)
        {
            int temp = curr_bound;
            curr_weight += adj[curr_path[level - 1]][i];

            if (level == 1)
                curr_bound -= ((firstMin(adj, curr_path[level - 1]) + firstMin(adj, i)) / 2);
            else
                curr_bound -= ((secondMin(adj, curr_path[level - 1]) + firstMin(adj, i)) / 2);

            if (curr_bound + curr_weight < final_res)
            {
                curr_path[level] = i;
                visited[i] = true;

                TSPRec(adj, curr_bound, curr_weight, level + 1, curr_path);

                visited[i] = false;
            }

            curr_weight -= adj[curr_path[level - 1]][i];
            curr_bound = temp;

            resetVisited();
            for (int j = 0; j <= level - 1; j++)
                visited[curr_path[j]] = true;
        }
    }
}

void TSP(int adj[N][N])
{
    int curr_path[N + 1];
    int curr_bound = 0;

    for (int i = 0; i < N; i++)
        visited[i] = false;

    for (int i = 0; i < N; i++)
        curr_bound += (firstMin(adj, i) + secondMin(adj, i));

    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;

    curr_path[0] = 0;
    visited[0] = true;

    TSPRec(adj, curr_bound, 0, 1, curr_path);
}
int main()
{
    int adj[N][N] = {{0, 10, 15, 20},
                     {10, 0, 35, 25},
                     {15, 35, 0, 30},
                     {20, 25, 30, 0}};
    TSP(adj);

    printf("Minimum cost : %d\n", final_res);
    printf("Path Taken : ");
    for (int i = 0; i <= N; i++)
        printf("%d ", final_path[i]);
    printf("\n");

    return 0;
}
