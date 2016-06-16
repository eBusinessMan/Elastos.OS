
#ifndef __ELASTOS_APPS_DIALER_CALLLOG_CALLLOGNOTIFICATIONSHELPER_H__
#define __ELASTOS_APPS_DIALER_CALLLOG_CALLLOGNOTIFICATIONSHELPER_H__

namespace Elastos {
namespace Apps {
namespace Dialer {
namespace CallLog {

/**
 * Helper class operating on call log notifications.
 */
class CallLogNotificationsHelper
    : public Object
{
public:
    /** Removes the missed call notifications. */
    static CARAPI_(void) RemoveMissedCallNotifications(
        /* [in] */ IContext* context);

    /** Update the voice mail notifications. */
    static CARAPI_(void) UpdateVoicemailNotifications(
        /* [in] */ IContext* context);

};

} // CallLog
} // Dialer
} // Apps
} // Elastos

#endif //__ELASTOS_APPS_DIALER_CALLLOG_CALLLOGNOTIFICATIONSHELPER_H__
