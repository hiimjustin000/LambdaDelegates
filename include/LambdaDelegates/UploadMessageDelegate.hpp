#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/UploadMessageDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaUploadMessageDelegate : public cocos2d::CCObject, public UploadMessageDelegate {
protected:
    std::function<void(LambdaUploadMessageDelegate*, int)> m_uploadMessageFinished;
    std::function<void(LambdaUploadMessageDelegate*, int)> m_uploadMessageFailed;
public:
    void uploadMessageFinished(int p0) override {
        if (m_uploadMessageFinished) return m_uploadMessageFinished(this, p0);
    }
    void uploadMessageFailed(int p0) override {
        if (m_uploadMessageFailed) return m_uploadMessageFailed(this, p0);
    }

    static LambdaUploadMessageDelegate* create(
        std::function<void(LambdaUploadMessageDelegate*, int)> const& uploadMessageFinished = [](auto*, auto) {},
        std::function<void(LambdaUploadMessageDelegate*, int)> const& uploadMessageFailed = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaUploadMessageDelegate();
        delegate->m_uploadMessageFinished = uploadMessageFinished;
        delegate->m_uploadMessageFailed = uploadMessageFailed;
        delegate->autorelease();
        return delegate;
    }
};
