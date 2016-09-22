
#include "KeyPairGenerator.h"
#include "CSecurity.h"
#include "CSecureRandom.h"
#include "org/apache/harmony/security/fortress/CEngine.h"

using Org::Apache::Harmony::Security::Fortress::CEngine;
using Org::Apache::Harmony::Security::Fortress::ISpiAndProvider;

namespace Elastos {
namespace Security {

KeyPairGeneratorImpl::KeyPairGeneratorImpl()
{}

ECode KeyPairGeneratorImpl::constructor(
    /* [in] */ KeyPairGeneratorSpi* keyPairGeneratorSpi,
    /* [in] */ IProvider* provider,
    /* [in] */ const String& algorithm)
{
    KeyPairGenerator::constructor(algorithm);
    mProvider = provider;
    mSpiImpl = keyPairGeneratorSpi;
    return NOERROR;
}

ECode KeyPairGeneratorImpl::Initialize(
    /* [in] */ Int32 keysize,
    /* [in] */ ISecureRandom* random)
{
    return mSpiImpl->Initialize(keysize, random);
}

ECode KeyPairGeneratorImpl::GenerateKeyPair(
    /* [out] */ IKeyPair** result)
{
    VALIDATE_NOT_NULL(result);
    return mSpiImpl->GenerateKeyPair(result);
}

ECode KeyPairGeneratorImpl::Initialize(
    /* [in] */ IAlgorithmParameterSpec* param,
    /* [in] */ ISecureRandom* random) /*throws InvalidAlgorithmParameterException*/
{
    return mSpiImpl->Initialize(param, random);
}


static AutoPtr<IEngine> InitEngine()
{
    AutoPtr<CEngine> e;
    CEngine::NewByFriend(String("KeyPairGenerator")/*SERVICE*/, (CEngine**)&e);
    return e;
}

static AutoPtr<ISecureRandom> InitSecureRandom()
{
    AutoPtr<CSecureRandom> r;
    CSecureRandom::NewByFriend((CSecureRandom**)&r);
    return r;
}

const String KeyPairGenerator::SERVICE("KeyPairGenerator");
AutoPtr<IEngine> KeyPairGenerator::ENGINE = InitEngine();
AutoPtr<ISecureRandom> KeyPairGenerator::RANDOM = InitSecureRandom();
CAR_INTERFACE_IMPL(KeyPairGenerator, KeyPairGeneratorSpi, IKeyPairGenerator)
KeyPairGenerator::~KeyPairGenerator()
{}

ECode KeyPairGenerator::constructor(
    /* [in] */ const String& algorithm)
{
    mAlgorithm = algorithm;
    return NOERROR;
}

ECode KeyPairGenerator::GetAlgorithm(
    /* [out] */ String* result)
{
    VALIDATE_NOT_NULL(result);
    *result = mAlgorithm;
    return NOERROR;
}

ECode KeyPairGenerator::GetInstance(
    /* [in] */ const String& algorithm,
    /* [out] */ IKeyPairGenerator** outResult) /*throws NoSuchAlgorithmException*/
{
    VALIDATE_NOT_NULL(outResult);
    if (algorithm == NULL) {
        // throw new NullPointerException("algorithm == NULL");
        return E_NULL_POINTER_EXCEPTION;
    }
    AutoPtr<ISpiAndProvider> sap;
    ENGINE->GetInstance(algorithm, NULL, (ISpiAndProvider**)&sap);
    AutoPtr<IInterface> spi;
    sap->GetSpi((IInterface**)&spi);
    AutoPtr<IProvider> provider;
    sap->GetProvider((IProvider**)&provider);
    if (IKeyPairGenerator::Probe(spi)) {
        AutoPtr<IKeyPairGenerator> result = IKeyPairGenerator::Probe(spi);
        ((KeyPairGenerator*)result.Get())->mAlgorithm = algorithm;
        ((KeyPairGenerator*)result.Get())->mProvider = provider;
        *outResult = result;
        REFCOUNT_ADD(*outResult);
        return NOERROR;
    }
    AutoPtr<KeyPairGeneratorImpl> impl = new KeyPairGeneratorImpl();
    impl->constructor((KeyPairGeneratorSpi*)IKeyPairGeneratorSpi::Probe(spi), provider, algorithm);
    *outResult = impl;
    REFCOUNT_ADD(*outResult);
    return NOERROR;
}

ECode KeyPairGenerator::GetInstance(
    /* [in] */ const String& algorithm,
    /* [in] */ const String& provider,
    /* [out] */ IKeyPairGenerator** result) /*throws NoSuchAlgorithmException, NoSuchProviderException*/
{
    VALIDATE_NOT_NULL(result);
    if (provider == NULL || provider.IsEmpty()) {
        // throw new IllegalArgumentException();
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    AutoPtr<ISecurity> security;
    CSecurity::AcquireSingleton((ISecurity**)&security);
    AutoPtr<IProvider> impProvider;
    security->GetProvider(provider, (IProvider**)&impProvider);
    if (impProvider == NULL) {
        // throw new NoSuchProviderException(provider);
        return E_NO_SUCH_PROVIDER_EXCEPTION;
    }
    return GetInstance(algorithm, impProvider, result);
}

ECode KeyPairGenerator::GetInstance(
    /* [in] */ const String& algorithm,
    /* [in] */ IProvider* provider,
    /* [out] */ IKeyPairGenerator** outResult) /*throws NoSuchAlgorithmException*/
{
    VALIDATE_NOT_NULL(outResult);
    if (provider == NULL) {
        // throw new IllegalArgumentException("provider == NULL");
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    if (algorithm == NULL) {
        // throw new NullPointerException("algorithm == NULL");
        return E_NULL_POINTER_EXCEPTION;
    }
    AutoPtr<IInterface> spi;
    ENGINE->GetInstance(algorithm, provider, NULL, (IInterface**)&spi);
    if (IKeyPairGenerator::Probe(spi)) {
        AutoPtr<IKeyPairGenerator> result = IKeyPairGenerator::Probe(spi);
        ((KeyPairGenerator*)result.Get())->mAlgorithm = algorithm;
        ((KeyPairGenerator*)result.Get())->mProvider = provider;
        *outResult = result;
        REFCOUNT_ADD(*outResult);
        return NOERROR;
    }

    AutoPtr<KeyPairGeneratorImpl> impl = new KeyPairGeneratorImpl();
    impl->constructor((KeyPairGeneratorSpi*)IKeyPairGeneratorSpi::Probe(spi), provider, algorithm);
    *outResult = impl;
    REFCOUNT_ADD(*outResult);
    return NOERROR;
}

ECode KeyPairGenerator::GetProvider(
    /* [out] */ IProvider** result)
{
    VALIDATE_NOT_NULL(result);
    *result = mProvider;
    REFCOUNT_ADD(*result);
    return NOERROR;
}

ECode KeyPairGenerator::Initialize(
    /* [in] */ Int32 keysize)
{
    return Initialize(keysize, RANDOM);
}

ECode KeyPairGenerator::Initialize(
    /* [in] */ IAlgorithmParameterSpec* param) /*throws InvalidAlgorithmParameterException*/
{
    return Initialize(param, RANDOM);
}

ECode KeyPairGenerator::GenKeyPair(
    /* [out] */ IKeyPair** result)
{
    VALIDATE_NOT_NULL(result);
    return GenerateKeyPair(result);
}

ECode KeyPairGenerator::GenerateKeyPair(
    /* [out] */ IKeyPair** result)
{
    VALIDATE_NOT_NULL(result);
    *result = NULL;
    return NOERROR;
}

ECode KeyPairGenerator::Initialize(
    /* [in] */ Int32 keysize,
    /* [in] */ ISecureRandom* random)
{
    return NOERROR;
}

ECode KeyPairGenerator::Initialize(
    /* [in] */ IAlgorithmParameterSpec* param,
    /* [in] */ ISecureRandom* random) /*throws InvalidAlgorithmParameterException*/
{
    return NOERROR;
}

} // namespace Security
} // namespace Elastos
