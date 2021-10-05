#ifndef CPU_H
#define CPU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CPU; }
QT_END_NAMESPACE

class CPU : public QMainWindow
{
    Q_OBJECT

public:
    CPU(QWidget *parent = nullptr);
    ~CPU();
    const static int NUM_CPU_STATES = 10;
    enum CPUStates
    {
        S_USER = 0,
        S_NICE,
        S_SYSTEM,
        S_IDLE,
        S_IOWAIT,
        S_IRQ,
        S_SOFTIRQ,
        S_STEAL,
        S_GUEST,
        S_GUEST_NICE
    };
    typedef struct CPUData
    {
        std::string cpu;
        size_t times[NUM_CPU_STATES];
    } CPUData;

    CPU();
    void ReadStatsCPU(std::vector<CPUData> & entries);
    size_t GetIdleTime(const CPUData & e1, const CPUData & e2);
    size_t GetActiveTime(const CPUData & e1, const CPUData & e2);
    size_t GetIdleTime(const CPUData & e);
    size_t GetActiveTime(const CPUData & e);

    void PrintStats(const std::vector<CPUData> & entries1, const std::vector<CPUData> & entries2);



private:
    Ui::CPU *ui;
};
#endif // CPU_H
