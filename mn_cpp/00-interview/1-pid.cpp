class PID
{
public:
    double k_p, k_i, k_d;
    double *P, *I, *D, *prevError;
    double T;
    double *control;

    PID(double KP, double KI, double KD) : k_p(KP), k_i(KI), k_d(KD)
    {
        *control = 0;
    }

    void proportional(double &setpoint, double &measurement)
    {
        *P = (setpoint - measurement) * k_p;
    }

    void integrate(double &setpoint, double &measurement)
    {
        *I += (setpoint - measurement) * T;
    }

    void differentiate(double &setpoint, double &measurement)
    {
        *D = ((setpoint - measurement) - *prevError) / T;
        *prevError = setpoint - measurement;
    }

    float update_control(double &setpoint, double &measurement)
    {
        this->proportional(setpoint, measurement);
        this->integrate(setpoint, measurement);
        this->differentiate(setpoint, measurement);

        *control = *P + *I + *D;
        return *control;
    }
};

int main() {}
