#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SliderDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSliderDelegate : public cocos2d::CCObject, public SliderDelegate {
protected:
    std::function<void(LambdaSliderDelegate*, Slider*)> m_sliderBegan;
    std::function<void(LambdaSliderDelegate*, Slider*)> m_sliderEnded;
public:
    void sliderBegan(Slider* p0) override {
        if (m_sliderBegan) return m_sliderBegan(this, p0);
    }
    void sliderEnded(Slider* p0) override {
        if (m_sliderEnded) return m_sliderEnded(this, p0);
    }

    static LambdaSliderDelegate* create(
        std::function<void(LambdaSliderDelegate*, Slider*)> const& sliderBegan = [](auto*, auto*) {},
        std::function<void(LambdaSliderDelegate*, Slider*)> const& sliderEnded = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaSliderDelegate();
        delegate->m_sliderBegan = sliderBegan;
        delegate->m_sliderEnded = sliderEnded;
        delegate->autorelease();
        return delegate;
    }
};
