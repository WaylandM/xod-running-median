
node {
    void evaluate(Context ctx) {
        if (isInputDirty<input_UPD>(ctx)) {
            auto samples = getValue<input_Buffer>(ctx);
            samples -> add(getValue<input_New>(ctx));
            emitValue<output_Done>(ctx, 1);
        }
    }
}
