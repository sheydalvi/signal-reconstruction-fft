#include "utils.hpp"
#include <fstream>

// save original and reconstructed signals side by side
void save_to_csv(const std::string& filename, const std::vector<double>& original, const std::vector<double>& reconstructed, double sampling_rate) {
    std::ofstream file(filename);
    file << "time,original,reconstructed\n";

    for (size_t i = 0; i < original.size() && i < reconstructed.size(); ++i) {
        double t = i / sampling_rate;
        file << t << "," << original[i] << "," << reconstructed[i] << "\n";
    }

    file.close();
}
