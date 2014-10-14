/*
 *  PreferencesWindowController.mm
 *  MachOView
 *
 *  Created by psaghelyi on 12/24/12.
 *
 */

#import "PreferenceController.h"

@implementation MVPreferenceController

-(id)init
{
    if (![super initWithWindowNibName:@"Preferences"]) {
        return nil;
    }

    NSLog(@"Warning: preferences are not completely implemented yet.\n");
    return self;
}

@end

