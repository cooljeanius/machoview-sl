/*
 *  ArchiveLayout.h
 *  MachOView
 *
 *  Created by psaghelyi on 18/03/2011.
 *
 */

#import "Layout.h"

@interface MVObjectInfo : NSObject
{
  NSString *    name;
  uint32_t      length;
  MVLayout *    __unsafe_unretained layout;
}

@property (nonatomic,copy)                   NSString *  name;
@property (nonatomic)                   uint32_t    length;
#ifndef NO_OBJC_ARC
@property (nonatomic,unsafe_unretained) MVLayout *  layout;
#else
@property (nonatomic,assign) MVLayout *  layout;
#endif /* !NO_OBJC_ARC */

@end

@interface ArchiveLayout : MVLayout
{
  NSMutableDictionary * objectInfoMap; // <(NSNumber)object offset,MVObjectInfo>
}

+ (ArchiveLayout *)     layoutWithDataController:(MVDataController *)dc rootNode:(MVNode *)node;

@end
