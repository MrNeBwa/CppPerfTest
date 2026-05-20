# CppPerfTrack 🚀

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.10+-brightgreen.svg)
![Python](https://img.shields.io/badge/Python-3.6+-yellow.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

**CppPerfTrack** is a lightweight system profiling and performance tracking CLI tool written in C++. It seamlessly measures execution time, maximum memory footprint, and CPU time of any shell command or script. The results are exported to JSON, which can then be visualized using the included Python dashboard script.

---

## ✨ Features

- **Accurate Profiling**: Leverages `fork`/`exec` and `getrusage` for robust process measurement.
- **Multiple Metrics**: Captures Wall-clock duration (ms), Max Memory Usage (KB), and CPU time (ms).
- **Extensible Storage**: Easily swap or extend the storage layer (currently supports JSON, ready for SQLite).
- **Visual Dashboard**: Automatically generates beautiful Matplotlib charts from your benchmark runs.
- **Lightweight & Fast**: Minimal dependencies, pure C++17 core.

## 📂 Project Structure

```text
CppPerfTrack/
├── CMakeLists.txt        # Build configuration
├── include/              # Header files (.hpp)
│   ├── Metric.hpp        # Data structures
│   ├── Storage.hpp       # Storage interfaces
│   ├── JsonStorage.hpp   # JSON implementation
│   └── Profiler.hpp      # Core profiling logic
├── src/                  # Source files (.cpp)
│   ├── JsonStorage.cpp
│   ├── Profiler.cpp
│   └── main.cpp          # CLI Entry point
└── scripts/              # Data visualization utilities
    ├── dashboard.py
    └── requirements.txt
```

## 🛠️ Prerequisites

To build and run **CppPerfTrack**, you will need:
- Compiler with **C++17** support (GCC, Clang, or MSVC)
- **CMake** (v3.10 or higher)
- **Python 3.6+** (for the visualization dashboard)
- (Optional) Unix-like system (Linux/macOS) for `getrusage` support.

## 🚀 Installation & Build

Build the C++ CLI tool:

```bash
# 1. Clone the repository
git clone https://github.com/your-username/CppPerfTrack.git
cd CppPerfTrack

# 2. Configure with CMake and build
mkdir build && cd build
cmake ..
make
```

Install Python dependencies for the dashboard:

```bash
cd ..
pip install -r scripts/requirements.txt
```

## 📖 Usage

### 1. Profiling a Command (C++ CLI)

Run the executable and pass a custom label along with the command you want to profile.

```bash
cd build
./CppPerfTrack "List Files" "ls -la"
./CppPerfTrack "Heavy Math Script" "python ../scripts/heavy_math.py"
```

*This will automatically generate a `metrics.json` file in your current directory containing the profiling data.*

### 2. Generating the Dashboard (Python)

Once you have gathered some metrics, generate a visual report:

```bash
python scripts/dashboard.py --input build/metrics.json
```

*A file named `report.png` will be created, containing side-by-side bar charts of Execution Time (ms) and Max Memory Usage (KB).*

## 📈 Example Output

**`metrics.json`**
```json
[
  {
    "name": "List Files",
    "duration_ms": 12.45,
    "memory_kb": 3216,
    "cpu_time_ms": 2.1,
    "timestamp": "2025-10-15 10:15:30"
  }
]
```

## 🤝 Contributing

Contributions are welcome!
1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📄 License

Distributed under the MIT License. See `LICENSE` for more information.
