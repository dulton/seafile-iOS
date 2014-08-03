//
//  SeafPreView.h
//  seafilePro
//
//  Created by Wang Wei on 8/3/14.
//  Copyright (c) 2014 Seafile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuickLook/QuickLook.h>

@class SeafBase;

@protocol SeafDentryDelegate <NSObject>
- (void)entry:(SeafBase *)entry updated:(BOOL)updated progress:(int)percent;
- (void)entry:(SeafBase *)entry downloadingFailed:(NSUInteger)errCode;
- (void)entry:(SeafBase *)entry repoPasswordSet:(BOOL)success;
@end

@protocol SeafPreView <QLPreviewItem>
- (UIImage *)image;
- (UIImage *)icon;
- (NSURL *)exportURL;
- (NSString *)mime;
- (NSString *)name;
- (BOOL)editable;
- (long long )filesize;
- (NSString *)strContent;
- (BOOL)saveStrContent:(NSString *)content;
- (BOOL)isDownloading;
- (void)unload;
- (BOOL)hasCache;
- (BOOL)isImageFile;

- (void)load:(id<SeafDentryDelegate>)delegate force:(BOOL)force;
@end
