// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#if ENABLE(WEB_AUDIO)
#include "V8AudioNode.h"

#include "bindings/modules/v8/V8AudioContext.h"
#include "bindings/modules/v8/V8AudioNode.h"
#include "bindings/modules/v8/V8AudioParam.h"
#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8HiddenValue.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(AudioNode* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8AudioNode::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::AudioNode* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8AudioNode::wrapperTypeInfo = { gin::kEmbedderBlink, V8AudioNode::domTemplate, V8AudioNode::derefObject, 0, V8AudioNode::toEventTarget, 0, V8AudioNode::installPerContextEnabledMethods, &V8EventTarget::wrapperTypeInfo, WrapperTypeObjectPrototype, WillBeGarbageCollectedObject };

namespace AudioNodeV8Internal {

template <typename T> void V8_USE(T) { }

static void contextAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AudioNode* impl = V8AudioNode::toNative(holder);
    RefPtrWillBeRawPtr<AudioContext> result(impl->context());
    if (result && DOMDataStore::setReturnValueFromWrapper<V8AudioContext>(info.GetReturnValue(), result.get()))
        return;
    v8::Handle<v8::Value> wrapper = toV8(result.get(), holder, info.GetIsolate());
    if (!wrapper.IsEmpty()) {
        V8HiddenValue::setHiddenValue(info.GetIsolate(), holder, v8AtomicString(info.GetIsolate(), "context"), wrapper);
        v8SetReturnValue(info, wrapper);
    }
}

static void contextAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AudioNodeV8Internal::contextAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void numberOfInputsAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AudioNode* impl = V8AudioNode::toNative(holder);
    v8SetReturnValueUnsigned(info, impl->numberOfInputs());
}

static void numberOfInputsAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AudioNodeV8Internal::numberOfInputsAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void numberOfOutputsAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AudioNode* impl = V8AudioNode::toNative(holder);
    v8SetReturnValueUnsigned(info, impl->numberOfOutputs());
}

static void numberOfOutputsAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AudioNodeV8Internal::numberOfOutputsAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void channelCountAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AudioNode* impl = V8AudioNode::toNative(holder);
    v8SetReturnValueUnsigned(info, impl->channelCount());
}

static void channelCountAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AudioNodeV8Internal::channelCountAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void channelCountAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ExceptionState exceptionState(ExceptionState::SetterContext, "channelCount", "AudioNode", holder, info.GetIsolate());
    AudioNode* impl = V8AudioNode::toNative(holder);
    TONATIVE_VOID_EXCEPTIONSTATE(unsigned, cppValue, toUInt32(v8Value, exceptionState), exceptionState);
    impl->setChannelCount(cppValue, exceptionState);
    exceptionState.throwIfNeeded();
}

static void channelCountAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    AudioNodeV8Internal::channelCountAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void channelCountModeAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AudioNode* impl = V8AudioNode::toNative(holder);
    v8SetReturnValueString(info, impl->channelCountMode(), info.GetIsolate());
}

static void channelCountModeAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AudioNodeV8Internal::channelCountModeAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void channelCountModeAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ExceptionState exceptionState(ExceptionState::SetterContext, "channelCountMode", "AudioNode", holder, info.GetIsolate());
    AudioNode* impl = V8AudioNode::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    String string = cppValue;
    if (!(string == "max" || string == "clamped-max" || string == "explicit"))
        return;
    impl->setChannelCountMode(cppValue, exceptionState);
    exceptionState.throwIfNeeded();
}

static void channelCountModeAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    AudioNodeV8Internal::channelCountModeAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void channelInterpretationAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AudioNode* impl = V8AudioNode::toNative(holder);
    v8SetReturnValueString(info, impl->channelInterpretation(), info.GetIsolate());
}

static void channelInterpretationAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AudioNodeV8Internal::channelInterpretationAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void channelInterpretationAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ExceptionState exceptionState(ExceptionState::SetterContext, "channelInterpretation", "AudioNode", holder, info.GetIsolate());
    AudioNode* impl = V8AudioNode::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    String string = cppValue;
    if (!(string == "speakers" || string == "discrete"))
        return;
    impl->setChannelInterpretation(cppValue, exceptionState);
    exceptionState.throwIfNeeded();
}

