#include <iostream>
#include <cmath>
#include <windows.h> // Для русификации консоли

using namespace std;

const double PI = 3.141592653589793;

class SignalGenerator {
protected:
    double amplitude; 
    double frequency; 
    double phase;     

public:
    SignalGenerator(double amp = 1.0, double freq = 1.0, double ph = 0.0)
        : amplitude(amp), frequency(freq), phase(ph) {
    }

    virtual ~SignalGenerator() {}

   
    virtual double getAmplitude() const { return amplitude; }
    virtual void setAmplitude(double amp) { amplitude = amp; }
    virtual double getFrequency() const { return frequency; }
    virtual void setFrequency(double freq) { frequency = freq; }
    virtual double getPhase() const { return phase; }
    virtual void setPhase(double ph) { phase = ph; }

   
    virtual double calculate(double time) const = 0;

    
    virtual void printInfo() const {
        cout << "Генератор сигнала" << endl;
    }

   
    virtual void generateAndPrint(int count, double timeStep) const {
        double t = 0.0;
        for (int i = 0; i < count; i++) {
            cout << "t = " << t << " сек -> " << calculate(t) << endl;
            t += timeStep;
        }
    }
};

class SineGenerator : public SignalGenerator {
public:
    SineGenerator(double amp, double freq, double ph)
        : SignalGenerator(amp, freq, ph) {
    }

    double calculate(double time) const override {
        return amplitude * sin(2 * PI * frequency * time + phase);
    }

    void printInfo() const override {
        cout << "Синусоидальный генератор" << endl;
    }
};

class SquareGenerator : public SignalGenerator {
public:
    SquareGenerator(double amp, double freq, double ph)
        : SignalGenerator(amp, freq, ph) {
    }

    double calculate(double time) const override {
        double s = sin(2 * PI * frequency * time + phase);
        return (s >= 0) ? amplitude : -amplitude;
    }

    void printInfo() const override {
        cout << "Генератор прямоугольного сигнала" << endl;
    }
};

class TriangleGenerator : public SignalGenerator {
public:
    TriangleGenerator(double amp, double freq, double ph)
        : SignalGenerator(amp, freq, ph) {
    }

    double calculate(double time) const override {
        return (2 * amplitude / PI) * asin(sin(2 * PI * frequency * time + phase));
    }

    void printInfo() const override {
        cout << "Генератор треугольного сигнала" << endl;
    }
};

int main() {
   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int GENERATOR_COUNT = 3;
    SignalGenerator* generators[GENERATOR_COUNT];

    generators[0] = new SineGenerator(1.0, 2.0, 0.0);
    generators[1] = new SquareGenerator(1.0, 2.0, 0.0);
    generators[2] = new TriangleGenerator(1.0, 2.0, 0.0);

    for (int i = 0; i < GENERATOR_COUNT; i++) {
        generators[i]->printInfo();
        generators[i]->generateAndPrint(15, 0.5);
        cout << "------------------------" << endl;
    }

    
    SignalGenerator* signal = new SineGenerator(0.5, 1.0, 0.0);
    cout << "Значение в t = 0.5: " << signal->calculate(0.5) << endl;
    delete signal;

    signal = new SquareGenerator(0.5, 1.0, 0.0);
    cout << "Значение в t = 0.5: " << signal->calculate(0.5) << endl;
    delete signal;

   
    for (int i = 0; i < GENERATOR_COUNT; i++) {
        delete generators[i];
    }

    return 0;
}
