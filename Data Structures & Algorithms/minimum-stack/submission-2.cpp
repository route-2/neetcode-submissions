class MinStack {
public:

    // This always stores the CURRENT minimum value in the stack
    // We keep it separate so getMin() is O(1)
    long min;

    // This stack does NOT store actual values
    // It stores: (value - min_at_the_time_of_push)
    std::stack<long> stack;

    MinStack() {
        // Nothing to initialize here
        // min will be set when the first value is pushed
    }
    
    void push(int val) {

        // If stack is empty, this is the FIRST element
        if (stack.empty()) {

            // We push 0 because:
            // value - min = val - val = 0
            // This means the first value equals the min
            stack.push(0);

            // Set min to this value
            min = val;

        } else {

            // Store the difference between this value and current min
            // This difference is the ONLY thing we store in the stack
            stack.push(val - min);

            // If the new value is smaller than current min,
            // then this value becomes the new minimum
            if (val < min) {
                min = val;
            }
        }
    }
    
    void pop() {

        // Nothing to do if stack is empty
        if (stack.empty()) return;

        // Get the stored difference from the stack
        long pop = stack.top();
        stack.pop();

        // If the difference is NEGATIVE:
        // This means this element CREATED a new minimum when it was pushed
        // So when we remove it, we must RESTORE the OLD minimum
        if (pop < 0) {

            // pop = (newMin - oldMin)
            // current min = newMin
            // oldMin = newMin - pop
            min = min - pop;
        }
    }
    
    int top() {

        // Get the difference stored at the top
        long top = stack.top();

        // If the difference is POSITIVE:
        // actual value = min + difference
        if (top > 0) {
            return (int)(top + min);
        }

        // If the difference is ZERO or NEGATIVE:
        // this element IS the minimum itself
        return (int)min;
    }
    
    int getMin() {

        // min always holds the correct minimum
        return (int)min;
    }
};
