
#ifndef __ELASTOS_SECURITY_CGUARDEDOBJECT_H__
#define __ELASTOS_SECURITY_CGUARDEDOBJECT_H__

#include "_Elastos_Security_CGuardedObject.h"
#include "Elastos.CoreLibrary.IO.h"
#include "Object.h"

using Elastos::IO::IObjectOutputStream;
using Elastos::IO::ISerializable;

namespace Elastos {
namespace Security {

/**
 * {@code GuardedObject} controls access to an object, by checking all requests
 * for the object with a {@code Guard}.
 */
CarClass(CGuardedObject)
    , public Object
    , public IGuardedObject
    , public ISerializable
{
public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    /**
     * Constructs a new instance of {@code GuardedObject} which protects access
     * to the specified {@code Object} using the specified {@code Guard}.
     *
     * @param object
     *            the {@code Object} to protect.
     * @param guard
     *            the {@code Guard} which protects the specified {@code Object},
     *            maybe {@code null}.
     */
    CARAPI constructor(
        /* [in] */ IInterface* object,
        /* [in] */ IGuard* guard);

    /**
     * Returns the guarded {@code Object} if the associated {@code Guard}
     * permits access. If access is not granted, then a {@code
     * SecurityException} is thrown.
     *
     * @return the guarded object.
     * @throws SecurityException
     *                if access is not granted to the guarded object.
     */
    CARAPI GetObject(
        /* [out] */ IInterface** result) /*throws SecurityException*/;

private:
    /**
     * Checks the guard (if there is one) before performing a default
     * serialization.
     */
    CARAPI WriteObject(
        /* [in] */ /*java.io.*/IObjectOutputStream* out) /*throws IOException*/;

private:
    // private static final long serialVersionUID = -5240450096227834308L;

    AutoPtr<IInterface> mObject;

    AutoPtr<IGuard> mGuard;
};

}
}

#endif // __ELASTOS_SECURITY_CGUARDEDOBJECT_H__
