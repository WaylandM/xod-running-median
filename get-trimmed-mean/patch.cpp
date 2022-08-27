#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        if (isInputDirty<input_UPD>(ctx)) {
            auto samples = getValue<input_Buffer>(ctx);
            auto N = getValue<input_N>(ctx);
            emitValue<output_tMean>(ctx, samples -> getAverage(N));
            emitValue<output_Done>(ctx, 1);
        }
    }
}
