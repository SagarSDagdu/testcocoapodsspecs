//
//  AccidentInfo.swift
//  ZendriveSDKSwift
//
//  Created by Sudeep Kumar on 21/06/19.
//  Copyright © 2019 Zendrive Inc. All rights reserved.
//

import Foundation
import ZendriveSDK

/// Confidence measure of the detected accident.
@objc(ZDAccidentConfidence) public enum AccidentConfidence: Int32 {

    /// Accident was detected with a high confidence. The application might inform
    /// emergency services directly after waiting for some time for user feedback.
    case high

    /// Accident was detected, but with a low confidence. The application might ask
    /// the user for feedback before notifying any emergency services.
    case low

    /// Confidence of an invalidating callback. This might be sent only when the application has opted into
    /// [multiple accident callbacks][multipleCallbackId].
    ///
    /// [multipleCallbackId]: ../Classes/Configuration.html#/c:@M@ZendriveSDKSwift@objc(cs)ZDConfiguration(py)implementsMultipleAccidentCallbacks
    case invalid

    func toObjcAccidentConfidence() -> ZendriveSDK.ZendriveAccidentConfidence {
        return ZendriveSDK.ZendriveAccidentConfidence(rawValue: self.rawValue) ?? ZendriveSDK.ZendriveAccidentConfidence.high
    }

    static func fromObjcAccidentConfidence(_ objcAccidentConfidence: ZendriveSDK.ZendriveAccidentConfidence) -> AccidentConfidence {
        return AccidentConfidence(rawValue: objcAccidentConfidence.rawValue) ?? high
    }
}

/// Collision severity of the detected accident.
@objc(ZDCollisionSeverity) public enum CollisionSeverity: Int32 {

    /// unknown severity collision.
    case unknown

    /// low severity collision
    case low

    /// high severity collision.
    case high

    func toObjcCollisionSeverity() -> ZendriveSDK.ZendriveCollisionSeverity {
        return ZendriveSDK.ZendriveCollisionSeverity(rawValue: self.rawValue) ?? ZendriveSDK.ZendriveCollisionSeverity.unknown
    }

    static func fromObjcCollisionSeverity(_ objcCollisionSeverity: ZendriveSDK.ZendriveCollisionSeverity) -> CollisionSeverity {
        return CollisionSeverity(rawValue: objcCollisionSeverity.rawValue) ?? unknown
    }
}

/// Direction of impact detected by SDK at the time of the accident
@objc(ZDDirectionOfImpact) public enum DirectionOfImpact: Int32 {

    /// Indicates an unknown direction of impact
    case unknown

    /// Indicates a front direction of impact
    case front

    /// Indicates a rear direction of impact
    case rear

    /// Indicates a broadside direction of impact
    case broadside

    func toObjcDirectionOfImpact() -> ZendriveSDK.ZendriveDirectionOfImpact {
        return ZendriveSDK.ZendriveDirectionOfImpact(rawValue: self.rawValue) ?? ZendriveSDK.ZendriveDirectionOfImpact.front
    }

    static func fromObjcDirectionOfImpact(_ objcDirectionOfImpact: ZendriveSDK.ZendriveDirectionOfImpact) -> DirectionOfImpact {
        return DirectionOfImpact(rawValue: objcDirectionOfImpact.rawValue) ?? front
    }
}

/// Wrapper for meta-information related to an accident detected by the SDK.
@objc(ZDAccidentInfo) public class AccidentInfo: NSObject {

    /// The unique Id of drive during which the accident occured
    @objc public var driveId: String {
        return self.internalAccidentInfo.driveId
    }

    /// The location of the accident.
    @objc public var accidentLocation: LocationPoint {
        return LocationPoint.fromObjcLocationPoint(self.internalAccidentInfo.accidentLocation)
    }

    /// The timestamp of the accident in milliseconds since epoch.
    @objc public var timestamp: Int64 {
        return self.internalAccidentInfo.timestamp
    }

    /// The session that was in progress when the accident occured, if a session
    /// was started in the SDK.
    ///
    /// - SeeAlso: `Zendrive.startSession(_:)`
    @objc public var sessionId: String? {
        return self.internalAccidentInfo.sessionId
    }

    /// The tracking id of the ongoing drive when the accident occured.
    ///
    /// - SeeAlso: `Zendrive.startManualDrive(_:completionHandler:)`
    @objc public var trackingId: String? {
        return self.internalAccidentInfo.trackingId
    }

    /// The confidence of detected accident.
    @objc public var confidence: AccidentConfidence {
        return AccidentConfidence.fromObjcAccidentConfidence(self.internalAccidentInfo.confidence)
    }

    /// Measures an approximate precision of the detected collision. Ranges between 0 to 100.
    ///
    /// Note: A confidence number of 0 indicated that it was *not* an accident.
    /// 0 confidence number can be sent as a part of [potential accident callback][potentialId]
    /// to invalidate the previous callback [final accident callback][finalId] for the same accident.
    /// 0 confidence number will never come as a part of potential accident callback.
    ///
    /// Checkout `MockAccidentConfig.invalidateFinalCallback()` to test this scenario during development.
    ///
    /// [potentialId]: ../Protocols/ZendriveDelegate.html#/c:@M@ZendriveSDKSwift@objc(pl)ZendriveDelegate(im)processPotentialAccidentDetected:
    /// [finalId]: ../Protocols/ZendriveDelegate.html#/c:@M@ZendriveSDKSwift@objc(pl)ZendriveDelegate(im)processAccidentDetected:
    @objc public var confidenceNumber: Int32 {
        return self.internalAccidentInfo.confidenceNumber
    }

