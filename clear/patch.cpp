
node {
    void evaluate(Context ctx) {
        if (isInputDirty<input_UPD>(ctx)) {
            auto samples = getValue<input_Buffer>(ctx);
            samples -> clear();
            emitValue<output_Done>(ctx, 1);
        }
    }
}
