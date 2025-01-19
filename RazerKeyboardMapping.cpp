#include "Razer\ChromaAnimationAPI.h"
#include "RazerKeyboardMapping.h"

using namespace ChromaSDK;
using namespace std;

RazerKeyboardMapping* RazerKeyboardMapping::_sInstance = nullptr;

RazerKeyboardMapping::RazerKeyboardMapping()
{

     _sData = std::map<int, int>();

    // Функциональные клавиши
    _sData[VK_ESCAPE] = (int)Keyboard::RZKEY::RZKEY_ESC;
    _sData[VK_F1] = (int)Keyboard::RZKEY::RZKEY_F1;
    _sData[VK_F2] = (int)Keyboard::RZKEY::RZKEY_F2;
    _sData[VK_F3] = (int)Keyboard::RZKEY::RZKEY_F3;
    _sData[VK_F4] = (int)Keyboard::RZKEY::RZKEY_F4;
    _sData[VK_F5] = (int)Keyboard::RZKEY::RZKEY_F5;
    _sData[VK_F6] = (int)Keyboard::RZKEY::RZKEY_F6;
    _sData[VK_F7] = (int)Keyboard::RZKEY::RZKEY_F7;
    _sData[VK_F8] = (int)Keyboard::RZKEY::RZKEY_F8;
    _sData[VK_F9] = (int)Keyboard::RZKEY::RZKEY_F9;
    _sData[VK_F10] = (int)Keyboard::RZKEY::RZKEY_F10;
    _sData[VK_F11] = (int)Keyboard::RZKEY::RZKEY_F11;
    _sData[VK_F12] = (int)Keyboard::RZKEY::RZKEY_F12;

    // Цифровые клавиши (верхний ряд)
    _sData['0'] = (int)Keyboard::RZKEY::RZKEY_0;
    _sData['1'] = (int)Keyboard::RZKEY::RZKEY_1;
    _sData['2'] = (int)Keyboard::RZKEY::RZKEY_2;
    _sData['3'] = (int)Keyboard::RZKEY::RZKEY_3;
    _sData['4'] = (int)Keyboard::RZKEY::RZKEY_4;
    _sData['5'] = (int)Keyboard::RZKEY::RZKEY_5;
    _sData['6'] = (int)Keyboard::RZKEY::RZKEY_6;
    _sData['7'] = (int)Keyboard::RZKEY::RZKEY_7;
    _sData['8'] = (int)Keyboard::RZKEY::RZKEY_8;
    _sData['9'] = (int)Keyboard::RZKEY::RZKEY_9;

    // Буквенные клавиши
    _sData['A'] = (int)Keyboard::RZKEY::RZKEY_A;
    _sData['B'] = (int)Keyboard::RZKEY::RZKEY_B;
    _sData['C'] = (int)Keyboard::RZKEY::RZKEY_C;
    _sData['D'] = (int)Keyboard::RZKEY::RZKEY_D;
    _sData['E'] = (int)Keyboard::RZKEY::RZKEY_E;
    _sData['F'] = (int)Keyboard::RZKEY::RZKEY_F;
    _sData['G'] = (int)Keyboard::RZKEY::RZKEY_G;
    _sData['H'] = (int)Keyboard::RZKEY::RZKEY_H;
    _sData['I'] = (int)Keyboard::RZKEY::RZKEY_I;
    _sData['J'] = (int)Keyboard::RZKEY::RZKEY_J;
    _sData['K'] = (int)Keyboard::RZKEY::RZKEY_K;
    _sData['L'] = (int)Keyboard::RZKEY::RZKEY_L;
    _sData['M'] = (int)Keyboard::RZKEY::RZKEY_M;
    _sData['N'] = (int)Keyboard::RZKEY::RZKEY_N;
    _sData['O'] = (int)Keyboard::RZKEY::RZKEY_O;
    _sData['P'] = (int)Keyboard::RZKEY::RZKEY_P;
    _sData['Q'] = (int)Keyboard::RZKEY::RZKEY_Q;
    _sData['R'] = (int)Keyboard::RZKEY::RZKEY_R;
    _sData['S'] = (int)Keyboard::RZKEY::RZKEY_S;
    _sData['T'] = (int)Keyboard::RZKEY::RZKEY_T;
    _sData['U'] = (int)Keyboard::RZKEY::RZKEY_U;
    _sData['V'] = (int)Keyboard::RZKEY::RZKEY_V;
    _sData['W'] = (int)Keyboard::RZKEY::RZKEY_W;
    _sData['X'] = (int)Keyboard::RZKEY::RZKEY_X;
    _sData['Y'] = (int)Keyboard::RZKEY::RZKEY_Y;
    _sData['Z'] = (int)Keyboard::RZKEY::RZKEY_Z;

    // Управляющие клавиши
    _sData[VK_TAB] = (int)Keyboard::RZKEY::RZKEY_TAB;
    _sData[VK_CAPITAL] = (int)Keyboard::RZKEY::RZKEY_CAPSLOCK;
    //_sData[VK_SHIFT] = (int)Keyboard::RZKEY::RZKEY_LSHIFT;
    //_sData[VK_CONTROL] = (int)Keyboard::RZKEY::RZKEY_LCTRL;
	_sData[VK_LCONTROL] = (int)Keyboard::RZKEY::RZKEY_LCTRL;
	_sData[VK_LWIN] = (int)Keyboard::RZKEY::RZKEY_LWIN;
	_sData[VK_LMENU] = (int)Keyboard::RZKEY::RZKEY_LALT; 
	_sData[VK_RMENU] = (int)Keyboard::RZKEY::RZKEY_RALT;
	//_sData[] = (int)Keyboard::RZKEY::RZKEY_FN; 
	_sData[VK_APPS] = (int)Keyboard::RZKEY::RZKEY_RMENU;
	_sData[VK_RCONTROL] = (int)Keyboard::RZKEY::RZKEY_RCTRL;
	_sData[VK_LSHIFT] = (int)Keyboard::RZKEY::RZKEY_LSHIFT;
	_sData[VK_RSHIFT] = (int)Keyboard::RZKEY::RZKEY_RSHIFT; 
    _sData[VK_MENU] = (int)Keyboard::RZKEY::RZKEY_LALT;
    _sData[VK_SPACE] = (int)Keyboard::RZKEY::RZKEY_SPACE;
    _sData[VK_RETURN] = (int)Keyboard::RZKEY::RZKEY_ENTER;
    _sData[VK_BACK] = (int)Keyboard::RZKEY::RZKEY_BACKSPACE;

    // Стрелки
    _sData[VK_LEFT] = (int)Keyboard::RZKEY::RZKEY_LEFT;
    _sData[VK_RIGHT] = (int)Keyboard::RZKEY::RZKEY_RIGHT;
    _sData[VK_UP] = (int)Keyboard::RZKEY::RZKEY_UP;
    _sData[VK_DOWN] = (int)Keyboard::RZKEY::RZKEY_DOWN;

    // Клавиши на цифровой клавиатуре
    _sData[VK_NUMLOCK] = (int)Keyboard::RZKEY::RZKEY_NUMLOCK;
    _sData[VK_NUMPAD0] = (int)Keyboard::RZKEY::RZKEY_NUMPAD0;
    _sData[VK_NUMPAD1] = (int)Keyboard::RZKEY::RZKEY_NUMPAD1;
    _sData[VK_NUMPAD2] = (int)Keyboard::RZKEY::RZKEY_NUMPAD2;
    _sData[VK_NUMPAD3] = (int)Keyboard::RZKEY::RZKEY_NUMPAD3;
    _sData[VK_NUMPAD4] = (int)Keyboard::RZKEY::RZKEY_NUMPAD4;
    _sData[VK_NUMPAD5] = (int)Keyboard::RZKEY::RZKEY_NUMPAD5;
    _sData[VK_NUMPAD6] = (int)Keyboard::RZKEY::RZKEY_NUMPAD6;
    _sData[VK_NUMPAD7] = (int)Keyboard::RZKEY::RZKEY_NUMPAD7;
    _sData[VK_NUMPAD8] = (int)Keyboard::RZKEY::RZKEY_NUMPAD8;
    _sData[VK_NUMPAD9] = (int)Keyboard::RZKEY::RZKEY_NUMPAD9;
    _sData[VK_DIVIDE] = (int)Keyboard::RZKEY::RZKEY_NUMPAD_DIVIDE;
    _sData[VK_MULTIPLY] = (int)Keyboard::RZKEY::RZKEY_NUMPAD_MULTIPLY;
    _sData[VK_SUBTRACT] = (int)Keyboard::RZKEY::RZKEY_NUMPAD_SUBTRACT;
    _sData[VK_ADD] = (int)Keyboard::RZKEY::RZKEY_NUMPAD_ADD;
    _sData[VK_DECIMAL] = (int)Keyboard::RZKEY::RZKEY_NUMPAD_DECIMAL;
	//_sData[VK_RETURN - Extended] = (int)Keyboard::RZKEY::RZKEY_NUMPAD_ENTER;
	_sData[VK_SNAPSHOT] = (int)Keyboard::RZKEY::RZKEY_PRINTSCREEN;
	_sData[VK_SCROLL] = (int)Keyboard::RZKEY::RZKEY_SCROLL; 
	_sData[VK_PAUSE] = (int)Keyboard::RZKEY::RZKEY_PAUSE;
	_sData[VK_INSERT] =	(int)Keyboard::RZKEY::RZKEY_INSERT;
	_sData[VK_HOME] = (int)Keyboard::RZKEY::RZKEY_HOME;
	_sData[VK_PRIOR] = (int)Keyboard::RZKEY::RZKEY_PAGEUP;
	_sData[VK_DELETE] = (int)Keyboard::RZKEY::RZKEY_DELETE;
	_sData[VK_END] = (int)Keyboard::RZKEY::RZKEY_END;
	_sData[VK_NEXT] = (int)Keyboard::RZKEY::RZKEY_PAGEDOWN;

    // Прочие клавиши (добавьте при необходимости)
	_sData[VK_OEM_3] = (int)Keyboard::RZKEY::RZKEY_OEM_1;
	_sData[VK_OEM_MINUS] = (int)Keyboard::RZKEY::RZKEY_OEM_2;
	_sData[VK_OEM_PLUS] = (int)Keyboard::RZKEY::RZKEY_OEM_3;
	_sData[VK_OEM_4] = (int)Keyboard::RZKEY::RZKEY_OEM_4;
	_sData[VK_OEM_6] = (int)Keyboard::RZKEY::RZKEY_OEM_5; 
	_sData[VK_OEM_5] = (int)Keyboard::RZKEY::RZKEY_OEM_6;
	_sData[VK_OEM_1] = (int)Keyboard::RZKEY::RZKEY_OEM_7;
	_sData[VK_OEM_7] = (int)Keyboard::RZKEY::RZKEY_OEM_8; 
	_sData[VK_OEM_COMMA] = (int)Keyboard::RZKEY::RZKEY_OEM_9;
	_sData[VK_OEM_PERIOD] = (int)Keyboard::RZKEY::RZKEY_OEM_10;
	_sData[VK_OEM_2] = (int)Keyboard::RZKEY::RZKEY_OEM_11;
	//                 = 0x0000;
    //                = (int)Keyboard::RZKEY::RZKEY_MACRO1;
    //                  ...I don't have a big keyboard...
}

int RazerKeyboardMapping::GetRZKEY(int key) 
{
	if (_sData.find(key) != _sData.end())
	{
		int rzkey = _sData[key];
		return rzkey;
	}
	else
	{
		return Keyboard::RZKEY::RZKEY_INVALID;
	}
}

RazerKeyboardMapping* RazerKeyboardMapping::GetInstance()
{
	if (_sInstance == nullptr)
	{
		_sInstance = new RazerKeyboardMapping();
	}
	return _sInstance;
}
