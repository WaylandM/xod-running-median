#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        if (isInputDirty<input_UPD>(ctx)) {
            auto samples = getValue<input_Buffer>(ctx);
            float newValue = getValue<input_New>(ctx);
            samples -> add(newValue);
            emitValue<output_Done>(ctx, 1);
        }
    }
}
