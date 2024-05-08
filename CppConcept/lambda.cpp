#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    // Lambda function that takes two integers and returns their sum
    auto add = [](auto a, auto b) {
        return a + b;
    };

    // Call the lambda function
    int result = add(5, 3);
    std::cout << "Result: " << result << std::endl;
    
    auto isEven = [](int x) { return x % 2 == 0; };
    auto it = std::find_if(nums.begin(), nums.end(), isEven);

    return 0;
}
