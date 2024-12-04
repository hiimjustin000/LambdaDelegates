#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelUploadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelUploadDelegate : public cocos2d::CCObject, public LevelUploadDelegate {
public:
    std::function<void(GJGameLevel*)> m_levelUploadFinished;
    std::function<void(GJGameLevel*)> m_levelUploadFailed;

    void levelUploadFinished(GJGameLevel* p0) override {
        return m_levelUploadFinished(p0);
    }
    void levelUploadFailed(GJGameLevel* p0) override {
        return m_levelUploadFailed(p0);
    }

    static LambdaLevelUploadDelegate* create(
        std::function<void(GJGameLevel*)> const& levelUploadFinished = [](auto) {},
        std::function<void(GJGameLevel*)> const& levelUploadFailed = [](auto) {}
    ) {
        auto delegate = new LambdaLevelUploadDelegate();
        delegate->m_levelUploadFinished = levelUploadFinished;
        delegate->m_levelUploadFailed = levelUploadFailed;
        delegate->autorelease();
        return delegate;
    }
};
