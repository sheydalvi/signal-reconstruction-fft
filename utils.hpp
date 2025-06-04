#pragma once
#include <vector>
#include <string>

// save original and reconstructed signal to a csv file
void save_to_csv(const std::string& filename, const std::vector<double>& original, const std::vector<double>& reconstructed, double sampling_rate);
