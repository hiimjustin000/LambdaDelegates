#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CommentUploadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCommentUploadDelegate : public cocos2d::CCObject, public CommentUploadDelegate {
protected:
    std::function<void(LambdaCommentUploadDelegate*, int)> m_commentUploadFinished;
    std::function<void(LambdaCommentUploadDelegate*, int, CommentError)> m_commentUploadFailed;
    std::function<void(LambdaCommentUploadDelegate*, int, int)> m_commentDeleteFailed;
public:
    void commentUploadFinished(int p0) override {
        if (m_commentUploadFinished) return m_commentUploadFinished(this, p0);
    }
    void commentUploadFailed(int p0, CommentError p1) override {
        if (m_commentUploadFailed) return m_commentUploadFailed(this, p0, p1);
    }
    void commentDeleteFailed(int p0, int p1) override {
        if (m_commentDeleteFailed) return m_commentDeleteFailed(this, p0, p1);
    }

    static LambdaCommentUploadDelegate* create(
        std::function<void(LambdaCommentUploadDelegate*, int)> const& commentUploadFinished = [](auto*, auto) {},
        std::function<void(LambdaCommentUploadDelegate*, int, CommentError)> const& commentUploadFailed = [](auto*, auto, auto) {},
        std::function<void(LambdaCommentUploadDelegate*, int, int)> const& commentDeleteFailed = [](auto*, auto, auto) {}
    ) {
        auto delegate = new LambdaCommentUploadDelegate();
        delegate->m_commentUploadFinished = commentUploadFinished;
        delegate->m_commentUploadFailed = commentUploadFailed;
        delegate->m_commentDeleteFailed = commentDeleteFailed;
        delegate->autorelease();
        return delegate;
    }
};
