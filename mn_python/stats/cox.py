import numpy as np
import matplotlib.pyplot as plt


def h0_risk():
    """
    Simulates risk hazard h0_risk
    """
    # Simulated baseline hazard function over 10 time units
    time = np.arange(1, 11)  # time points 1 to 10
    baseline_hazard = np.array(
        [0.02, 0.03, 0.04, 0.05, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1]
    )

    # Calculate cumulative hazard by summing hazard * delta time (here delta time = 1)
    cumulative_hazard = np.cumsum(baseline_hazard)

    # Baseline survival function: S0(t) = exp(- cumulative hazard)
    baseline_survival = np.exp(-cumulative_hazard)

    # Plot baseline hazard plt.figure(figsize=(12, 5))
    plt.subplot(1, 2, 1)
    plt.plot(time, baseline_hazard, marker="o", color="red")
    plt.title("Baseline Hazard Function $h_0(t)$")
    plt.xlabel("Time")
    plt.ylabel("Hazard (Instantaneous Risk)")
    plt.grid(True)

    # Plot baseline survival
    plt.subplot(1, 2, 2)
    plt.plot(time, baseline_survival, marker="o", color="blue")
    plt.title("Baseline Survival Function $S_0(t)$")
    plt.xlabel("Time")
    plt.ylabel("Survival Probability")
    plt.ylim(0, 1.05)
    plt.grid(True)

    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    h0_risk()
