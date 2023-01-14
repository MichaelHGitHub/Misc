#include <stdint.h>
#include <vector>
#include <iostream>

using namespace std;

int EatApples(int n, const int* numbers, int h);

int main(int argi, char** argc) {
    int n = 5;
    int h = 5;
    vector<int> numbers({30, 11, 23, 4, 20});
    cout << "Ms. Yuan has to eat at lest:" << EatApples(n, numbers.data(), h) << " per hour." << endl;
}

// Assume a_max and a_min are the numbers of apples
// in the biggest and smallest pile. The eating speed must be
// in the range of [a_min, a_max].
// Do a binary search to find an estimate speed such the teacher
// can finish eating all the apples in h hours.
int EatApples(int n, const int* numbers, int h) {
    // Find our max and min number in the piles.
    int num_max = INT32_MIN;
    int num_min = INT32_MAX;
    for (int i = 0; i < n; i++) {
        num_max = max(num_max, numbers[i]);
        num_min = min(num_min, numbers[i]);
    }

    // Use binary search to find the speed.
    int speed = 0;
    int low = num_min, high = num_max;
    while (low <= high) {
        int estimate_hour = 0;
        // Try mid-value of [min, max]
        int mid = (low + high) / 2;
        // calculate the total estimate hours
        for (int i = 0; i < n; i++) {
            if (mid >= numbers[i]) {
                ++estimate_hour;
            }
            else {
                estimate_hour += (numbers[i] / mid);
                if (numbers[i] % mid > 0) {
                    ++estimate_hour;
                }
            }
            if (estimate_hour > h) {
                break;
            }
        }
        // check if estimate hours equals h, if yes, mid
        // is the speed we have been looking for.
        if (estimate_hour == h) {
            speed = mid;
            break;
        }
        else if (estimate_hour > h) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return speed;
}
