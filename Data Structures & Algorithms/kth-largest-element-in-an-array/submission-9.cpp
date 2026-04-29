class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        // We want the k-th LARGEST.
        // If nums were sorted ascending (small -> big),
        // the k-th largest would be at index (n - k).
        // Example: n=6, k=2 -> index = 4 (0-based) -> 2nd largest.
        int target = n - k;

        int left = 0;
        int right = n - 1;

        // We keep shrinking the search window [left..right]
        // until the pivot lands exactly at 'target'.
        while (true) {
            // Pick a random pivot INDEX inside current window.
            // (right-left+1) is how many elements are in the window.
            // rand()%size gives 0..size-1, then +left shifts to left..right.
            int pivotIx = rand() % (right - left + 1) + left;

            // Partition the array around pivot value.
            // After partition:
            // - pivot ends up at index newPivot
            // - everything left of newPivot is < pivot
            // - everything right of newPivot is >= pivot
            int newPivot = partition(nums, left, right, pivotIx);

            // If pivot is exactly at target index, that's our answer.
            if (newPivot == target) {
                return nums[newPivot];
            }
            // If pivot landed too far right, answer is on the left side.
            else if (newPivot > target) {
                right = newPivot - 1;
            }
            // If pivot landed too far left, answer is on the right side.
            else {
                left = newPivot + 1;
            }
        }
    }

private:
    int partition(vector<int>& nums, int left, int right, int pivotIx) {
        // Pivot VALUE we compare everything against.
        int pivot = nums[pivotIx];

        // Move pivot value to the end (index right) so it doesn't get disturbed
        // while we rearrange the other elements.
        swap(nums[pivotIx], nums[right]);

        // curr = the next position where we should place a value < pivot.
        int curr = left;

        // Scan through the window except the pivot at the end.
        for (int i = left; i < right; i++) {
            // If nums[i] belongs to the "smaller than pivot" group...
            if (nums[i] < pivot) {
                // ...put it at nums[curr], and grow the "< pivot" group.
                swap(nums[i], nums[curr]);
                curr++;
            }
            // Else (>= pivot), leave it on the right side for now.
        }

        // Now curr is the first position where pivot should go.
        // Put pivot back from the end into its final position at curr.
        swap(nums[curr], nums[right]);

        // Return the pivot’s final index.
        return curr;
    }
};
