class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // freq[i] = how many times task ('A' + i) appears
        int freq[26] = {0};
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Sort frequencies in ascending order.
        // After sorting:
        // - freq[25] is the largest frequency (most frequent task count).
        sort(begin(freq), end(freq));

        // remaining = number of "gaps" BETWEEN occurrences of the most frequent task.
        // IMPORTANT: this is NOT "how many of that task are left to execute".
        //
        // If the max frequency task appears maxFreq times, placing only that task looks like:
        //   A _ A _ A _ A   (maxFreq times)
        // The number of gaps "_" between them is (maxFreq - 1).
        int remaining = freq[25] - 1;

        // Each gap must have 'n' slots (cooldown distance).
        // These are initially "empty slots" that must be filled by other tasks,
        // otherwise they become idle cycles.
        int idle = remaining * n;

        // Try to fill those empty slots using other tasks.
        // A task type with frequency f can fill at most ONE slot in each gap,
        // so it can fill at most 'remaining' total slots across all gaps.
        for (int i = 24; i >= 0; i--) {
            idle -= min(remaining, freq[i]);
        }

        // If idle <= 0, we had enough tasks to fill all gap slots -> no idles needed.
        // If idle > 0, those slots must be real idle cycles.
        if (idle < 0) idle = 0;
        return (int)tasks.size() + idle;
    }
};
