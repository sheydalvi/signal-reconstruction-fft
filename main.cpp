#include <iostream>
#include <cstdlib>
#include "signal.hpp"
#include "fft_processor.hpp"
#include "utils.hpp"

int main() {
    double duration = 2.0; // seconds
    double sampling_rate = 500.0; // Hz

    // generate the original signal
    auto signal = generate_signal(duration, sampling_rate);

    // perform fft
    auto freq_domain = perform_fft(signal);

    // keep only top n coefficients
    int top_n = 10;
    keep_top_coefficients(freq_domain, top_n);

    // perform ifft
    auto reconstructed_signal = perform_ifft(freq_domain);

    // save results
    save_to_csv("data/output.csv", signal, reconstructed_signal, sampling_rate);

    std::cout << "signal processing complete, results saved to data/output.csv\n";

    std::system("python3 plot_results.py");

    return 0;
}
