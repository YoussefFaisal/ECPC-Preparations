#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int ll;


// Distination Between two points
double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}


// Check if it valid triangle with 3 length sides
bool is_triangle(int a, int b, int c){
    return (a + b > c) && (a + c > b) && (b + c > a) && (a && b && c);
}


// Get Slope of two points
double slope(double x1, double y1, double x2, double y2){
    if(x2 == x1) return 0;
    return (y2 - y1) / (x2 - x1);
}


// Check if three points in the same line
bool is_same_line(int x1, int y1, int x2, int y2, int x3, int y3){
    return (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1);
}


// Extended Euclidean Algorithm
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int ret = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return ret;
}



int main(){}