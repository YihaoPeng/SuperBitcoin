#pragma once

#include "componentid.h"
#include "framework/component.hpp"

using namespace appbase;

class IHttpRpcComponent : public appbase::TComponent<IHttpRpcComponent>
{
public:
    virtual ~IHttpRpcComponent()
    {
    }

    enum
    {
        ID = CID_HTTP_RPC
    };

    virtual int GetID() const override
    {
        return ID;
    }

    virtual bool ComponentInitialize() = 0;

    virtual bool ComponentStartup() = 0;

    virtual bool ComponentShutdown() = 0;

    virtual const char *whoru() const = 0;

    //add other interface methods here ...

};

#define GET_RPC_INTERFACE(ifObj) \
    auto ifObj = appbase::CBase::Instance().FindComponent<IHttpRpcComponent>()
