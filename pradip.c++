#include<iostream> 
using namespace std; 
const int P = 5; 
const int R = 4; 
void calculateNeed(int need[P][R],int max[P][R],int alloc[P][R]) 
{  
for (int i = 0 ; i < P ; i++) 
for (int j = 0 ; j < R ; j++) 
need[i][j] = max[i][j] - alloc[i][j]; 
} 
bool isSafe(int processes[], int avail[], int max[][R], 
int alloc[][R]) 
{ 
int need[P][R]; 
calculateNeed(need, max, alloc); 
bool finish[P] = {0}; 
int safeSeq[P]; 
int work[R]; 
for (int i = 0; i < R ; i++) 
work[i] = avail[i]; 
int count = 0; 
while (count < P) 
{ 
bool found = false; 
for (int p = 0; p < P; p++) 
{ 
if (finish[p] == 0) 
{ 	 
int j; 
for (j = 0; j < R; j++) 
if (need[p][j] > work[j]) 
break; 
if (j == R) 
{ 
for (int k = 0 ; k < R ; k++) 
work[k] += alloc[p][k]; 
safeSeq[count++] = p; 
finish[p] = 1;
found = true; 
} 
} 
} 
if (found == false) 
{ 
cout << "System is not in safe state"; 
return false; 
} 
} 
cout << "Congratulations.....System is in safe state.\nSafe Sequence is: "; 
for (int i = 0; i < P ; i++)  
cout << safeSeq[i] << " "; 
return true; 
}
int main() 
{ 
cout << "Welcome..This Programme works on the concept of Banker's Algorithm.\n";
cout << "In this we will find out the safe sequence for the System.\n";
cout <<"**************************************************************************************\n";
int processes[] = {0, 1, 2, 3, 4}; 
int avail[] = {1, 5, 2, 0}; 
int max[][R] = {{0, 0, 1, 2}, 
               {1, 7, 5, 0}, 
               {2, 3, 5, 6}, 
               {0, 6, 5, 2}, 
               {0, 6, 5, 6}}; 
int alloc[][R] = {{0, 0, 1, 2}, 
                 {1, 0, 0, 0}, 
                 {1, 3, 5, 4}, 
                 {0, 6, 3, 2}, 
                 {0, 0, 1, 4}}; 
isSafe(processes, avail, max, alloc); 
return 0; 
} 
