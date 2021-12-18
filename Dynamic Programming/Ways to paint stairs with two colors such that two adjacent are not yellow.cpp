// https://www.geeksforgeeks.org/ways-paint-stairs-two-colors-two-adjacent-not-yellow/

// Same as Fibonacci = https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

int ways(int n)
{
    int W[n + 1];
 
    // take base case for 1 and 2
    W[1] = 2;
    W[2] = 3;
 
    for (int i = 3; i <= n; i++)
        W[i] = W[i - 1] + W[i - 2];
     
    return W[n];
}


