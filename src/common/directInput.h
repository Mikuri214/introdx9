#pragma once

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

class DirectInput
{
public:
	DirectInput(DWORD keyboardCoopFlags = DISCL_FOREGROUND|DISCL_NONEXCLUSIVE, DWORD mouseCoopFlags = DISCL_FOREGROUND|DISCL_NONEXCLUSIVE);
	~DirectInput();

	void poll();
	bool keyDown(char key);
	bool mouseButtonDown(int button);
	float mouseDX();
	float mouseDY();
	float mouseDZ();

private:
	DirectInput(const DirectInput &rhs);
	DirectInput& operator=(const DirectInput &rhs);

private:
	IDirectInput8       *mDInput;

	IDirectInputDevice8 *mKeyboard;
	char                 mKeyboardState[256];

	IDirectInputDevice8 *mMouse;
	DIMOUSESTATE2        mMouseState;
};

extern DirectInput *gDInput;
