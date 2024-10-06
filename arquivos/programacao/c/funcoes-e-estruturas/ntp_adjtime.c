


— Data Type: struct timex

    This structure is used to control and monitor the system clock. It contains the following members:

    unsigned int modes
        This variable controls whether and which values are set. Several symbolic constants have to be combined with binary or to specify the effective mode. These constants start with MOD_.
    long int offset
        This value indicates the current offset of the system clock from the true calendar time. The value is given in microseconds. If bit MOD_OFFSET is set in modes, the offset (and possibly other dependent values) can be set. The offset's absolute value must not exceed MAXPHASE.
    long int frequency
        This value indicates the difference in frequency between the true calendar time and the system clock. The value is expressed as scaled PPM (parts per million, 0.0001%). The scaling is 1 << SHIFT_USEC. The value can be set with bit MOD_FREQUENCY, but the absolute value must not exceed MAXFREQ.
    long int maxerror
        This is the maximum error, measured in microseconds. A new value can be set using bit MOD_MAXERROR. Unless updated via ntp_adjtime periodically, this value will increase steadily and reach some platform-specific maximum value.
    long int esterror
        This is the estimated error, measured in microseconds. This value can be set using bit MOD_ESTERROR.
    int status
        This variable reflects the various states of the clock machinery. There are symbolic constants for the significant bits, starting with STA_. Some of these flags can be updated using the MOD_STATUS bit.
    long int constant
        This value represents the bandwidth or stiffness of the PLL (phase locked loop) implemented in the kernel. The value can be changed using bit MOD_TIMECONST.
    long int precision
        This value represents the accuracy or the maximum error when reading the system clock. The value is expressed in microseconds.
    long int tolerance
        This value represents the maximum frequency error of the system clock in scaled PPM. This value is used to increase the maxerror every second.
    struct timeval time
        The current calendar time.
    long int tick
        The elapsed time between clock ticks in microseconds. A clock tick is a periodic timer interrupt on which the system clock is based.
    long int ppsfreq
        This is the first of a few optional variables that are present only if the system clock can use a PPS (pulse per second) signal to discipline the system clock. The value is expressed in scaled PPM and it denotes the difference in frequency between the system clock and the PPS signal.
    long int jitter
        This value expresses a median filtered average of the PPS signal's dispersion in microseconds.
    int shift
        This value is a binary exponent for the duration of the PPS calibration interval, ranging from PPS_SHIFT to PPS_SHIFTMAX.
    long int stabil
        This value represents the median filtered dispersion of the PPS frequency in scaled PPM.
    long int jitcnt
        This counter represents the number of pulses where the jitter exceeded the allowed maximum MAXTIME.
    long int calcnt
        This counter reflects the number of successful calibration intervals.
    long int errcnt
        This counter represents the number of calibration errors (caused by large offsets or jitter).
    long int stbcnt
        This counter denotes the number of of calibrations where the stability exceeded the threshold. 

— Function: int ntp_adjtime (struct timex *tptr)

    The ntp_adjtime function sets the structure specified by tptr to current values.

    In addition, ntp_adjtime updates some settings to match what you pass to it in *tptr. Use the modes element of *tptr to select what settings to update. You can set offset, freq, maxerror, esterror, status, constant, and tick.

    modes = zero means set nothing.

    Only the superuser can update settings.

    The return value is 0 on success and other values on failure. The following errno error conditions are defined for this function:

    TIME_ERROR
        The high accuracy clock model is not properly set up at the moment, thus the clock must be considered unsynchronized, and the values should be treated with care. Another reason could be that the specified new values are not allowed.
    EPERM
        The process specified a settings update, but is not superuser. 

    For m

