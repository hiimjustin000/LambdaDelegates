#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelCommentDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaLevelCommentDelegate : public cocos2d::CCObject, public LevelCommentDelegate {
public:
    std::function<void(cocos2d::CCArray*, char const*)> m_loadCommentsFinished;
    std::function<void(char const*)> m_loadCommentsFailed;
    std::function<void()> m_updateUserScoreFinished;
    std::function<void(gd::string, char const*)> m_setupPageInfo;

    void loadCommentsFinished(cocos2d::CCArray* p0, char const* p1) override {
        return m_loadCommentsFinished(p0, p1);
    }
    void loadCommentsFailed(char const* p0) override {
        return m_loadCommentsFailed(p0);
    }
    void updateUserScoreFinished() override {
        return m_updateUserScoreFinished();
    }
    void setupPageInfo(gd::string p0, char const* p1) override {
        return m_setupPageInfo(p0, p1);
    }

    static LambdaLevelCommentDelegate* create(
        std::function<void(cocos2d::CCArray*, char const*)> const& loadCommentsFinished = [](auto, auto) {},
        std::function<void(char const*)> const& loadCommentsFailed = [](auto) {},
        std::function<void()> const& updateUserScoreFinished = []() {},
        std::function<void(gd::string, char const*)> const& setupPageInfo = [](auto, auto) {}
    ) {
        auto delegate = new LambdaLevelCommentDelegate();
        delegate->m_loadCommentsFinished = loadCommentsFinished;
        delegate->m_loadCommentsFailed = loadCommentsFailed;
        delegate->m_updateUserScoreFinished = updateUserScoreFinished;
        delegate->m_setupPageInfo = setupPageInfo;
        delegate->autorelease();
        return delegate;
    }
};
