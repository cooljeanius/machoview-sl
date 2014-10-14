/*
 *  Document.h
 *  MachOView
 *
 *  Created by psaghelyi on 15/06/2010.
 *
 */

@class MVDataController;

@interface MVOutlineView : NSOutlineView
{
}
@end

@interface MVTableView : NSTableView
{
}
@end

@interface MVRightFormatter : NSFormatter
{
  BOOL        compound;   // NO: plain hex;     YES: groups of bytes (11 22 33 44 55)
  NSUInteger  length;     // size of hex value; number of bytes
  BOOL        alignLeft;  // NO: 12 --> 0012    YES: 12 --> 1200
}
@end


@interface MVDocument : NSDocument
{
  IBOutlet MVOutlineView *        leftView;
  IBOutlet MVTableView *          rightView;
  IBOutlet NSSearchField *        searchField;
  IBOutlet NSTextField *          statusText;
  IBOutlet NSProgressIndicator *  progressIndicator;
  IBOutlet NSSegmentedControl *   offsetModeSwitch;
  IBOutlet NSButton *             stopButton;
  MVDataController *              dataController;
  int32_t                         threadCount;
}
@property (nonatomic,readonly) MVDataController * dataController;

- (IBAction)updateSearchFilter:(id)sender;
- (IBAction)updateAddressingMode:(id)sender;
- (IBAction)stopProcessing:(id)sender;
- (IBAction)rightViewDoubleAction:(id)sender;
- (BOOL)isRVA;

// the first two of these next five are still only partially implemented:
- (void)handleDataTreeWillChange:(NSNotification *)notification;
- (void)handleDataTreeDidChange:(NSNotification *)notification;
- (void)handleDataTreeChanged:(NSNotification *)notification;
- (void)handleDataTableChanged:(NSNotification *)notification;
- (void)handleThreadStateChanged:(NSNotification *)notification;

+ (NSString *)temporaryDirectory;

@end
