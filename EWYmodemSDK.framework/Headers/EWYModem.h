//
//  EWYModem.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/10/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, EWYModemOTAState) {
    EWYModemOTAStateNONE,
    EWYModemOTAStateStart,
    EWYModemOTAStateWriting,
    EWYModemOTAStateEnd,
};

@interface EWYModem : NSObject
@property (nonatomic, copy) void(^progressDidChangeHandler)(NSInteger part, NSInteger totalParts, NSInteger progress, double timeLeft, NSError *error);

/// 单例
+ (instancetype)share;

/// 设置升级文件路径
/// - Parameter filePath: 文件路径
- (void)setupOTAUpgradeFilePath:(NSString *)filePath;

/// 通过读取的数据获得需要写入的数据
/// - Parameter readValue: 写入的数据
- (NSData *)getWriteValueForReadValue:(NSData *)readValue;
@end

NS_ASSUME_NONNULL_END