    /// A unique identifier of this accident.
    @objc public var accidentId: String {
        return self.internalAccidentInfo.accidentId
    }

    /// Vehicle type detected by SDK at the time of the accident.
    /// Default value is `VehicleType.car`.
    @objc public var vehicleType: VehicleType {
        return VehicleType.fromObjcVehicleType(self.internalAccidentInfo.vehicleType)
    }

    /// This field specifies the [collision severity][collisionSeverityId] at the time of [potential accident callback][potentialId] and [final accident callback][finalId].
    ///
    /// Default value is `CollisionSeverity.unknown`.
    ///
    /// [collisionSeverityId]: ../Enums/CollisionSeverity.html
    /// [potentialId]: ../Protocols/ZendriveDelegate.html#/c:@M@ZendriveSDKSwift@objc(pl)ZendriveDelegate(im)processPotentialAccidentDetected:
    /// [finalId]: ../Protocols/ZendriveDelegate.html#/c:@M@ZendriveSDKSwift@objc(pl)ZendriveDelegate(im)processAccidentDetected:
    @objc public var collisionSeverity: CollisionSeverity {
        return CollisionSeverity.fromObjcCollisionSeverity(self.internalAccidentInfo.collisionSeverity)
    }

    /// This field specifies the [direction of impact][directionOfImpactId] at the time of [potential accident callback][potentialId] and [final accident callback][finalId].
    ///
    /// Default value is `DirectionOfImpact.unknown`.
    ///
    /// [directionOfImpactId]: ../Enums/DirectionOfImpact.html
    /// [potentialId]: ../Protocols/ZendriveDelegate.html#/c:@M@ZendriveSDKSwift@objc(pl)ZendriveDelegate(im)processPotentialAccidentDetected:
    /// [finalId]: ../Protocols/ZendriveDelegate.html#/c:@M@ZendriveSDKSwift@objc(pl)ZendriveDelegate(im)processAccidentDetected:
    @objc public var directionOfImpact: DirectionOfImpact {
        return DirectionOfImpact.fromObjcDirectionOfImpact(self.internalAccidentInfo.directionOfImpact)
    }

    internal var internalAccidentInfo: ZendriveSDK.ZendriveAccidentInfo!

    @objc override convenience init() {
        self.init(with: ZendriveSDK.ZendriveAccidentInfo())
    }

    convenience init(with objcAccidentInfo: ZendriveSDK.ZendriveAccidentInfo) {
        self.init(location: LocationPoint.fromObjcLocationPoint(objcAccidentInfo.accidentLocation),
                 timestamp: objcAccidentInfo.timestamp,
                 trackingId: objcAccidentInfo.trackingId,
                 sessionId: objcAccidentInfo.sessionId,
                 confidence: AccidentConfidence.fromObjcAccidentConfidence(objcAccidentInfo.confidence),
                 confidenceNumber: objcAccidentInfo.confidenceNumber,
                 accidentId: objcAccidentInfo.accidentId, driveId: objcAccidentInfo.driveId,
                 vehicleType: VehicleType.fromObjcVehicleType(objcAccidentInfo.vehicleType),
                 collisionSeverity: CollisionSeverity.fromObjcCollisionSeverity(objcAccidentInfo.collisionSeverity),
                 directionOfImpact: DirectionOfImpact.fromObjcDirectionOfImpact(objcAccidentInfo.directionOfImpact))
    }

    /// Initializer for `AccidentInfo`.
    /// - Parameters:
    ///   - location: The location of the accident
    ///   - timestamp: The timestamp of the accident in milliseconds since epoch
    ///   - trackingId: The tracking id of the ongoing drive when the accident occured
    ///   - sessionId: The session that was in progress when the accident
    ///                  occured, if a session was started in the SDK
    ///   - confidence: Confidence measure of the detected accident
    ///   - confidenceNumber: Confidence number of the detected accident
    ///   - accidentId: A unique identifier of this accident
    ///   - driveId: The unique Id of drive during which the accident occured
    ///   - vehicleType: Vehicle type detected by SDK at the time of the accident
    ///   - collisionSeverity: Collision Severity detected by SDK at the time of the accident
    ///   - directionOfImpact: Direction Of Impact detected by SDK at the time of the accident
    /// - Returns: `AccidentInfo` object
    @objc public init(location: LocationPoint, timestamp: Int64, trackingId: String?, sessionId: String?, confidence: AccidentConfidence, confidenceNumber: Int32, accidentId: String, driveId: String, vehicleType: VehicleType, collisionSeverity: CollisionSeverity, directionOfImpact: DirectionOfImpact) {
        self.internalAccidentInfo = ZendriveSDK.ZendriveAccidentInfo(location: location.internalLocationPoint,
                                                                     timestamp: timestamp, trackingId: trackingId,
                                                                     sessionId: sessionId, confidence: confidence.toObjcAccidentConfidence(), confidenceNumber: confidenceNumber, accidentId: accidentId,
                                                                     driveId: driveId,
                                                                     vehicleType: vehicleType.toObjcVehicleType(),
                                                                     collisionSeverity: collisionSeverity.toObjcCollisionSeverity(),
                                                                     directionOfImpact: directionOfImpact.toObjcDirectionOfImpact()
                                                                     )
    }

    /// Returns a dictionary that represents the `AccidentInfo` object.
    @objc public func toDictionary() -> [AnyHashable: Any] {
        return self.internalAccidentInfo.toDictionary()
    }

    /// Returns a JSON formatted string that represents the `AccidentInfo` object.
    @objc public func toJson() -> String {
        return self.internalAccidentInfo.toJson()
    }
}
