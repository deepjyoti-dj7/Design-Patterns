#include <iostream>

class IButton {
public:
    virtual void press() = 0;
};

class MacButton : public IButton {
public:
    void press() {
        std::cout << "Mac button pressed" << std::endl;
    }
};

class WinButton : public IButton {
public: 
    void press() {
        std::cout << "Win button pressed" << std::endl;
    }
};

class ITextBox {
public:
    virtual void showText() = 0;
};

class MacTextBox : public ITextBox{
public:
    void showText() {
        std::cout << "Showing Mac TextBox" << std::endl;
    }
};

class WinTextBox : public ITextBox {
public:
    void showText() {
        std::cout << "Showing Win TextBox" << std::endl;
    }
};

class IFactory {
public:
    virtual IButton* CreateButton() = 0;
    virtual ITextBox* CreateTextBox() = 0;
};

class MacFactory : public IFactory {
public:
    IButton* CreateButton() {
        return new MacButton();
    }
    ITextBox* CreateTextBox() {
        return new MacTextBox();
    }
};

class WinFactory : public IFactory {
public:
    IButton* CreateButton() {
        return new WinButton();
    }
    ITextBox* CreateTextBox() {
        return new WinTextBox();
    }
};

class GUIAbstractFactory {
public:  
    static IFactory* CreateFactory(std::string osType) {
        if (osType == "windows")
            return new WinFactory();
        else if (osType == "mac")
            return new MacFactory();
        return new MacFactory(); // There should be a default factory
    }
};

int main() {
    std::cout << "Enter your c machine OS" << std::endl;
    std::string osType;
    std::cin >> osType;

    IFactory* fact = GUIAbstractFactory::CreateFactory(osType);

    IButton* button = fact->CreateButton();
    button->press();

    ITextBox* textBox = fact->CreateTextBox();
    textBox->showText();

    return 0;
}