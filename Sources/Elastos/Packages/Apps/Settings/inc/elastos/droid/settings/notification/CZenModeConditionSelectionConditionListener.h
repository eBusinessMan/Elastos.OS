#ifndef __ELASTOS_DROID_SETTINGS_NOTIFICATION_CZENMODECONDITIONSELECTIONCONDITIONLISTENER_H__
#define __ELASTOS_DROID_SETTINGS_NOTIFICATION_CZENMODECONDITIONSELECTIONCONDITIONLISTENER_H__

#include "_Elastos_Droid_Settings_Notification_CZenModeConditionSelectionConditionListener.h"
#include "elastos/droid/settings/notification/CZenModeConditionSelection.h"

namespace Elastos {
namespace Droid {
namespace Settings {
namespace Notification {

CarClass(CZenModeConditionSelectionConditionListener)
    , public CZenModeConditionSelection::ConditionListener
{
public:
    CAR_OBJECT_DECL()
};

} // namespace Notification
} // namespace Settings
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_SETTINGS_NOTIFICATION_CZENMODECONDITIONSELECTIONCONDITIONLISTENER_H__