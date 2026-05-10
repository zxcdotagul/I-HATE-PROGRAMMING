#include "research_cond.h"
#include <cmath>
#include <algorithm>

const double PI = 3.14159265358979323846;

CircuitWork::CircuitWork(const ParamCircuit& valueElements, const ParamVoltSource& voltage, double step, double freq, double maxT)
    : stepTime(step), frequency(freq), maxTime(maxT), sw1Closed(false), sw2Closed(false) {
    schemeParam = new ParamCircuit(valueElements._C1, valueElements._R1, valueElements._R2);
    voltageSource = new ParamVoltSource(voltage._E1, voltage._signalForm);
}

CircuitWork::~CircuitWork() {
    delete schemeParam;
    delete voltageSource;
}

double CircuitWork::tauCharge() const {
    return schemeParam->_R1 * schemeParam->_C1 / 1000.0;
}

double CircuitWork::tauDischarge() const {
    return schemeParam->_R2 * schemeParam->_C1 / 1000.0;
}

double CircuitWork::getSignalValue(double t, double amplitude, TypeSignal type) const {
    double period = 1.0 / frequency;
    double omega = 2.0 * PI * frequency;
    double t_mod = fmod(t, period);
    double t_rel = t_mod / period;

    switch (type) {
    case TypeSignal::sinus:
        return amplitude * sin(omega * t);

    case TypeSignal::meandr:
        return amplitude * ((t_mod < period / 2.0) ? 1.0 : -1.0);

    case TypeSignal::triangle:
        return amplitude * (2.0 * fabs(2.0 * t_rel - 1.0) - 1.0);

    case TypeSignal::sawtooth:
        return amplitude * (2.0 * t_rel - 1.0);

    case TypeSignal::halfSinus:
        if (t_mod < period / 2.0) {
            return amplitude * sin(omega * t);
        }
        return 0.0;

    case TypeSignal::doubleHalfSinus:
        return amplitude * fabs(sin(omega * t));

    case TypeSignal::constV:
    default:
        return amplitude;
    }
}

double CircuitWork::getChargeDischargeRC(double dt, double U_prev, double E1) const {
    double R_charge = schemeParam->_R1;
    double R_discharge = schemeParam->_R2;
    double C = schemeParam->_C1;

    double tau_charge = R_charge * C / 1000.0;
    double tau_discharge = R_discharge * C / 1000.0;

    if (E1 > U_prev + 0.001) {
        if (tau_charge > 0) {
            return E1 - (E1 - U_prev) * exp(-dt / tau_charge);
        }
    }
    else if (E1 < U_prev - 0.001) {
        if (tau_discharge > 0) {
            return U_prev * exp(-dt / tau_discharge);
        }
    }
    return U_prev;
}

double CircuitWork::getVoltageE1(double curTime) {
    return getSignalValue(curTime, voltageSource->_E1, voltageSource->_signalForm);
}

double CircuitWork::getVoltageCharge(double curTime) {
    double tau = tauCharge();
    double UM = voltageSource->_E1;
    if (tau > 0) {
        return UM * (1.0 - exp(-curTime / tau));
    }
    return 0.0;
}

double CircuitWork::getVoltageDischarge(double curTime) {
    double tau = tauDischarge();
    double UM = voltageSource->_E1;
    if (tau > 0) {
        return UM * exp(-curTime / tau);
    }
    return 0.0;
}

double CircuitWork::getVoltageC(double curTime) {
    double diff = stepTime;
    double U_prev = 0.0;

    for (double t = 0; t <= curTime; t += diff) {
        double E1 = getVoltageE1(t);
        U_prev = getChargeDischargeRC(diff, U_prev, E1);
    }
    return U_prev;
}

bool CircuitWork::toggle_SW1() {
    sw1Closed = !sw1Closed;
    return sw1Closed;
}

bool CircuitWork::status_SW1() const {
    return sw1Closed;
}

bool CircuitWork::switch_SW1(bool on) {
    sw1Closed = on;
    return sw1Closed;
}

bool CircuitWork::toggle_SW2() {
    sw2Closed = !sw2Closed;
    return sw2Closed;
}

bool CircuitWork::status_SW2() const {
    return sw2Closed;
}

bool CircuitWork::switch_SW2(bool on) {
    sw2Closed = on;
    return sw2Closed;
}

void CircuitWork::getVoltage(double curTime) {}

void CircuitWork::getVoltage(double curTime, bool statusSW1, bool statusSW2) {}

std::vector<std::pair<double, double>> CircuitWork::getSignalVolt() const {
    std::vector<std::pair<double, double>> result;
    for (double t = 0; t <= maxTime; t += stepTime) {
        double E1 = getSignalValue(t, voltageSource->_E1, voltageSource->_signalForm);
        result.emplace_back(t, E1);
    }
    return result;
}

std::vector<std::pair<double, double>> CircuitWork::getCapacitorVolt(bool charge, bool discharge) const {
    std::vector<std::pair<double, double>> result;

    if (charge && !discharge) {
        double tau = tauCharge();
        double UM = voltageSource->_E1;
        for (double t = 0; t <= maxTime; t += stepTime) {
            double U = (tau > 0) ? UM * (1.0 - exp(-t / tau)) : 0.0;
            result.emplace_back(t, U);
        }
    }
    else if (!charge && discharge) {
        double tau = tauDischarge();
        double UM = voltageSource->_E1;
        for (double t = 0; t <= maxTime; t += stepTime) {
            double U = (tau > 0) ? UM * exp(-t / tau) : 0.0;
            result.emplace_back(t, U);
        }
    }
    else {
        double U_prev = 0.0;
        double diff = stepTime;
        for (double t = 0; t <= maxTime; t += diff) {
            double E1 = getSignalValue(t, voltageSource->_E1, voltageSource->_signalForm);
            double U_cur = getChargeDischargeRC(diff, U_prev, E1);
            result.emplace_back(t, U_cur);
            U_prev = U_cur;
        }
    }

    return result;
}