# FFT Signal Reconstruction

this project performs signal reconstruction using a custom fft implementation in standard C++, with no external fft libraries. results are visualized using python.



## how it works

- generates a synthetic signal (sum of sine waves)
- performs fft and inverse fft using a recursive implementation written entirely in C++
- filters by keeping only the top-n frequency components
- reconstructs and saves the signal to `data/output.csv`
- calls a python script to plot original vs reconstructed signal and save `data/output_plot.png`


## project structure

```code

main.cpp                   
signal.hpp/.cpp             # generates the input signal
fft_processor.hpp/.cpp      # custom fft, ifft, and coefficient filtering
utils.hpp/.cpp              # csv export helpers
plot_results.py             # python visualization script
data/                       # output folder for csv and plot
.gitignore                  
README.md                   

````


## build and run

```bash
g++ -std=c++11 main.cpp signal.cpp fft_processor.cpp utils.cpp -o fft_reconstruct
./fft_reconstruct
```

this saves the output csv and automatically runs the python script to produce a plot

* `data/output.csv`: time, original, and reconstructed signal values
* `data/output_plot.png`: plot showing original vs reconstructed waveform


