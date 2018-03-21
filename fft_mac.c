#include "kiss_fftr.h"

float* fft(float *samples, int nSamples, int tickCount)
{
    // much initialization
    kiss_fftr_cfg kiss_fftr_state;
    kiss_fft_scalar *rin = malloc(sizeof(kiss_fft_scalar)*nSamples);
    kiss_fft_cpx *sout = malloc(sizeof(kiss_fft_cpx)*nSamples);
    kiss_fft_scalar zero;
    memset(&zero, 0, sizeof(zero));

    // float array -> kiss_fft_scalar array
    int i;
    for (i=0;i<nSamples;++i) {
        rin[i] = samples[i];
    }

    kiss_fftr_state = kiss_fftr_alloc(nSamples, 0, NULL, NULL);
    kiss_fftr(kiss_fftr_state, rin, sout); // generate fft
    free(kiss_fftr_state);

    // complex sample to normalized sample using pythagorean theorem
    for (i=0; i<tickCount; ++i) {
      samples[i] = fabs(2*sqrt((sout[i].r)*(sout[i].r) + (sout[i].i)*(sout[i].i)))/nSamples;
    }

    free(sout);
    free(rin);

    return samples;
}
