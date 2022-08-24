
node {
    void evaluate(Context ctx) {
        if (isInputDirty<input_UPD>(ctx)) {
            auto samples = getValue<input_Buffer>(ctx);
            emitValue<output_Lowest>(ctx, samples -> getLowest());
            emitValue<output_Done>(ctx, 1);
        }
    }
}
