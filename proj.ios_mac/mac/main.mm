#import <Cocoa/Cocoa.h>

#include "steam_api.h"

int main(int argc, char *argv[])
{
    auto ret = true;
#if !defined(COCOS2D_DEBUG) || COCOS2D_DEBUG <= 0
    ret &= SteamAPI_RestartAppIfNecessary(1631760);
#endif
    ret &= SteamAPI_Init();
    if (!ret) {
        return 0;
    }

    return NSApplicationMain(argc, (const char **)argv);
}
