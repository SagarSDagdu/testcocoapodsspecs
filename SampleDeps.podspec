Pod::Spec.new do |s|
  s.name           = "SampleDeps"
  s.version        = "9.0.3"
  s.summary        = "Sample Deps"
  s.homepage       = "http://www.cocoapods.org"
  s.license        = 'Apache License, Version 2.0'
  s.author         = { "Anon" => "anon" }
  s.swift_version  = '5.0'
  s.static_framework = true
  s.cocoapods_version = '>= 1.9.0'
  s.platform       = :ios, '11.0'
  s.source         = { :git => "https://github.com/SagarSDagdu/testcocoapodsspecs.git", :tag => "#{s.version}" }
  s.libraries      = "z.1.1.3", "sqlite3", "c++"
  s.requires_arc = true
  s.default_subspec = 'Standard'

  s.subspec 'Standard' do |ss|
    ss.vendored_frameworks = 'ZendriveSDK.xcframework'
    ss.frameworks     = "Accelerate", "SystemConfiguration", "CoreLocation", "CoreMotion", "CoreTelephony"
    ss.dependency "AWSCore", '~>2.23.2'
    ss.dependency "AWSSQS", '~>2.23.2'
    ss.dependency "SQLite.swift", '~>0.12.2'
  end

  s.subspec 'Testing' do |ss|
    ss.dependency 'SampleDeps/Standard'
    ss.ios.vendored_frameworks = 'ZendriveSDKTesting.xcframework'
  end

end
