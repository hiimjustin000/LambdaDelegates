#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelDownloadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelDownloadDelegate : public cocos2d::CCObject, public LevelDownloadDelegate {
protected:
    std::function<void(LambdaLevelDownloadDelegate*, GJGameLevel*)> m_levelDownloadFinished;
    std::function<void(LambdaLevelDownloadDelegate*, int)> m_levelDownloadFailed;
public:
    void levelDownloadFinished(GJGameLevel* p0) override {
        if (m_levelDownloadFinished) return m_levelDownloadFinished(this, p0);
    }
    void levelDownloadFailed(int p0) override {
        if (m_levelDownloadFailed) return m_levelDownloadFailed(this, p0);
    }

    static LambdaLevelDownloadDelegate* create(
        std::function<void(LambdaLevelDownloadDelegate*, GJGameLevel*)> const& levelDownloadFinished = [](auto*, auto*) {},
        std::function<void(LambdaLevelDownloadDelegate*, int)> const& levelDownloadFailed = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaLevelDownloadDelegate();
        delegate->m_levelDownloadFinished = levelDownloadFinished;
        delegate->m_levelDownloadFailed = levelDownloadFailed;
        delegate->autorelease();
        return delegate;
    }
};
