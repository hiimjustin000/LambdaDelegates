#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/UploadActionDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaUploadActionDelegate : public cocos2d::CCObject, public UploadActionDelegate {
public:
    std::function<void(int, int)> m_uploadActionFinished;
    std::function<void(int, int)> m_uploadActionFailed;

    void uploadActionFinished(int p0, int p1) override {
        return m_uploadActionFinished(p0, p1);
    }
    void uploadActionFailed(int p0, int p1) override {
        return m_uploadActionFailed(p0, p1);
    }

    static LambdaUploadActionDelegate* create(
        std::function<void(int, int)> const& uploadActionFinished = [](auto, auto) {},
        std::function<void(int, int)> const& uploadActionFailed = [](auto, auto) {}
    ) {
        auto delegate = new LambdaUploadActionDelegate();
        delegate->m_uploadActionFinished = uploadActionFinished;
        delegate->m_uploadActionFailed = uploadActionFailed;
        delegate->autorelease();
        return delegate;
    }
};
