#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJChallengeDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJChallengeDelegate : public cocos2d::CCObject, public GJChallengeDelegate {
public:
    std::function<void()> m_challengeStatusFinished;
    std::function<void()> m_challengeStatusFailed;

    void challengeStatusFinished() override {
        return m_challengeStatusFinished();
    }
    void challengeStatusFailed() override {
        return m_challengeStatusFailed();
    }

    static LambdaGJChallengeDelegate* create(
        std::function<void()> const& challengeStatusFinished = []() {},
        std::function<void()> const& challengeStatusFailed = []() {}
    ) {
        auto delegate = new LambdaGJChallengeDelegate();
        delegate->m_challengeStatusFinished = challengeStatusFinished;
        delegate->m_challengeStatusFailed = challengeStatusFailed;
        delegate->autorelease();
        return delegate;
    }
};
