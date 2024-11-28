#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[]) {
    int n, m;

    std::cin >> n >> m;
    
    std::vector<float> prices(n), costs(m), limits(m);
    std::vector<std::vector<float>> compositions(n, std::vector<float>(m));

    // Read prices
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }
    
    // Read costs and limits
    for (int i = 0; i < m; i++) {
        std::cin >> costs[i] >> limits[i];
    }

    // Read compositions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> compositions[i][j];
        }
    }

    // Output to the file
    std::ofstream output(argv[1]);

    // Print objective function (maximization)
    output << "max: ";
    for (int i = 0; i < n - 1; i++) {
        output << prices[i] << " x" << i + 1;
        output << " + ";
    }

    output << prices[n - 1] << " x" << n << ";\n";
    
    // Print the constraints
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            output << compositions[i][j] << " x" << i + 1;
            if (i < n - 1) {
                output << " + ";
            }
        }

        output << " <= " << limits[j] << ";\n";
    }

    // Print the non-negativity constraints
    for (int i = 0; i < n; ++i) {
        output << "x" << i + 1 << " >= 0;\n";
    }

    return 0;
}
