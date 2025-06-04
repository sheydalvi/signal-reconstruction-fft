#include "fft_processor.hpp"
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

// perform in-place fft
void fft_recursive(std::vector<std::complex<double>>& a) {
    int n = a.size();
    if (n <= 1) return;

    // divide
    std::vector<std::complex<double>> even(n/2), odd(n/2);
    for (int i = 0; i < n/2; ++i) {
        even[i] = a[i*2];
        odd[i] = a[i*2 + 1];
    }

    // conquer
    fft_recursive(even);
    fft_recursive(odd);

    // combine
    for (int k = 0; k < n/2; ++k) {
        std::complex<double> t = std::polar(1.0, -2 * M_PI * k / n) * odd[k];
        a[k] = even[k] + t;
        a[k + n/2] = even[k] - t;
    }
}

// perform in-place ifft
void ifft_recursive(std::vector<std::complex<double>>& a) {
    for (auto& x : a) x = std::conj(x);
    fft_recursive(a);
    for (auto& x : a) x = std::conj(x) / static_cast<double>(a.size());
}

// perform fft on a real signal
std::vector<std::complex<double>> perform_fft(const std::vector<double>& signal) {
    std::vector<std::complex<double>> freq_domain(signal.begin(), signal.end());
    fft_recursive(freq_domain);
    return freq_domain;
}

// perform ifft on complex coefficients
std::vector<double> perform_ifft(const std::vector<std::complex<double>>& freq_domain) {
    std::vector<std::complex<double>> temp = freq_domain;
    ifft_recursive(temp);

    std::vector<double> time_signal(temp.size());
    for (size_t i = 0; i < temp.size(); ++i) {
        time_signal[i] = temp[i].real();
    }

    return time_signal;
}

// keep only top n coefficients by magnitude
void keep_top_coefficients(std::vector<std::complex<double>>& freq_domain, int n) {
    std::vector<std::pair<double, int>> magnitudes;

    for (int i = 0; i < freq_domain.size(); ++i) {
        double mag = std::abs(freq_domain[i]);
        magnitudes.push_back({mag, i});
    }

    // sort by magnitude descending
    std::sort(magnitudes.begin(), magnitudes.end(), [](auto& a, auto& b) {
        return a.first > b.first;
    });

    std::vector<bool> keep(freq_domain.size(), false);
    for (int i = 0; i < n && i < magnitudes.size(); ++i) {
        keep[magnitudes[i].second] = true;
    }

    // zero out the coefficients we don't want
    for (int i = 0; i < freq_domain.size(); ++i) {
        if (!keep[i]) {
            freq_domain[i] = {0.0, 0.0};
        }
    }
}
