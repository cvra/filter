
/**  biquad filter
 H(z) = (b0 + b1*z^-1 + b2*z^-2) / (1 + a1*z^-1 + a2*z^-2)
 y[n] = b0*x[n] + b1*x[n-1] + b2*[n-2] - a1*y[n-1] - a2*y[n-2]
*/

typedef struct {
	// coefficients
	float b0, b1, b2;
	float a1, a2;
	// delays
	float d1, d2;
} filt_biquad_t;


void filt_biquad_init_manual(filt_biquad_t *f, float b0, float b1, float b2
							 float a1, float a2);

void filt_biquad_init_lp(filt_biquad_t *f, float Fs, float Fc, float Q);

float filt_biquad_apply(filt_biquad_t *f, float in)
{
	float out;
	out = f->b0 * in + d1;
	// update filter
	f->d1 = f->b1 * in + f->a1 * out + f->d2;
	f->d2 = f->b2 * in + f->a2 * out;
	return out;
}
