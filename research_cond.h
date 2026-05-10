#ifndef RESEARCH_COND_H
#define RESEARCH_COND_H

#include <vector>
#include <utility>

enum class TypeSignal {
    constV = 0,
    meandr = 1,
    sinus = 2,
    triangle = 3,
    sawtooth = 4,
    halfSinus = 5,
    doubleHalfSinus = 6
};

// Структуры вынесены из класса (будут доступны везде)
struct ParamCircuit {
    double _C1;
    double _R1;
    double _R2;
    ParamCircuit(double C1, double R1, double R2) : _C1(C1), _R1(R1), _R2(R2) {}
};

struct ParamVoltSource {
    double _E1;
    TypeSignal _signalForm;
    ParamVoltSource(double E1, TypeSignal signal) : _E1(E1), _signalForm(signal) {}
};

class CircuitWork {
private:
    ParamCircuit* schemeParam;
    ParamVoltSource* voltageSource;
    double stepTime;
    double frequency;
    double maxTime;
    bool sw1Closed;
    bool sw2Closed;

    double tauCharge() const;
    double tauDischarge() const;
    double getSignalValue(double t, double amplitude, TypeSignal type) const;
    double getChargeDischargeRC(double dt, double U_prev, double E1) const;

public:
    CircuitWork() = delete;
    CircuitWork(const ParamCircuit& valueElements, const ParamVoltSource& voltage, double step = 0.001, double freq = 100.0, double maxT = 0.1);
    ~CircuitWork();

    double getVoltageC(double curTime);
    double getVoltageE1(double curTime);
    double getVoltageCharge(double curTime);
    double getVoltageDischarge(double curTime);

    bool toggle_SW1();
    bool status_SW1() const;
    bool switch_SW1(bool on);
    bool toggle_SW2();
    bool status_SW2() const;
    bool switch_SW2(bool on);

    void getVoltage(double curTime);
    void getVoltage(double curTime, bool statusSW1, bool statusSW2);

    std::vector<std::pair<double, double>> getSignalVolt() const;
    std::vector<std::pair<double, double>> getCapacitorVolt(bool charge, bool discharge) const;
};

#endif