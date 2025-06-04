#include "signal.hpp"
#include <cmath>

// generate a signal composed of multiple sine waves
std::vector<double> generate_signal(double duration, double sampling_rate) {
    int total_samples = static_cast<int>(duration * sampling_rate);

    // adjust total_samples to next power of 2
    int n = 1;
    while (n < total_samples) n *= 2;
    total_samples = n;

    std::vector<double> signal(total_samples);

    // define frequencies and amplitudes
    std::vector<double> frequencies = {5.0, 20.0, 50.0}; // in Hz
    std::vector<double> amplitudes = {1.0, 0.5, 0.2};

    for (int i = 0; i < total_samples; ++i) {
        double t = i / sampling_rate;
        double value = 0.0;
        for (size_t j = 0; j < frequencies.size(); ++j) {
            value += amplitudes[j] * std::sin(2 * M_PI * frequencies[j] * t);
        }
        signal[i] = value;
    }

    return signal;
}
