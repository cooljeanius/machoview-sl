/*
 *  AppController.h
 *  MachOView
 *
 *  Created by psaghelyi on 15/06/2010.
 *
 */

#import <Cocoa/Cocoa.h>

@class MVPreferenceController;

@interface MVAppController : NSObject <NSApplicationDelegate,NSOpenSavePanelDelegate>
{
    MVPreferenceController * preferenceController;
}

-(void) printStat;

- (IBAction)showPreferencePanel:(id)sender;

@end




