#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJChallengeDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJChallengeDelegate : public cocos2d::CCObject, public GJChallengeDelegate {
protected:
    std::function<void(LambdaGJChallengeDelegate*)> m_challengeStatusFinished;
    std::function<void(LambdaGJChallengeDelegate*)> m_challengeStatusFailed;
public:
    void challengeStatusFinished() override {
        if (m_challengeStatusFinished) return m_challengeStatusFinished(this);
    }
    void challengeStatusFailed() override {
        if (m_challengeStatusFailed) return m_challengeStatusFailed(this);
    }

    static LambdaGJChallengeDelegate* create(
        std::function<void(LambdaGJChallengeDelegate*)> const& challengeStatusFinished = [](auto*) {},
        std::function<void(LambdaGJChallengeDelegate*)> const& challengeStatusFailed = [](auto*) {}
    ) {
        auto delegate = new LambdaGJChallengeDelegate();
        delegate->m_challengeStatusFinished = challengeStatusFinished;
        delegate->m_challengeStatusFailed = challengeStatusFailed;
        delegate->autorelease();
        return delegate;
    }
};
