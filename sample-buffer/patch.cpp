#pragma XOD require "https://github.com/WaylandM/RunningMedian"

#include <RunningMedian.h>

node {
    meta {
        using Type = RunningMedian*;
    }

    uint8_t mem[sizeof(RunningMedian)];

    void evaluate(Context ctx) {
        if (!isSettingUp())
            return;

        uint8_t sampleSize = getValue<input_Size>(ctx);

        Type samples = new (mem) RunningMedian(sampleSize);

        emitValue<output_Buffer>(ctx, samples);

    }
}
