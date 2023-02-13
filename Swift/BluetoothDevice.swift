//
//  BluetoothDevice.swift
//  ZendriveSDKSwift
//
//  Created by Abhishek Aggarwal on 17/11/20.
//  Copyright © 2020 Zendrive Inc. All rights reserved.
//

import UIKit
import ZendriveSDK

/// Wrapper to describe a bluetooth device.
@objc(ZDBluetoothDevice) public class BluetoothDevice: NSObject {

    /// The name of the bluetooth device.
    @objc public var name: String

    /// The mac address of the bluetooth device.
    @objc public var identifier: String

    override init() {
        name = ""
        identifier = ""
        super.init()
    }

    init(with objcBluetoothDevice: ZendriveBluetoothDevice) {
        name = objcBluetoothDevice.name
        identifier = objcBluetoothDevice.identifier
        super.init()
    }

    func toObjcBluetoothDevice() -> ZendriveBluetoothDevice {
        let objcBluetoothDevice = ZendriveBluetoothDevice()
        objcBluetoothDevice.name = name
        objcBluetoothDevice.identifier = identifier
        return objcBluetoothDevice
    }
}
