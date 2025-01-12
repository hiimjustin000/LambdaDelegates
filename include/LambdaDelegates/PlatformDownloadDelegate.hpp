#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/PlatformDownloadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaPlatformDownloadDelegate : public cocos2d::CCObject, public PlatformDownloadDelegate {
protected:
    std::function<void(LambdaPlatformDownloadDelegate*, char const*)> m_downloadFinished;
    std::function<void(LambdaPlatformDownloadDelegate*, char const*)> m_downloadFailed;
public:
    void downloadFinished(char const* p0) override {
        if (m_downloadFinished) return m_downloadFinished(this, p0);
    }
    void downloadFailed(char const* p0) override {
        if (m_downloadFailed) return m_downloadFailed(this, p0);
    }

    static LambdaPlatformDownloadDelegate* create(
        std::function<void(LambdaPlatformDownloadDelegate*, char const*)> const& downloadFinished = [](auto*, auto const*) {},
        std::function<void(LambdaPlatformDownloadDelegate*, char const*)> const& downloadFailed = [](auto*, auto const*) {}
    ) {
        auto delegate = new LambdaPlatformDownloadDelegate();
        delegate->m_downloadFinished = downloadFinished;
        delegate->m_downloadFailed = downloadFailed;
        delegate->autorelease();
        return delegate;
    }
};
