import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('data/output.csv')

# plot
plt.figure(figsize=(10, 6))
plt.plot(data['time'], data['original'], label='original')
plt.plot(data['time'], data['reconstructed'], label='reconstructed', linestyle='--')
plt.xlabel('time (s)')
plt.ylabel('amplitude')
plt.title('signal reconstruction using top Fourier coefficients')
plt.legend()
plt.grid(True)

plt.savefig('data/output_plot.png')
