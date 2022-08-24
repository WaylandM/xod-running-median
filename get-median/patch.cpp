
node {
    void evaluate(Context ctx) {
        if (isInputDirty<input_UPD>(ctx)) {
            auto samples = getValue<input_Buffer>(ctx);
            emitValue<output_Median>(ctx, samples -> getMedian());
            emitValue<output_Done>(ctx, 1);
        }
    }
}
