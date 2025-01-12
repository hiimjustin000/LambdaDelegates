#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/UploadActionDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaUploadActionDelegate : public cocos2d::CCObject, public UploadActionDelegate {
protected:
    std::function<void(LambdaUploadActionDelegate*, int, int)> m_uploadActionFinished;
    std::function<void(LambdaUploadActionDelegate*, int, int)> m_uploadActionFailed;
public:
    void uploadActionFinished(int p0, int p1) override {
        if (m_uploadActionFinished) return m_uploadActionFinished(this, p0, p1);
    }
    void uploadActionFailed(int p0, int p1) override {
        if (m_uploadActionFailed) return m_uploadActionFailed(this, p0, p1);
    }

    static LambdaUploadActionDelegate* create(
        std::function<void(LambdaUploadActionDelegate*, int, int)> const& uploadActionFinished = [](auto*, auto, auto) {},
        std::function<void(LambdaUploadActionDelegate*, int, int)> const& uploadActionFailed = [](auto*, auto, auto) {}
    ) {
        auto delegate = new LambdaUploadActionDelegate();
        delegate->m_uploadActionFinished = uploadActionFinished;
        delegate->m_uploadActionFailed = uploadActionFailed;
        delegate->autorelease();
        return delegate;
    }
};
