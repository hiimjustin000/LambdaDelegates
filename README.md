# Lambda Delegates
A library for creating Geometry Dash delegates with lambda functions.\
**Note: This library is only for use in mods created with the [Geode SDK](https://github.com/geode-sdk/geode).**

## Inclusion
If you have CPM, you can include this library by adding the following to your `CMakeLists.txt`:
```cmake
CPMAddPackage("gh:hiimjustin000/LambdaDelegates#...") # 7-digit commit hash

target_link_libraries(${PROJECT_NAME} LambdaDelegates)
```

## Usage
```cpp
// Include a specific delegate type
#include <LambdaDelegates/TextInputDelegate.hpp>
// Include a specific delegate type
#include <LambdaDelegates/LevelDownloadDelegate.hpp>
// Include the library (Includes all delegate types)
#include <LambdaDelegates.hpp>

// Create a delegate
class AwesomeLayer : public cocos2d::CCLayer {
protected:
    CCTextInputNode* m_textInputNode;
    // It is important to use Refs (or manually manage with retain/release) to prevent automatic deletion
    Ref<LambdaTextInputDelegate> m_textInputDelegate;
    // With these types of delegates, you need to unset it from the manager when you are done with it, so it doesn't get called after the object is deleted
    Ref<LambdaLevelDownloadDelegate> m_levelDownloadDelegate;
public:
    static AwesomeLayer* create() {
        auto ret = new AwesomeLayer();
        if (ret->init()) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }

    bool init() {
        if (!CCLayer::init()) {
            return false;
        }

        // Create a text input node
        m_textInputNode = CCTextInputNode::create(200.0f, 50.0f, "Text...", "bigFont.fnt");
        // Do stuff with m_textInputNode
        m_textInputDelegate = LambdaTextInputDelegate::create([this](LambdaTextInputDelegate* delegate, CCTextInputNode* sender) {
            // Do stuff with text
        }/* Other functions can be added here */);
        m_textInputNode->setDelegate(m_textInputDelegate);

        auto glm = GameLevelManager::sharedState();
        m_levelDownloadDelegate = LambdaLevelDownloadDelegate::create([this](LambdaLevelDownloadDelegate* delegate, GJGameLevel* level) {
            // Do stuff with level
        }, [this](int error) {
            // Do stuff with error
        });
        glm->m_levelDownloadDelegate = m_levelDownloadDelegate;
        glm->downloadLevel(12345678);

        return true;
    }

    ~AwesomeLayer() {
        // Unset the delegate from the manager
        auto glm = GameLevelManager::sharedState();
        if (glm->m_levelDownloadDelegate == m_levelDownloadDelegate) {
            glm->m_levelDownloadDelegate = nullptr;
        }
    }
};
```

For further documentation, view the source files in the `include/LambdaDelegates` directory.

## License
This project is licensed under the [MIT License](./LICENSE).