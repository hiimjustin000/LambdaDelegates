#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelUploadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelUploadDelegate : public cocos2d::CCObject, public LevelUploadDelegate {
protected:
    std::function<void(LambdaLevelUploadDelegate*, GJGameLevel*)> m_levelUploadFinished;
    std::function<void(LambdaLevelUploadDelegate*, GJGameLevel*)> m_levelUploadFailed;
public:
    void levelUploadFinished(GJGameLevel* p0) override {
        if (m_levelUploadFinished) return m_levelUploadFinished(this, p0);
    }
    void levelUploadFailed(GJGameLevel* p0) override {
        if (m_levelUploadFailed) return m_levelUploadFailed(this, p0);
    }

    static LambdaLevelUploadDelegate* create(
        std::function<void(LambdaLevelUploadDelegate*, GJGameLevel*)> const& levelUploadFinished = [](auto*, auto*) {},
        std::function<void(LambdaLevelUploadDelegate*, GJGameLevel*)> const& levelUploadFailed = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaLevelUploadDelegate();
        delegate->m_levelUploadFinished = levelUploadFinished;
        delegate->m_levelUploadFailed = levelUploadFailed;
        delegate->autorelease();
        return delegate;
    }
};
