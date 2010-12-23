#include "CpLinnCoUkMediaTime1.h"
#include <CpProxy.h>
#include <CpiService.h>
#include <Thread.h>
#include <AsyncPrivate.h>
#include <Buffer.h>
#include <Std/CpDevice.h>

#include <string>

using namespace Zapp;


class SyncSecondsLinnCoUkMediaTime1Cpp : public SyncProxyAction
{
public:
    SyncSecondsLinnCoUkMediaTime1Cpp(CpProxyLinnCoUkMediaTime1Cpp& aProxy, uint32_t& aaSeconds);
    virtual void CompleteRequest(IAsync& aAsync);
private:
    CpProxyLinnCoUkMediaTime1Cpp& iService;
    uint32_t& iaSeconds;
};

SyncSecondsLinnCoUkMediaTime1Cpp::SyncSecondsLinnCoUkMediaTime1Cpp(CpProxyLinnCoUkMediaTime1Cpp& aProxy, uint32_t& aaSeconds)
    : iService(aProxy)
    , iaSeconds(aaSeconds)
{
}

void SyncSecondsLinnCoUkMediaTime1Cpp::CompleteRequest(IAsync& aAsync)
{
    iService.EndSeconds(aAsync, iaSeconds);
}


CpProxyLinnCoUkMediaTime1Cpp::CpProxyLinnCoUkMediaTime1Cpp(CpDeviceCpp& aDevice)
    : CpProxy("linn-co-uk", "MediaTime", 1, aDevice.Device())
{
    Zapp::Parameter* param;

    iActionSeconds = new Action("Seconds");
    param = new Zapp::ParameterUint("aSeconds");
    iActionSeconds->AddOutputParameter(param);

    Functor functor;
    functor = MakeFunctor(*this, &CpProxyLinnCoUkMediaTime1Cpp::SecondsPropertyChanged);
    iSeconds = new PropertyUint("Seconds", functor);
    AddProperty(iSeconds);
}

CpProxyLinnCoUkMediaTime1Cpp::~CpProxyLinnCoUkMediaTime1Cpp()
{
    DestroyService();
    delete iActionSeconds;
}

void CpProxyLinnCoUkMediaTime1Cpp::SyncSeconds(uint32_t& aaSeconds)
{
    SyncSecondsLinnCoUkMediaTime1Cpp sync(*this, aaSeconds);
    BeginSeconds(sync.Functor());
    sync.Wait();
}

void CpProxyLinnCoUkMediaTime1Cpp::BeginSeconds(FunctorAsync& aFunctor)
{
    Invocation* invocation = iService->Invocation(*iActionSeconds, aFunctor);
    TUint outIndex = 0;
    const Action::VectorParameters& outParams = iActionSeconds->OutputParameters();
    invocation->AddOutput(new ArgumentUint(*outParams[outIndex++]));
    iInvocable.InvokeAction(*invocation);
}

void CpProxyLinnCoUkMediaTime1Cpp::EndSeconds(IAsync& aAsync, uint32_t& aaSeconds)
{
    ASSERT(((Async&)aAsync).Type() == Async::eInvocation);
    Invocation& invocation = (Invocation&)aAsync;
    ASSERT(invocation.Action().Name() == Brn("Seconds"));

    if (invocation.Error()) {
        THROW(ProxyError);
    }
    TUint index = 0;
    aaSeconds = ((ArgumentUint*)invocation.OutputArguments()[index++])->Value();
}

void CpProxyLinnCoUkMediaTime1Cpp::SetPropertySecondsChanged(Functor& aFunctor)
{
    iLock->Wait();
    iSecondsChanged = aFunctor;
    iLock->Signal();
}

void CpProxyLinnCoUkMediaTime1Cpp::PropertySeconds(uint32_t& aSeconds) const
{
    iPropertyLock->Wait();
    ASSERT(iCpSubscriptionStatus == CpProxy::eSubscribed);
    aSeconds = iSeconds->Value();
    iPropertyLock->Signal();
}

void CpProxyLinnCoUkMediaTime1Cpp::SecondsPropertyChanged()
{
    ReportEvent(iSecondsChanged);
}

