Pod::Spec.new do |s|
  s.name             = "SampleDepsSwift"
  s.version          = "9.0.3"
  s.summary          = "Sample Deps"
  s.homepage         = "http://www.cocoapods.org"
  s.license          = "Apache License, Version 2.0"
  s.author         = { "Anon" => "anon" }
  s.swift_version  = '5.0'
  s.static_framework = true
  s.cocoapods_version = '>= 1.9.0'
  s.platform         = :ios, '11.0'
  s.source         = { :git => "https://github.com/SagarSDagdu/testcocoapodsspecs.git", :tag => "#{s.version}" }
  s.requires_arc     = true
  s.source_files     = 'Swift/*.swift'
  s.module_name = 'ZendriveSDKSwift'
  s.dependency "SampleDeps"

end
