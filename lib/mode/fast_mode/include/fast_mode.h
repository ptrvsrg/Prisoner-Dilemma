#ifndef TASK2_FAST_MODE_H
#define TASK2_FAST_MODE_H

#include <iomanip>

#include "abstract_mode.h"

class FastMode : public Mode
{
public:
    FastMode(const std::vector<std::string> & strategy_names,
             int steps,
             const std::string & config_dir,
             Matrix matrix);
    void Launch() override;
private:
    void PrintScores();
};

#endif //TASK2_FAST_MODE_H
