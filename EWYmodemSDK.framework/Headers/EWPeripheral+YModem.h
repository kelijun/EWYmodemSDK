//
//  EWPeripheral+YModem.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/10/12.
//

#import "EWPeripheral+YModem.h"
#import <EWBluetoothSDK/EWPeripheral.h>

NS_ASSUME_NONNULL_BEGIN


@interface EWPeripheral (YModem)

/// 获取 YModem 升级状态
- (EWYModemUpgradeStatus)getYModemUpgradeStatus;

/// 有些YModem协议要开启条件请在这里加入
/// - Parameter commands: 命令数组
- (void)addYModemCommands:(NSArray <EWCommand *>*)commands;


/// 通过YModem协议进行OTA升级，仅支持.bin文件。如果协议不稳定，起始帧之后不回复ACK，只回复C，forceSendingData 可以设置为Y ES
/// - Parameters:
///   - filePath: OTA文件路径
///   - forceSendingData: 强制发送第一帧数据
///   - writeCharacteristic: 写入特征
///   - readCharacteristic: 读取特征
- (void)startUpdateWithOTAFilePath:(NSString *)filePath
                  forceSendingData:(BOOL)forceSendingData
               writeCharacteristic:(EWCharacteristic *)writeCharacteristic
                readCharacteristic:(EWCharacteristic *)readCharacteristic;
@end

NS_ASSUME_NONNULL_END
