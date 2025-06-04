#pragma once
#include <vector>
#include <complex>

// perform fft on a real signal
std::vector<std::complex<double>> perform_fft(const std::vector<double>& signal);

// perform ifft on complex coefficients
std::vector<double> perform_ifft(const std::vector<std::complex<double>>& freq_domain);

// keep only top n coefficients by magnitude
void keep_top_coefficients(std::vector<std::complex<double>>& freq_domain, int n);
