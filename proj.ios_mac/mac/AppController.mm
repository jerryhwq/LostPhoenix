#import "AppController.h"

@implementation AppController

-(void) dealloc
{
    cocos2d::Director::getInstance()->end();
    [super dealloc];
}

#pragma mark -
#pragma delegates

- (void) applicationDidFinishLaunching:(NSNotification *)aNotification
{
    _app = new AppDelegate();

    [self createWindowAndGLView];
    [self startup];
}

#pragma mark -
#pragma mark functions

- (BOOL) windowShouldClose:(id)sender
{
    return YES;
}

- (void) windowWillClose:(NSNotification *)notification
{
    [[NSRunningApplication currentApplication] terminate];
}

- (BOOL) applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)theApplication
{
    return YES;
}

- (void) createWindowAndGLView
{
    auto rect = cocos2d::Rect(0, 0, 800, 600);
    auto view = cocos2d::GLViewImpl::createWithRect("Lost Phoenix", rect);
    cocos2d::Director::getInstance()->setOpenGLView(view);
}

- (void) startup
{
    [self setupUI];
    cocos2d::Application::getInstance()->run();
    [NSApp terminate:self];
}

- (void) setupUI
{

}

- (BOOL) applicationShouldHandleReopen:(NSApplication *)sender hasVisibleWindows:(BOOL)flag
{
    return NO;
}

@end