static void channelInterpretationAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    AudioNodeV8Internal::channelInterpretationAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void connect1Method(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "connect", "AudioNode", info.Holder(), info.GetIsolate());
    AudioNode* impl = V8AudioNode::toNative(info.Holder());
    AudioNode* destination;
    unsigned output;
    unsigned input;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(destination, V8AudioNode::toNativeWithTypeCheck(info.GetIsolate(), info[0]));
        TONATIVE_VOID_EXCEPTIONSTATE_INTERNAL(output, toUInt32(info[1], exceptionState), exceptionState);
        TONATIVE_VOID_EXCEPTIONSTATE_INTERNAL(input, toUInt32(info[2], exceptionState), exceptionState);
    }
    impl->connect(destination, output, input, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void connect2Method(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "connect", "AudioNode", info.Holder(), info.GetIsolate());
    AudioNode* impl = V8AudioNode::toNative(info.Holder());
    AudioParam* destination;
    unsigned output;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(destination, V8AudioParam::toNativeWithTypeCheck(info.GetIsolate(), info[0]));
        TONATIVE_VOID_EXCEPTIONSTATE_INTERNAL(output, toUInt32(info[1], exceptionState), exceptionState);
    }
    impl->connect(destination, output, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void connectMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "connect", "AudioNode", info.Holder(), isolate);
    switch (std::min(3, info.Length())) {
    case 1:
        if (isUndefinedOrNull(info[0])) {
            connect1Method(info);
            return;
        }
        if (V8AudioNode::hasInstance(info[0], isolate)) {
            connect1Method(info);
            return;
        }
        if (V8AudioParam::hasInstance(info[0], isolate)) {
            connect2Method(info);
            return;
        }
        break;
    case 2:
        if (isUndefinedOrNull(info[0])) {
            connect1Method(info);
            return;
        }
        if (V8AudioNode::hasInstance(info[0], isolate)) {
            connect1Method(info);
            return;
        }
        if (V8AudioParam::hasInstance(info[0], isolate)) {
            connect2Method(info);
            return;
        }
        break;
    case 3:
        if (true) {
            connect1Method(info);
            return;
        }
        break;
    default:
        exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
        exceptionState.throwIfNeeded();
        return;
    }
    exceptionState.throwTypeError("No function was found that matched the signature provided.");
    exceptionState.throwIfNeeded();
}

static void connectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    AudioNodeV8Internal::connectMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void disconnectMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "disconnect", "AudioNode", info.Holder(), info.GetIsolate());
    AudioNode* impl = V8AudioNode::toNative(info.Holder());
    unsigned output;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_EXCEPTIONSTATE_INTERNAL(output, toUInt32(info[0], exceptionState), exceptionState);
    }
    impl->disconnect(output, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void disconnectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    AudioNodeV8Internal::disconnectMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace AudioNodeV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8AudioNodeAttributes[] = {
    {"context", AudioNodeV8Internal::contextAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"numberOfInputs", AudioNodeV8Internal::numberOfInputsAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"numberOfOutputs", AudioNodeV8Internal::numberOfOutputsAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"channelCount", AudioNodeV8Internal::channelCountAttributeGetterCallback, AudioNodeV8Internal::channelCountAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"channelCountMode", AudioNodeV8Internal::channelCountModeAttributeGetterCallback, AudioNodeV8Internal::channelCountModeAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"channelInterpretation", AudioNodeV8Internal::channelInterpretationAttributeGetterCallback, AudioNodeV8Internal::channelInterpretationAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static const V8DOMConfiguration::MethodConfiguration V8AudioNodeMethods[] = {
    {"connect", AudioNodeV8Internal::connectMethodCallback, 0, 1},
    {"disconnect", AudioNodeV8Internal::disconnectMethodCallback, 0, 0},
};

static void configureV8AudioNodeTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "AudioNode", V8EventTarget::domTemplate(isolate), V8AudioNode::internalFieldCount,
        V8AudioNodeAttributes, WTF_ARRAY_LENGTH(V8AudioNodeAttributes),
        0, 0,
        V8AudioNodeMethods, WTF_ARRAY_LENGTH(V8AudioNodeMethods),
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8AudioNode::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8AudioNodeTemplate);
}

bool V8AudioNode::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8AudioNode::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

AudioNode* V8AudioNode::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

EventTarget* V8AudioNode::toEventTarget(v8::Handle<v8::Object> object)
{
    return toNative(object);
}

v8::Handle<v8::Object> V8AudioNode::createWrapper(PassRefPtrWillBeRawPtr<AudioNode> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8AudioNode>(impl.get(), isolate));
    if (ScriptWrappable::wrapperCanBeStoredInObject(impl.get())) {
        const WrapperTypeInfo* actualInfo = ScriptWrappable::fromObject(impl.get())->typeInfo();
        // Might be a XXXConstructor::wrapperTypeInfo instead of an XXX::wrapperTypeInfo. These will both have
        // the same object de-ref functions, though, so use that as the basis of the check.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(actualInfo->derefObjectFunction == wrapperTypeInfo.derefObjectFunction);
    }

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &wrapperTypeInfo, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextEnabledProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8AudioNode>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8AudioNode::derefObject(void* object)
{
#if !ENABLE(OILPAN)
    fromInternalPointer(object)->deref();
#endif // !ENABLE(OILPAN)
}

template<>
v8::Handle<v8::Value> toV8NoInline(AudioNode* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore
#endif // ENABLE(WEB_AUDIO)
