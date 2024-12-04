#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelDownloadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelDownloadDelegate : public cocos2d::CCObject, public LevelDownloadDelegate {
public:
    std::function<void(GJGameLevel*)> m_levelDownloadFinished;
    std::function<void(int)> m_levelDownloadFailed;

    void levelDownloadFinished(GJGameLevel* p0) override {
        return m_levelDownloadFinished(p0);
    }
    void levelDownloadFailed(int p0) override {
        return m_levelDownloadFailed(p0);
    }

    static LambdaLevelDownloadDelegate* create(
        std::function<void(GJGameLevel*)> const& levelDownloadFinished = [](auto) {},
        std::function<void(int)> const& levelDownloadFailed = [](auto) {}
    ) {
        auto delegate = new LambdaLevelDownloadDelegate();
        delegate->m_levelDownloadFinished = levelDownloadFinished;
        delegate->m_levelDownloadFailed = levelDownloadFailed;
        delegate->autorelease();
        return delegate;
    }
};
