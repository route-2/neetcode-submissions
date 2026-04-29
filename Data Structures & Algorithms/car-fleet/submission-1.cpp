class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        // cars[i] = {position, speed}
        vector<pair<int,int>> cars;
        for (int i = 0; i < (int)position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort by position descending: closest to target first
        sort(cars.rbegin(), cars.rend());

        // fleetTimes acts like a stack:
        // fleetTimes[k] = time for the k-th fleet (from front to back)
        vector<double> fleetTimes;

        for (auto &car : cars) {
            int pos = car.first;
            int spd = car.second;

            // time for THIS car to reach target if it drove alone
            double timeToTarget = (double)(target - pos) / spd;

            // assume it forms a new fleet (push it)
            fleetTimes.push_back(timeToTarget);

            // If the car behind arrives earlier/same than the fleet in front,
            // it catches up -> merges -> remove its time (no new fleet)
            int m = fleetTimes.size();
            if (m >= 2 && fleetTimes[m - 1] <= fleetTimes[m - 2]) {
                fleetTimes.pop_back();
            }
        }

        return (int)fleetTimes.size();
    }
};
