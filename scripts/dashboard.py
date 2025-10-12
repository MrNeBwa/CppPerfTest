import json
import matplotlib.pyplot as plt
import os
import argparse

def load_metrics(filepath):
    if not os.path.exists(filepath):
        return []
    with open(filepath, 'r') as f:
        return json.load(f)

def plot_metrics(metrics):
    if not metrics:
        print("No metrics to plot.")
        return

    names = [m['name'] for m in metrics]
    durations = [m['duration_ms'] for m in metrics]
    memories = [m['memory_kb'] for m in metrics]

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))

    ax1.bar(names, durations, color='skyblue')
    ax1.set_title('Execution Time (ms)')
    ax1.set_ylabel('ms')

    ax2.bar(names, memories, color='lightgreen')
    ax2.set_title('Max Memory Usage (KB)')
    ax2.set_ylabel('KB')

    plt.tight_layout()
    plt.savefig('report.png')
    print("Report saved to report.png")
    # plt.show() # Disabled for non-interactive environments

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate performance report.")
    parser.add_argument("--input", default="metrics.json", help="Path to metrics.json")
    args = parser.parse_args()

    data = load_metrics(args.input)
    plot_metrics(data)
