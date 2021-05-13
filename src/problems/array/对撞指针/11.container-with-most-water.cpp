/*!
 * @brief https://leetcode-cn.com/problems/container-with-most-water/
 * Time: O(n)
 * Space: O(1)
 */
int maxArea(vector<int>& height) {
  int i = 0;
  int j = height.size() - 1;
  int area = 0;
  while (i < j) {
    if (height[i] <= height[j]) {
      if ((height[i] * (j - i)) > area) {
        area = height[i] * (j - i);
      }
      ++i;
    } else {
      if ((height[j] * (j - i)) > area) {
        area = height[j] * (j - i);
      }
      --j;
    }
  }
  return area;
}
