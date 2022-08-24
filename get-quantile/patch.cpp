
node {
    void evaluate(Context ctx) {
        if (isInputDirty<input_UPD>(ctx)) {
            auto samples = getValue<input_Buffer>(ctx);
            auto quant = getValue<input_Quant>(ctx);
            emitValue<output_Value>(ctx, samples -> getQuantile(quant));
            emitValue<output_Done>(ctx, 1);
        }
    }
}
