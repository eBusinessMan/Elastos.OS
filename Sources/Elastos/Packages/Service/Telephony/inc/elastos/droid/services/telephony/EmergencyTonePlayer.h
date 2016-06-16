#ifndef  __ELASTOS_DROID_SERVICES_TELEPHONY_EMERGENCYTONEPLAYER_H__
#define  __ELASTOS_DROID_SERVICES_TELEPHONY_EMERGENCYTONEPLAYER_H__

#include "_Elastos.Droid.Server.Telephony.h"
#include "elastos/droid/ext/frameworkext.h"

namespace Elastos {
namespace Droid {
namespace Services {
namespace Telephony {

/**
 * Plays an emergency tone when placing emergency calls on CDMA devices.
 */
class EmergencyTonePlayer
    : public Object
{
public:
    TO_STRING_IMPL("EmergencyTonePlayer")

    EmergencyTonePlayer(
        /* [in] */ IContext* context);

    CARAPI Start();

    CARAPI Stop();

private:
    CARAPI_(void) StartVibrate();

    CARAPI_(void) StopVibrate();

    CARAPI_(void) StartAlert();

    CARAPI_(void) StopAlert();

    CARAPI_(Int32) GetToneSetting();


private:
    static const Int32 EMERGENCY_TONE_OFF;
    static const Int32 EMERGENCY_TONE_ALERT;
    static const Int32 EMERGENCY_TONE_VIBRATE;

    static const Int32 ALERT_RELATIVE_VOLUME_PERCENT;

    static const Int32 VIBRATE_LENGTH_MILLIS;
    static const Int32 VIBRATE_PAUSE_MILLIS;
    static AutoPtr<ArrayOf<Int64> > VIBRATE_PATTERN;

    static AutoPtr<IAudioAttributes> VIBRATION_ATTRIBUTES;

    // We don't rely on getSystemService(Context.VIBRATOR_SERVICE) to make sure that this vibrator
    // object will be isolated from others.
    AutoPtr<IVibrator> mVibrator;
    AutoPtr<IContext> mContext;
    AutoPtr<IAudioManager> mAudioManager;

    AutoPtr<IToneGenerator> mToneGenerator;
    Int32 mSavedInCallVolume;
    Boolean mIsVibrating;
};

} // namespace Telephony
} // namespace Services
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SERVICES_TELEPHONY_EMERGENCYTONEPLAYER_H__