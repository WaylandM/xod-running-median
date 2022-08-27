#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        if (isInputDirty<input_UPD>(ctx)) {
            auto samples = getValue<input_Buffer>(ctx);
            auto avg = samples -> getAverage();
            emitValue<output_Mean>(ctx, avg);
            emitValue<output_Done>(ctx, 1);
        }
    }
}
