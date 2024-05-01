#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Returns the maximum amount of water that can be trapped between the two
// given bars
int trap(vector<int>& height) {
  int n = height.size();
  if (n == 0) {
    return 0;
  }

  // Initialize left and right max heights
  vector<int> leftMax(n, 0);
  vector<int> rightMax(n, 0);

  // Initialize result
  int waterTrapped = 0;

  // Fill leftMax and rightMax arrays
  for (int i = 1; i < n; i++) {
    leftMax[i] = max(leftMax[i - 1], height[i - 1]);
    rightMax[n - i - 1] = max(rightMax[n - i], height[n - i]);
  }

  // Calculate water between bars
  for (int i = 0; i < n; i++) {
    waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
  }

  return waterTrapped;
}

int main() {
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << trap(height) << endl;
  return 0;
}